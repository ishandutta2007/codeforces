#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot,rt; ll k,mina,maxa;
int v[200005],nxt[200005],h[100005],dep[100005],f[100005],siz[100005],son[100005];
bool leaf[100005],vis[100005];
vector<int> vec[100005];
set<pii> pt[100005],s;
vector<pii> ans;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	siz[u]=1;
	int mx=0;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs1(v[p],u);
		siz[u]+=siz[v[p]];
		chkmax(mx,siz[v[p]]);
	}
	if(max(mx,n-siz[u])<=n/2) rt=u;
}

void dfs2(int u,int fa,int t){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		f[v[p]]=u,dep[v[p]]=dep[u]+1;
		dfs2(v[p],u,t<0?v[p]:t);
		siz[u]+=siz[v[p]],son[u]++;
		if(leaf[v[p]]) vec[u].pb(v[p]);
		mina+=siz[v[p]]&1;
		maxa+=siz[v[p]];
	}
	if(son[u]==0) leaf[u]=1;
	if(t>=0&&son[u]>0) pt[t].insert(mp(dep[u],u));
}

void dfs3(int u,int fa,int t){
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs3(v[p],u,t<0?v[p]:t);
	}
	if(t>=0&&!vis[u]) pt[t].insert(mp(u,0));
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dfs1(1,-1);
	dfs2(rt,-1,-1);
	if(k%2!=mina%2||k<mina||k>maxa) return printf("NO\n"),0;
	printf("YES\n");
	for(int p=h[rt];p;p=nxt[p]) s.insert(mp(siz[v[p]],v[p]));
	ll rem=(maxa-k)/2;
	while(rem){
		auto it=--s.end();
		pii tmp=*it;
		s.erase(it);
		if(tmp.fi-2>0) s.insert(mp(tmp.fi-2,tmp.se));
		auto pl=pt[tmp.se].lower_bound(mp(rem,0));
		if(pl==pt[tmp.se].end()) pl--;
		int u=pl->se;
		rem-=dep[u];
		if(vec[u].size()>=2){
			ans.pb(mp(vec[u][vec[u].size()-1],vec[u][vec[u].size()-2]));
			vis[vec[u][vec[u].size()-1]]=vis[vec[u][vec[u].size()-2]]=1;
			vec[u].pop_back(),vec[u].pop_back();
			son[u]-=2;
			if(son[u]==0){
				pt[tmp.se].erase(mp(dep[u],u));
				if(f[u]!=rt) vec[f[u]].pb(u);
			}
		}
		else if(vec[u].size()==1){
			ans.pb(mp(vec[u][0],u));
			vis[vec[u][0]]=vis[u]=1;
			pt[tmp.se].erase(mp(dep[u],u));
			if(f[u]!=rt){
				son[f[u]]--;
				if(son[f[u]]==0){
					pt[tmp.se].erase(mp(dep[f[u]],f[u]));
					if(f[f[u]]!=rt) vec[f[f[u]]].pb(f[u]);
				}
			}
		}
		else{
			assert(rem==0);
			for(int p=h[u];p;p=nxt[p]){
				if(!vis[v[p]]&&v[p]!=f[u]){
					vis[v[p]]=vis[u]=1;
					ans.pb(mp(u,v[p]));
					break;
				}
			}
		}
	}
	for(int p=h[rt];p;p=nxt[p]) pt[v[p]].clear();
	dfs3(rt,-1,-1);
	s.clear();
	for(int p=h[rt];p;p=nxt[p]) if(pt[v[p]].size()) s.insert(mp(pt[v[p]].size(),v[p]));
	while(1){
		if(s.size()==1){
			assert(pt[s.begin()->se].size()==1);
			ans.pb(mp(pt[s.begin()->se].begin()->fi,rt));
			break;
		}
		auto it1=--s.end(),it2=it1; it2--;
		ans.pb(mp(pt[it1->se].begin()->fi,pt[it2->se].begin()->fi));
		pt[it1->se].erase(pt[it1->se].begin());
		pt[it2->se].erase(pt[it2->se].begin());
		if(it1->fi>1) s.insert(mp(it1->fi-1,it1->se));
		if(it2->fi>1) s.insert(mp(it2->fi-1,it2->se));
		s.erase(it1),s.erase(it2);
	}
	for(auto r:ans) printf("%d %d\n",r.fi,r.se);
	return 0;
}
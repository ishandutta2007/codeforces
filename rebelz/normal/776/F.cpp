#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int id;
	vector<int> val;
	bool operator<(const node c)const{
		for(int i=0;i<val.size();i++){
			if(c.val.size()-1<i) return false;
			if(val[i]>c.val[i]) return false;
			else if(val[i]<c.val[i]) return true;
		}
		if(c.val.size()>val.size()) return true;
		return false;
	}
}ts[100005];

int n,m,scnt;
int pl[100005],ans[100005],rnk[100005];
bool fl[100005];
vector<int> adj[100005];

namespace work{
	int rt,tot,nmx,fsize;
	int v[400005],nxt[400005],h[100005],siz[100005];
	bool vis[100005];
	void addedge(int x,int y){
		v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
		v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
	}
	void getroot(int u,int fa){
		int mx=0;
		siz[u]=1;
		for(int p=h[u];p;p=nxt[p]){
			if(v[p]==fa||vis[v[p]]) continue;
			getroot(v[p],u);
			siz[u]+=siz[v[p]];
			chkmax(mx,siz[v[p]]);
		}
		chkmax(mx,fsize-siz[u]);
		if(chkmin(nmx,mx)) rt=u;
	}
	void getsize(int u,int fa){
		siz[u]=1;
		for(int p=h[u];p;p=nxt[p]){
			if(v[p]==fa||vis[v[p]]) continue;
			getsize(v[p],u);
			siz[u]+=siz[v[p]];
		}
	}
	void work(int u,int now){
		ans[rnk[u]]=now;
		getsize(u,-1);
		for(int p=h[u];p;p=nxt[p]){
			if(vis[v[p]]) continue;
			fsize=siz[v[p]],nmx=1<<30;
			getroot(v[p],-1);
			vis[rt]=1;
			work(rt,now+1);
		}
	}
	void getans(){
		nmx=1<<30,fsize=scnt;
		getroot(1,-1);
		vis[rt]=1;
		work(rt,1);
	}
}

int solve(int l,int r){
	if(l==r){
		scnt++;
		ts[scnt].val.push_back(l);
		return scnt;
	}
	vector<pii> t(0);
	t.push_back(mp(l+1,1));
	auto it=lower_bound(adj[l].begin(),adj[l].end(),l);
	while(it!=adj[l].end()&&*it<=r) t.push_back(mp(*it,0)),it++;
	t.push_back(mp(r,1));
	int lst=0,ret=0;
	for(int i=0;i<t.size()-1;i++){
		int x=solve(t[i].fi,t[i+1].fi);
		if(!fl[x]){
			ts[x].val.push_back(l);
			if(!t[i+1].se) fl[x]=1;
			else ret=x;
			if(lst) work::addedge(lst,x);
			lst=x;
		}
	}
	return ret;
}

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		adj[x].push_back(y),adj[y].push_back(x);
	}
	for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());
	solve(1,n);
	for(int i=1;i<=scnt;i++){
		sort(ts[i].val.begin(),ts[i].val.end());
		reverse(ts[i].val.begin(),ts[i].val.end());
	}
	for(int i=1;i<=scnt;i++) ts[i].id=i;
	sort(ts+1,ts+scnt+1);
	for(int i=1;i<=scnt;i++) rnk[ts[i].id]=i;
	work::getans();
	for(int i=1;i<=scnt;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
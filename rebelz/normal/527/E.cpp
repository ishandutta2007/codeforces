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

int n,m,k,tot;
int x[200005],y[200005],du[100005],v[600005],id[600005],nxt[600005],h[100005];
bool vis[300005];
vector<pii> ans;

void addedge(int x,int y,int z){
	v[++tot]=y; id[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; id[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u){
	for(int &p=h[u];p;p=nxt[p]){
		int to=v[p],d=id[p];
		if(vis[d]) continue;
		vis[d]=1;
		dfs(to);
		ans.pb(mp(u,to));
	}
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++){
		du[x[i]=readint()]++,du[y[i]=readint()]++;
		addedge(x[i],y[i],i);
	}
	vector<int> v(0);
	for(int i=1;i<=n;i++) if(du[i]&1) v.pb(i);
	k=m;
	for(int i=0;i<v.size();i+=2){
		if(i==v.size()-1) addedge(v[i],v[i],++k);
		else addedge(v[i],v[i+1],++k);
	}
	if(k&1) addedge(1,1,++k);
	dfs(1);
	printf("%d\n",k);
	for(int i=0;i<ans.size();i++){
		if(i&1) printf("%d %d\n",ans[i].fi,ans[i].se);
		else printf("%d %d\n",ans[i].se,ans[i].fi);
	}
	return 0;
}
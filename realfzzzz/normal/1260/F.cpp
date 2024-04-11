#include<algorithm>
#include<vector>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
    int x=0;
    bool f=0;
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-'){
        f=1;
        c=getchar();
    }
	while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return f?-x:x;
}
const int maxn=1e5+5;
int n,l[maxn],r[maxn];
vector<int> g[maxn];
typedef long long ll;
const ll mod=1e9+7;
ll inv[maxn];
bool vis[maxn];
int size[maxn];
void dfs1(int u,int fa){
	size[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa||vis[v]) continue;
		dfs1(v,u);
		size[u]+=size[v];
	}
}
int cen,res;
void dfs2(int u,int fa,int r){
	int maxs=size[r]-size[u];
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa||vis[v]) continue;
		dfs2(v,u,r);
		maxs=max(maxs,size[v]);
	}
	if(!cen||maxs<res){
		cen=u;
		res=maxs;
	}
}
int dep[maxn];
void dfs3(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa||vis[v]) continue;
		dfs3(v,u);
	}
}
typedef pair<int,int> pii;
void dfs4(int u,int fa,vector<pii>& res){
	res.push_back(pii(l[u],u));
	res.push_back(pii(r[u]+1,-u));
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa||vis[v]) continue;
		dfs4(v,u,res);
	}
}
ll calc(int u){
	vector<pii> res;
	dfs4(u,0,res);
	sort(res.begin(),res.end());
	ll ans=0,s1=0,s2=0;
	for(int i=0;i<res.size()-1;i++){
		int v=res[i].second;
		if(v>0){
			ll g=inv[r[v]-l[v]+1];
			s1=(s1+dep[v]*g%mod)%mod;
			s2=(s2+g)%mod;
		}
		else{
			v=-v;
			ll g=inv[r[v]-l[v]+1];
			s1=(s1+mod-dep[v]*g%mod)%mod;
			s2=(s2+mod-g)%mod;
		}
		ans=(ans+s1*s2%mod*(res[i+1].first-res[i].first)%mod)%mod;
	}
	return ans;
}
ll solve(int u){
	dfs3(u,0);
	ll ans=calc(u);
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]) continue;
		ans=(ans+mod-calc(v))%mod;
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]) continue;
		dfs1(v,0);
		cen=0;
		dfs2(v,0,v);
		ans=(ans+solve(cen))%mod;
	}
	return ans;
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    n=readint();
    for(int i=1;i<=n;i++){
    	l[i]=readint();
    	r[i]=readint();
	}
	for(int i=1;i<n;i++){
		int u,v;
		u=readint();
		v=readint();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	inv[1]=1;
	for(int i=2;i<maxn;i++)
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	dfs1(1,0);
	cen=0;
	dfs2(1,0,1);
	dep[0]=-1;
	ll ans=solve(cen);
	for(int i=1;i<=n;i++) ans=ans*(r[i]-l[i]+1)%mod;
	printf("%d\n",(int)ans);
    return 0;
}
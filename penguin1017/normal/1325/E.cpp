#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=1e6+9;
const ll mod=998244353;
int p[1001];
void getpri(){
	for(int i=2;i<1001;++i){
		if(!p[i])p[++p[0]]=i;
		for(int j=1;j<=p[0]&&p[j]*i<1001;++j){
			p[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
}
vi g[N],d;
queue<int> q;
int deg[N],fa[N];
int main(){
	getpri();
	int n,a;
	scanf("%d",&n);
	int flag=0;
	while(n--){
		scanf("%d",&a);
		d.clear();
		rep(i,1,p[0]+1){
			if(a%p[i]==0){
				int cnt=0;
				while(a%p[i]==0)++cnt,a/=p[i];
				if(cnt&1)d.pb(p[i]);
			}
		}
		if(a>1)d.pb(a);
		if(d.size()==0)flag=1;
		else if(d.size()==1){
			g[1].pb(d[0]);
			g[d[0]].pb(1);
		}
		else {
			g[d[0]].pb(d[1]);
			g[d[1]].pb(d[0]);
		}
	}
	if(flag){
		cout<<1;
		return 0; 
	}
	rep(i,1,1001){
		sort(all(g[i]));
		if(unique(all(g[i]))!=g[i].end()){
			cout<<2;
			return 0;
		}
	}
	//cout<<"OK\n";
	int ans=N;
	rep(i,1,1001){
		while(q.size())q.pop();
		if(!g[i].size())continue;
		memset(deg,0,sizeof deg);
		memset(fa,0,sizeof fa);
		q.push(i);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:g[u]){
				if(v==fa[u])continue;
				//cout<<deg[u]<<' '<<deg[v]<<' '<<u<<' '<<v<<"check\n";
				if(deg[v])ans=min(ans,deg[u]+deg[v]+1);
				else deg[v]=deg[u]+1,fa[v]=u,q.push(v);
			}
		}
	}
	if(ans==N)cout<<-1;
	else cout<<ans;
}
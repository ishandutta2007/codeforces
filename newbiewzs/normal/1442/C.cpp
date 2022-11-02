#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define int long long
typedef long long ll;
using namespace std;
int read(){
	char c=getchar();int x=1;int s=0;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
const int N=4e5+5;
const int mod=998244353;
int n,m,x,y;
vector<pii>v[N],g[N];
struct node{
	int id,cs,val;
	friend bool operator < (node x,node y){
		return x.val>y.val;
	}
};
priority_queue<node>q;
int pd[N][19],dis[N][19],f[N];
void solve(){
	memset(dis,10,sizeof(dis));
	dis[1][0]=0;q.push((node){1,0,0});
	while(q.size()){
		node u=q.top();
		q.pop();
		if(pd[u.id][u.cs])continue;
		if(u.cs==18)continue;
		pd[u.id][u.cs]=1;
		for(auto i:v[u.id]){
			if(i.se==1e9+1){
				if(dis[i.fi][u.cs+1]>dis[u.id][u.cs]+(1<<u.cs)+1){
					dis[i.fi][u.cs+1]=dis[u.id][u.cs]+(1<<u.cs)+1;
					q.push((node){i.fi,u.cs+1,dis[i.fi][u.cs+1]});
				}
			}
			else{
				if(dis[i.fi][u.cs]>dis[u.id][u.cs]+i.se){
					dis[i.fi][u.cs]=dis[u.id][u.cs]+i.se;
					q.push((node){i.fi,u.cs,dis[i.fi][u.cs]});
				}
			}
		}
	}
}
bool vis[N];
void work(){
	for(int i=1;i<=2*n;i++){
		q.push((node){i,0,f[i]});
	}
	while(q.size()){
		node u=q.top();
		q.pop();
		if(vis[u.id])continue;
		vis[u.id]=1;
		for(auto i:v[u.id]){
			if(f[i.fi]>f[u.id]+i.se){
				f[i.fi]=f[u.id]+i.se;
				q.push((node){i.fi,0,f[i.fi]});
			}
		}
	}
}
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	for(int i=1;i<=m;i++){
		x=read();y=read();
	/*	v[x].pb(mp(y,1));
		v[y].pb(mp(x,1e9));*/
	/*	g[x].pb(mp(y,1));
		g[y*2].pb(mp(x*2,1));
		g[y].pb(mp(x*2,1e9));
		g[x*2].pb(mp(y,1e9));*/
		
		v[x].pb(mp(y,1));
		v[y+n].pb(mp(x+n,1));
		v[y].pb(mp(x+n,1e9+1));
		v[x+n].pb(mp(y,1e9+1));
	}
	solve();
	memset(f,10,sizeof(f));
	for(int i=1;i<=2*n;i++){
		for(int k=0;k<=18;k++){
			f[i]=min(f[i],dis[i][k]);
		}
	}
	work();
	int tmp=min(f[n],f[2*n]);
	int fm=tmp/1e9;
	int ew=0;
	for(int i=1;i<=fm;i++)ew=(ew+ksm(2,17+i))%mod;
	tmp=tmp%(ll)(1e9);
	tmp=(tmp+ew)%mod;
	cout<<tmp;
	return 0;
}
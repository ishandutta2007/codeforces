//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
namespace MCMF{
	const int N=3000,M=2000000;
	int head[N],cnt,dis[N],fr[N],id[N],S,T,cost;
	struct node{
		int to,next,val,cost;
	}edge[M];
	void ae(int u,int v,int w,int c){
		edge[cnt].cost=c,edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		edge[cnt].cost=-c,edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	bool in[N];
	bool SPFA(){
		memset(dis,0x3f,sizeof(dis)),dis[S]=0,q.push(S),in[S]=true;
		while(!q.empty()){
			int x=q.front();q.pop(),in[x]=false;
			for(int i=head[x];i!=-1;i=edge[i].next){
				if(!edge[i].val)continue;
				if(dis[edge[i].to]>dis[x]+edge[i].cost){
					dis[edge[i].to]=dis[x]+edge[i].cost,fr[edge[i].to]=x,id[edge[i].to]=i;
					if(!in[edge[i].to])in[edge[i].to]=true,q.push(edge[i].to);
				}
			}
		}
		if(dis[T]==dis[0])return false;
		int x=T,mn=0x3f3f3f3f;
		while(x!=S)mn=min(mn,edge[id[x]].val),x=fr[x];
		cost+=dis[T]*mn,x=T;
		while(x!=S)edge[id[x]].val-=mn,edge[id[x]^1].val+=mn,x=fr[x];
		return true;
	}
}
using namespace MCMF;
int a[(1<<10)+5],t[(1<<10)+5],nex[(1<<10)+5];
bool vis[(1<<10)+5];
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n,m;
	FILL(head,-1);
	cin>>n>>m;S=m+m+1,T=m+m+2;
	FOR(i,1,m){
		FOR(j,1,n){
			char c;
			cin>>c;
			if(c=='1'){
				t[i]++;
				a[i]+=(1<<(j-1));
			}
		}
		ae(S,i,1,t[i]);
		ae(i,T,1,1);
		ae(i+m,T,1,0);
	} 
	FOR(i,1,m){
		FOR(j,1,m){
			if(i!=j&&(a[i]&a[j])==a[j]){
				ae(j,i+m,1,-t[j]);
			}
		}
	}
	while(SPFA());
	FOR(i,1,m){
		for(int j=head[i];j!=-1;j=edge[j].next){
			if(edge[j].val==0&&(a[edge[j].to-m]&a[i])==a[i]){
				nex[i]=edge[j].to-m;vis[edge[j].to-m]=1;
			}
		}
	}
	V<int> ans;
	FOR(i,1,m)if(!vis[i]){
		int now=i,lst=0;
		while(now){
			rep(j,0,n){
				if((a[now]^lst)&(1<<j)){
					ans.PB(j);
				}
			}
			lst=a[now];
			now=nex[now];
		}
		ans.PB(-1);
	}
	ans.pop_back();
	cout<<ans.size()<<'\n';
	for(auto u:ans){
		if(u==-1){
			cout<<'R'<<' ';
		}else cout<<u<<' ';
	}
	RE 0;
}
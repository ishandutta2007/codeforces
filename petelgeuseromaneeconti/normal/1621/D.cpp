#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
using LL=long long;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int n;
LL c[505][505];
LL dis[505][505];
bool vis[505][505];
int f(int x){
	if(x>=n*2)x-=n*2;
	if(x<=0)x+=n*2;
	return x;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		LL base=0;
		rep(i,1,n*2){
			rep(j,1,n*2){
				scanf("%lld",&c[i][j]);
				if(i>n&&j>n)base+=c[i][j],c[i][j]=0;
				if(i<=n&&j<=n)c[i][j]=INFLL;
				if(i>n&&j>n)c[i][j]=INFLL;
			}
		}
		c[n+1][n+1]=c[n+1][n*2]=c[n*2][n+1]=c[n*2][n*2]=0;
		LL ans=INFLL;
		rep(o,0,3){
			int sx,sy;
			if(o&1){
				sx=1;
			}else{
				sx=n;
			}
			if(o&2){
				sy=1;
			}else{
				sy=n;
			}
			rep(i,1,n*2)rep(j,1,n*2){
				dis[i][j]=INFLL;
				vis[i][j]=0;
			}
			priority_queue<tuple<LL,int,int> >pq;
			dis[sx][sy]=0,pq.emplace(0,sx,sy);
			while(!pq.empty()){
				int x,y;
				tie(ignore,x,y)=pq.top();
				pq.pop();
				if(vis[x][y])continue;
				vis[x][y]=1;
				rep(i,0,3){
					int xx=f(x+dx[i]),yy=f(y+dy[i]);
					if(dis[x][y]+c[xx][yy]<dis[xx][yy]){
						dis[xx][yy]=dis[x][y]+c[xx][yy];
						pq.emplace(-dis[xx][yy],xx,yy);
					}
				}
			}
			ans=min({ans,dis[n+1][n+1],dis[n+1][n*2],dis[n*2][n+1],dis[n*2][n*2]});
		}
		printf("%lld\n",ans+base);
	}
	return 0;
}
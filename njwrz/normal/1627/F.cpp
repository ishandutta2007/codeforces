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
#define y1 yyyy1111
using namespace std;
int n,m,d1[505][505],d2[505][505],dis[505][505];
void solve(){
	cin>>n>>m;
	FOR(i,0,m){
		FOR(j,0,m){
			dis[i][j]=-1e9;
			d1[i][j]=d2[i][j]=0;
		}
	}
	FOR(i,1,n){
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2){
			if(y1>y2)swap(y1,y2);
			d1[x1][y1]++;
			d1[m-x1+1][m-y1]++;
		}else {
			if(x1>x2)swap(x2,x1);
			d2[x1][y1]++;
			d2[m-x1][m-y1+1]++;
		}
	}
	priority_queue<P<int,P<int,int> > > q;
	q.emplace(MP(0,MP(0,0)));
	dis[0][0]=0;
	while(!q.empty()){
		P<int,P<int,int> > now=q.top();
		int d=now.F;
		int x=now.S.F,y=now.S.S;
		q.pop();
		if(dis[x][y]!=d)continue;
		if(x>0&&dis[x-1][y]<d-d1[x][y]){
			dis[x-1][y]=d-d1[x][y];
			q.emplace(MP(dis[x-1][y],MP(x-1,y)));
		}
		if(y>0&&dis[x][y-1]<d-d2[x][y]){
			dis[x][y-1]=d-d2[x][y];
			q.emplace(MP(dis[x][y-1],MP(x,y-1)));
		}
		if(x<m&&dis[x+1][y]<d-d1[x+1][y]){
			dis[x+1][y]=d-d1[x+1][y];
			q.emplace(MP(dis[x+1][y],MP(x+1,y)));
		}
		if(y<m&&dis[x][y+1]<d-d2[x][y+1]){
			dis[x][y+1]=d-d2[x][y+1];
			q.emplace(MP(dis[x][y+1],MP(x,y+1)));
		}
	}
	cout<<n+dis[m/2][m/2]<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}
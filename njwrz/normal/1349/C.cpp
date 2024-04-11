#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
using namespace std;
int n,m,k;
int a[1005][1005],d[1005][1005];
int fx[4][2]={
0,-1,
0,1,
-1,0,
1,0
};
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int qus;
	cin>>n>>m>>qus;
	char c;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>c;
			if(c=='1')a[i][j]=1;
		}
	}
	queue<P<int,int>> q;
	FILL(d,-1);
	int tx,ty;
	FOR(i,1,n){
		FOR(j,1,m){
			bool f=1;
			rep(k,0,4){
				tx=i+fx[k][0];ty=j+fx[k][1];
				if(tx>=1&&tx<=n&&ty>=1&&ty<=m){
					if(a[tx][ty]==a[i][j]){
						f=0;break;
					}
				}
			}
			if(!f){
				d[i][j]=0;
				q.emplace(i,j);
			}
		}
	}
	P<int,int> cur;
	while(!q.empty()){
		cur=q.front();q.pop();
		int x=cur.F,y=cur.S,tx,ty;
		rep(i,0,4){
			tx=x+fx[i][0];ty=y+fx[i][1];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m){
				if(d[tx][ty]==-1){
					d[tx][ty]=d[x][y]+1;
					q.emplace(tx,ty);
				}
			}
		}
	}
	int x,y,p;
	FOR(i,1,qus){
		cin>>x>>y>>p;
		p--;
		if(p<d[x][y]||d[x][y]==-1){
			cout<<a[x][y]<<'\n';
		}else{
			cout<<(1^a[x][y]^((p-d[x][y])&1))<<'\n';
		}
	}
	RE 0;
}
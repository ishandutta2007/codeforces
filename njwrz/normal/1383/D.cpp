/*

DP





ll int
 dp 










*/
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
using namespace std;
int a[255][255],n,m,cnt,ans[255][255]; 
P<int,int> p[255*255],used[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>a[i][j];
		}
	}
	FOR(i,1,n){
		int maxi=0;
		FOR(j,1,m)gmax(maxi,a[i][j]);
		p[maxi].F=1;
	}
	FOR(i,1,m){
		int maxi=0;
		FOR(j,1,n)gmax(maxi,a[j][i]);
		p[maxi].S=1;
	}
	int h=0,w=0,l=0;
	for(int i=n*m;i>=1;i--){
		bool ff=0;
		if(p[i].F&&!p[i].S){
			h++;ff=1;ans[h][w]=i;
			for(int j=w-1;j>=1;j--){
				used[++cnt]=MP(h,j);
			}
		}
		if(p[i].S&&!p[i].F){
			w++;ff=1;ans[h][w]=i;
			for(int j=h-1;j>=1;j--){
				used[++cnt]=MP(j,w);
			}
		}
		if(p[i].F&&p[i].S){
			w++;h++;ff=1;ans[h][w]=i;
			for(int j=h-1;j>=1;j--){
				used[++cnt]=MP(j,w);
			}
			for(int j=w-1;j>=1;j--){
				used[++cnt]=MP(h,j);
			}
		}
		if(!ff){
			++l;
			ans[used[l].F][used[l].S]=i;
		}
	}
	FOR(i,1,n){
		FOR(j,1,m)cout<<ans[i][j]<<' ';
		cout<<'\n';
	}
	RE 0;
}
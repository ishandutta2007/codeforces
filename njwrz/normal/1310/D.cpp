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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int d[85][15],n,k,a[85][85],s[85],maxi=2147483647; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n){
		FOR(j,1,n)cin>>a[i][j];
	}
	srand(time(0));
	int ans=maxi;
	FOR(t,1,10000){
	FOR(i,1,n)s[i]=rand()&1;
	FOR(i,0,k)FOR(j,0,n)d[j][i]=maxi;
	d[1][0]=0;
	FOR(i,1,k){
		FOR(x,1,n){
			if(d[x][i-1]==maxi)continue;
			FOR(y,1,n){
				if(s[x]^s[y])gmin(d[y][i],d[x][i-1]+a[x][y]);
			}
		}
	}
	gmin(ans,d[1][k]);
	}
	cout<<ans;
	RE 0;
}
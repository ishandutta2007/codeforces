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
int to[100005][345],a[100005],B=340;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	for(int i=n;i>=1;i--){
		FOR(j,1,B){
			int New=i+a[i]+j;
			if(New>n){
				to[i][j]=1;
			}else to[i][j]=to[New][j]+1;
		}
	}
	int q;
	cin>>q;
	FOR(i,1,q){
		int x,y;
		cin>>x>>y;
		if(y>B){
			int cnt=0;
			while(x<=n){
				x=x+a[x]+y;cnt++;
			}
			cout<<cnt<<'\n';
		}else{
			cout<<to[x][y]<<'\n';
		}
	}
	RE 0;
}
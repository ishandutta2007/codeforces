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
int n;
int a[105],ans[55];
void solve(){
	cin>>n;
	FOR(i,1,2*n-1){
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	while(1){
		FOR(i,1,n)ans[i]=rand()&1;
		bool f=1;
		FOR(i,1,n){
			bool ff=0;
			FOR(j,i,i+n-1){
				if(ans[j-i+1]==a[j]){
					ff=1;break;
				}
			}
			if(!ff){
				f=0;break;
			}
		}
		if(f){
			FOR(i,1,n)cout<<ans[i];
			cout<<'\n';RE ;
		} 
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}
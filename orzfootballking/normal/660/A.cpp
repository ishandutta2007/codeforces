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
int a[1005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; 
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
	}
	V<int> ans;
	ans.PB(a[1]);
	FOR(i,2,n){
		if(__gcd(a[i],a[i-1])>1){
			ans.PB(1);
		}
		ans.PB(a[i]);
	}
	cout<<ans.size()-n<<'\n';
	for(auto u:ans)cout<<u<<' ';
	RE 0;
}
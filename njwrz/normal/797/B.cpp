/*

DP





ll int
 dp 










*/
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
V<int> v;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,sum=0;
	cin>>n;
	FOR(i,1,n){
		int x;
		cin>>x;
		if(x%2==0){
			if(x>0)sum+=x;
		}else{
			v.PB(x);
		}
	}
	sort(ALL(v),greater<int>());
	int cnt=0,tot=sum;sum=0;int ans=-1e18;
	for(auto u:v){
		cnt++;
		sum+=u;
		if(cnt&1)gmax(ans,tot+sum);
	}
	cout<<ans;
	RE 0;
}
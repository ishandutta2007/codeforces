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
void solve(){
	int n;
	cin>>n;
	int mid=n/2+1;
	int sum=0;
	FOR(i,mid,n-1){
		sum+=(i-1)*(i-1);
	}
	FOR(i,2,mid-1){
		sum+=(n-i)*(n-i);
	}
	sum+=(n-1)*(n-1);
	cout<<sum<<'\n';
	cout<<mid<<' ';
	FOR(i,1,mid-2)cout<<i<<' ';
	FOR(i,mid+1,n)cout<<i<<' ';
	cout<<mid-1<<'\n';
	cout<<n-1<<'\n';
	FOR(i,mid,n-1){
		cout<<i<<' '<<1<<'\n';
	}
	for(int i=mid-1;i>=2;i--){
		cout<<i<<' '<<n<<'\n';
	}
	cout<<1<<' '<<n<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}
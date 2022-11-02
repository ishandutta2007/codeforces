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
int n,k;
int a[200005],qz[200005],hz[200005];
map<int,int> m; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i],m[a[i]]++;
	sort(a+1,a+n+1);
	FOR(i,1,n)qz[i]=qz[i-1]+a[i];
	for(int i=n;i>=1;i--)hz[i]=hz[i+1]+a[i];
	int ans=1e17;
	for(auto u:m){
		if(u.S>=k){
			cout<<0;RE 0;
		}
	}
	FOR(i,1,n){
		gmin(ans,a[i]*i-qz[i]+hz[i]-(n-i+1)*a[i]-(n-k));
		if(i>=k)gmin(ans,a[i]*i-qz[i]-(i-k));
		if(n-i+1>=k)gmin(ans,hz[i]-(n-i+1)*a[i]-(n-i+1-k));
	}
	cout<<ans;
	RE 0;
}
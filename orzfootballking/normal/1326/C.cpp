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
int mod=998244353,a[200005],f[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n){
		cin>>a[i];
		f[a[i]]=i;
	}
	int sum=0;
	FOR(i,n-m+1,n)sum+=i;
	cout<<sum<<' ';
	V<int> v;
	FOR(i,1,n){
		if(a[i]>n-m)v.PB(i);
	}
	int ans=1;
	for(int i=0;i<v.size()-1;i++){
		ans=ans*(v[i+1]-v[i])%mod;
	}
	cout<<ans;
	RE 0;
}
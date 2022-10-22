#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
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
int mod=1e9+7,n,m,f[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	f[0]=f[1]=1;
	FOR(i,2,max(n,m))f[i]=(f[i-1]+f[i-2])%mod;
	cout<<(f[n]+f[m]-1)*2%mod;
	RE 0;
}
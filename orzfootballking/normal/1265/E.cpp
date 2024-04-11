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
int inv[105],x,mod=998244353;
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin>>n;
	inv[1]=1;
	FOR(i,2,100)inv[i]=mod-inv[mod%i]*(mod/i)%mod;
	int ans=0;
	FOR(i,1,n){
		cin>>x;
		ans=(ans+1)*100%mod*inv[x]%mod;
	}
	cout<<ans;
	RE 0;
}
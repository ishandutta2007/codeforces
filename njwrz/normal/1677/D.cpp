#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
using namespace __gnu_pbds;
int n,a[1000005],b[1000005],c[1000005],mod=998244353,k;
void solve(){
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i],b[i]=0,c[i]=0;
	int ans=1;
	FOR(i,1,k)ans=ans*i%mod;
	FOR(i,1,n){
		if(i+k>n){
			if(a[i]==-1){
				
			}else if(a[i]){
				cout<<0<<'\n';RE;
			}
		}else{
			if(a[i]==-1){
				ans=ans*(i+k)%mod;
			}else{
				if(a[i]==0)ans=ans*(k+1)%mod;
				if(a[i]>=i){
					cout<<0<<'\n';RE ;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}
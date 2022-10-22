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
int q(int x){
	cout<<"? "<<x<<'\n';cout.flush();
	int val;
	cin>>val;
	RE val;
}
signed main(){
	int n;
	cin>>n;
	int l=n,r=10000000,mx=0,mid;
	while(r>=l){
		mid=(l+r)>>1;
		int t=q(mid);
		if(t!=1){
			l=mid+1;
		}else r=mid-1,mx=mid;
	}
	int ans=mx;
	FOR(i,2,n){
		int t=q(mx/i);
		if(t!=0){
			gmin(ans,t*(mx/i));
		}
	}
	cout<<"! "<<ans<<'\n';cout.flush();
	RE 0;
}
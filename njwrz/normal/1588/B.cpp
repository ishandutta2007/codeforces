#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n;
int ask(int l,int r){
	cout<<"? "<<l<<' '<<r<<'\n';
	fflush(stdout);
	int t;
	cin>>t;
	RE t;
}
void solve(){
	cin>>n;
	int t=ask(1,n);
	int l=2,r=n,mid,ans=-1;
	while(r>=l){
		mid=(l+r)>>1;
		if(ask(1,mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	int tt=ask(ans,n);
	int i=ans-1;
	int j=(t-tt)+i;
	int res=t-(j-i+1)*(j-i)/2;res*=2;
	int tp=sqrt(res)+1;
	int k=j+tp;
	j++;
	cout<<"! "<<i<<' '<<j<<' '<<k<<'\n';
	fflush(stdout);
}
signed main(){
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}
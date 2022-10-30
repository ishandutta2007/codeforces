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
int n,a[200005];
int cnt[200005],sum[200005];
void solve(){
	cin>>n;
	V<int> v;
	FOR(i,1,n)cin>>a[i],v.PB(a[i]);
	sort(ALL(v));v.erase(unique(ALL(v)),v.end());
	FOR(i,1,n)cnt[i]=0;
	FOR(i,1,n)cnt[lwb(ALL(v),a[i])-v.begin()+1]++;
	FOR(i,1,n)gmin(cnt[i],2ll);
	sum[n+1]=0;
	for(int i=n;i>=1;i--)sum[i]=sum[i+1]+cnt[i];
	int s=0,ans=0;
	FOR(i,1,n){
		if(cnt[i]){
			gmax(ans,1+(s+sum[i+1])/2);
		}
		s+=cnt[i];
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
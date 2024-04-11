#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(ll i=l; i<r; i++)
#define repr(i,r,l) for(ll i=r; i>=l; --i)
#define pb push_back
#define mp make_pair
#define Y second
#define X first
using namespace std; 
const long long int mod=1e8,N=1e5+10;
ll a[N],cnt[N];
int main(){
	ios_base::sync_with_stdio(false);	
	cout.tie(0);
	ll t;
	cin >> t;
	rep (i,0,t){
		ll n;
		cin >> n;
		rep (i,0,N) cnt[i]=0;
		rep (i,0,n){
			cin >> a[i];
			cnt[a[i]-1] ++;
		}
		sort(cnt,cnt+N,greater<int>());
		ll ans = 0;
		rep (i,0,n){
			if (cnt[i]==cnt[0])ans++;
		//	cout << cnt[i] << endl;
		}
		//cout << ans << endl;
		//cout << "ans : "<<ans << "cnt  "<<cnt[0]<<endl;
		cout << ans-1+(n-ans*cnt[0])/(cnt[0]-1)<<endl;
	}
}
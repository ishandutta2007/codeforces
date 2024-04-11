#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;

const long long int N=5e5+30;
ll l[N],r[N],a[N],sul[N],sur[N];
int main(){
	ios_base::sync_with_stdio(false);	cout.tie(0);cin.tie(0);
	ll n;
	cin >> n;
	rep (i,0,n) cin >> a[i];
	stack <pair<ll,ll> > st,sr;
	rep (i,0,n){
		while (!st.empty() && st.top().X >= a[i]){
			st.pop();
		}
		if (st.empty()) l[i] = -1;
		else l[i] = st.top().Y;
		st.push(mp(a[i],i));
	}
	repr(i,n-1,0){
		while (!sr.empty() && sr.top().X >= a[i]){
			sr.pop();
		}
		if (sr.empty()) r[i] = -1;
		else r[i] = sr.top().Y;
		sr.push(mp(a[i],i));
	}
	ll ind=0,mx=0;
	//(r[0] == -1) ? dp[0] = n*a[0] : dp[0] = r[0]*a[0] + (n-r[0])*a[r[0]];
	//(l[n-1] == -1) ? dp[n-1] = n*a[n-1] : dp[n-1] = a[n-1]*(n-l[n-1]-1) + (l[n-1]+1) *a[l[n-1]];
	//if (dp[0] > dp[n-1]){
	//	ind = 0;
	//	mx = dp[0];
	//}
	//else {
	//	ind=n-1;
	//	mx = dp[n-1];
	//}
	rep (i,0,n){
		(l[i] == -1) ? sul[i] = (i+1)*a[i] : sul[i] = (i-l[i])*a[i] + sul[l[i]];
	}
	repr(i,n-1,0){
		(r[i] == -1) ? sur[i] = (n-1-i)*a[i] : sur[i] = (r[i]-i-1)*a[i] + sur[r[i]]+a[r[i]];
		if (mx < sur[i]+sul[i]){
			ind = i;
			mx = sur[i] + sul[i];
		}
	}
	rep (i,ind+1,n){
		a[i] = min(a[i],a[i-1]);
	}
	repr (i,ind-1,0) a[i] = min(a[i],a[i+1]);
	rep (i,0,n){
	cout << a[i] << ' ';
	}
}
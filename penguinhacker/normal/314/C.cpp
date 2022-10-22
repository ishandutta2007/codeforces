#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000, mxA=1e6+1, MOD=1e9+7;
int n, a[mxN], dp[mxA];
struct ft {
	int a[mxA+1];
	void add(int i, int val) {for (++i; i<=mxA; i+=i&-i) a[i]=(a[i]+val)%MOD;}
	int sum(int i) {ll res=0; for (++i; i>0; i-=i&-i) res+=a[i]; return res%MOD;}
	int sum(int l, int r) {return (sum(r)-sum(l-1)+MOD)%MOD;}
} f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	ll ans=0;
	f.add(0, 1);
	for (int i=0; i<n; ++i) {
		int old=dp[a[i]], inc=(1ll*a[i]*f.sum(0, a[i])-dp[a[i]]+MOD)%MOD;
		dp[a[i]]=(dp[a[i]]+inc)%MOD;
		ans=(ans+inc)%MOD;
		//cout << inc << ' ';
		f.add(a[i], inc);
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
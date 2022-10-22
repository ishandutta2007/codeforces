#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000;
const ll INF=1e18;
struct Person {
	int crowd;
	vector<int> play;
	bool operator< (const Person &o) const {return crowd>o.crowd;}
} a[100000];

int n, p, k;
//vector<vector<ll>> dp, dpl;
vector<ll> dp;// dpl;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> k;
	for (int i=0; i<n; ++i) {
		cin >> a[i].crowd;
	}
	for (int i=0; i<n; ++i) {
		a[i].play.resize(p);
		for (auto &i: a[i].play)
			cin >> i;
	}
	sort(a, a+n);
	//dp=dpl=vector<vector<ll>>((1<<p), vector<ll>(p+1, -INF));
	//dp=dpl=vector<ll>(1<<p, -INF);
	dp.assign((1<<p), -INF);
	dp[0]=0;
	for (int i=0; i<k; ++i)
		dp[0]+=a[i].crowd;
	for (int i=0; i<n; ++i) {
		//dpl=dp;
		//cout << dp[0] << ' ' << dp[1] << '\n';
		for (int mask=(1<<p)-2; mask>=0; --mask) {
			int cnt=__builtin_popcount(mask);
			if (cnt>i) continue;
			int add=(i<cnt+k)?-a[i].crowd+a[cnt+k].crowd:0;
			for (int j=0; j<p; ++j) if (!(mask&(1<<j))) {
				dp[mask|(1<<j)]=max(dp[mask|(1<<j)], dp[mask]+a[i].play[j]+add);
			}
		}
	}
	cout << dp[(1<<p)-1];
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
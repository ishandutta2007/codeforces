#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const unsigned long long SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

const int mxN=2e5;
int n, m, p, dp[1<<15];
ll like[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> p;
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s;
		for (int j=0; j<m; ++j)
			if (s[j]=='1')
				like[i]|=1ll<<j;
	}
	ll ans=0;
	for (int rep=0; rep<15; ++rep) {
		vector<int> id(m, -1);
		ll x=like[rng()%n];
		int c=0;
		for (int j=0; j<m; ++j)
			if (x&1ll<<j)
				id[j]=c++;
		memset(dp, 0, sizeof(dp));
		for (int i=0; i<n; ++i) {
			ll y=x&like[i];
			ll y2=0;
			while(y) {
				int lb=__builtin_ctzll(y);
				y2+=1ll<<id[lb];
				y-=1ll<<lb;
			}
			++dp[y2];
		}
		for (int j=0; j<c; ++j)
			for (int i=0; i<1<<c; ++i)
				if (!(i&1<<j))
					dp[i]+=dp[i|1<<j];
		int best=0;
		for (int i=1; i<1<<c; ++i)
			if (dp[i]>=(n+1)/2&&__builtin_popcount(i)>__builtin_popcount(best))
				best=i;
		if (__builtin_popcount(best)>__builtin_popcountll(ans)) {
			ans=0;
			for (int i=0; i<m; ++i)
				if (id[i]!=-1&&best&1<<id[i])
					ans|=1ll<<i;
		}
	}
	for (int i=0; i<m; ++i)
		cout << (ans>>i&1);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define debug(x) cerr << "[" << #x << "] = [" << (x) << "]\n"

const int mxN=5000, MOD=998244353;
int n, m;
ll ans=0, iv[5001];
vector<int> cnt;
vector<ll> dp, dpl;

void read() { //initialization
	cin >> n;
	map<int, int> mp;
	for (int i=0; i<n; ++i) {
		int x; cin >> x;
		++mp[x];
	}
	for (auto x: mp)
		cnt.push_back(x.second);
	iv[1]=1;
	for (int i=2; i<=n; ++i)
		iv[i]=(MOD-MOD/i*iv[MOD%i]%MOD)%MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	read();
	m=cnt.size();
	dp.resize(m);
	for (int i=0; i<m; ++i)
		dp[i]=cnt[i]*iv[n]%MOD;
	for (int i=1; i<=m; ++i) {
		dpl=dp;
		dp.assign(m, 0);
		//for (int j=0; j<m; ++j)
		//	cout << dpl[j] << ' ';
		//cout << '\n';
		for (int j=0; j<m; ++j) {
			if (dpl[j]==0) continue;
			ans=(ans+dpl[j]*iv[n-i]%MOD*(cnt[j]-1))%MOD;
			if (j+1<m)
				dp[j+1]+=dpl[j];
		}
		//debug(ans);
		for (int j=1; j<m; ++j)
			dp[j]=(dp[j]+dp[j-1])%MOD;
		for (int j=1; j<m; ++j)
			dp[j]=dp[j]*iv[n-i]%MOD*cnt[j]%MOD;
	}
	//int temp=iv[2]*iv[3]%MOD;
	//debug(temp);
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define int long long
#define ld long double
#define ll long long

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

bool simple(int v) {
	for (int j = 2; j <= sqrt(v); j++) {
		if (v % j == 0) {
			return 0;
		}
	}
	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] == 1){
            mp[1]++;
            continue;
		}
		if (simple(v[i])) {
			mp[v[i]]++;
			continue;
		}
		int k = v[i], now = 2;
		while (v[i] != 1) {
			int cnt = 0;
			while (v[i] % now == 0) {
				v[i] /= now;
				cnt++;
			}
			if (cnt) {
				mp[now]++;
			}
			now++;
		}
		v[i] = k;
	}
	if (mp[1] == n){
        cout << 0;
        return 0;
	}
	bool x = 0;
	for (auto to : mp) {
		if (to.second == n) {
			x = 1;
		}
	}
	if (x) {
		cout << -1;
	}
	else {
		int ans = 1e18;
		for (int i = 0; i < n; i++) {
			int g = v[i];
			for (int j = i + 1; j < n; j++) {
				g = gcd(g, v[j]);
				if (g == 1) {
					ans = min(ans, j - i);
					break;
				}
			}
		}
		cout << ans + n - 1 - mp[1];
	}
	return 0;
}
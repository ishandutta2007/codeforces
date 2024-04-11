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
#define mp make_pair

mt19937 rnd(51);


int32_t main()
{ 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		map<int, int> lol;
		bool x = 0;
		for (auto to : v) {
			int now = k;
			int cnt = 1;
			while (now < 1e16) {
				now *= k;
				cnt++;
			}
			while (now >= 1) {
				if (to >= now) {
					to -= now;
					lol[cnt]++;
				}
				now /= k;
				cnt--;
			}
			if (to != 0) {
				x = 1;
			}
		}
		for (auto to : lol) {
			if (to.second > 1) {
				x = 1;
			}
		}
		if (!x) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
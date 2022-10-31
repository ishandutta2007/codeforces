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

mt19937 rnd(51);

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> v(k), v1(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 0; i < k; i++) {
		cin >> v1[i].first >> v1[i].second;
	}
	string s = "";
	for (int i = 0; i < n - 1; i++) {
		s += "U";
	}
	for (int i = 0; i < m - 1; i++) {
		s += "L";
	}
	bool x = 1;
	for (int i = 0; i < n; i++) {
		if (!x) {
			for (int i = 0; i < m - 1; i++) {
				s += "L";
			}
			if (i != n - 1) s += "D";
			x = 1;
		}
		else {
			for (int i = 0; i < m - 1; i++) {
				s += "R";
			}
			if (i != n - 1) s += "D";
			x = 0;
		}
	}
	cout << s.size() << endl << s;
	return 0;
}
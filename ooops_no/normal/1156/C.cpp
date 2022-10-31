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


int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, z;
	cin >> n >> z;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int l = 0, r = n / 2 + 1;
	while (r - l > 1) {
		int mid = (r + l) / 2;
		bool x = 0;
		for (int i = 0; i < mid; i++) {
			if (v[n - mid + i] - v[i] >= z) {
				continue;
			}
			else {
				x = 1;
			}
		}
		if (!x) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << l;
	return 0;
}
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
//#include<unordered_set>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 5e5 + 10;
vector<int> sum(N);

int get(int l, int r) {
	if (l == 0) {
		return sum[r];
	}
	else {
		return sum[r] - sum[l - 1];
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x, now = 0;
	cin >> n;
	vector<int> a((n + 1) / 2);
	for (int i = 0; i < (n + 1) / 2; i++) {
		cin >> a[i];
		now += a[i];
	}
	cin >> x;
	if (x >= 0) {
        now += x * (n / 2);
		if (now > 0) {
			cout << n << endl;
		}
		else {
			cout << -1 << endl;
		}
		return 0;
	}
	now = 0;
	for (int i = 0; i < n / 2; i++) {
		a.pb(x);
	}
	for (int i = 0; i < n; i++) {
		now += a[i];
		sum[i] = now;
	}
	vector<int> kek(n + 1);
	for (int i = 0; i < (n + 1) / 2; i++) {
		int l = i, r = n;
		while (r - l > 1) {
			int mid = (r + l) / 2;
			if (get(i, mid) > 0) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		kek[l - i + 1]++;
	}
	int lol = 0;
	for (int i = n; i >= (n + 2) / 2; i--) {
		lol += kek[i];
		if (lol >= n - i + 1) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
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

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int ans = 0;
		vector<vector<int>> a(n, vector<int>(m));
		map<int, int> cnt, cnt1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] == 0) cnt[i + j]++;
				else cnt1[i + j]++;
			}
		}
		for (int i = 0; i < (n + m - 1) / 2; i++) {
            ans += min(cnt[i] + cnt[(n + m - 2) - i], cnt1[i] + cnt1[(n + m - 2) - i]);
		}
		cout << ans << endl;
	}
	return 0;
}
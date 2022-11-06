#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int l[n];
	std::vector<int> r(n); for (int o = 0; o < n; o++) { cin >> l[o] >> r[o]; }
	int k; cin >> k;
	int u = lower_bound(r.begin(), r.end(), k) - r.begin();
	cout << n - u << "\n";
}
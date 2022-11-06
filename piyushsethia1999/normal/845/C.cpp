#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	std::vector<int> l(n);
	std::vector<int> r(n);
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
	}
	unordered_map<int, int> m;
	std::vector<int> com(2 * n);
	for (int i = 0; i < n; ++i) com[i] = l[i], com[i + n] = r[i];
	sort(com.begin(), com.end());
	auto e = unique(com.begin(), com.end());
	int p = 0;
	for (auto i = com.begin(); i != e; ++i) m[*i] = p++;
	for (int i = 0; i < n; ++i) l[i] = m[l[i]], r[i] = m[r[i]];
	std::vector<int> v(5 * n);
	for (int i = 0; i < n; ++i) {
		v[l[i]]++;
		v[r[i] + 1]--;
	}
	int u = 0;
	bool ok = false;
	for (int i = 0; i < 4 * n + 1; ++i) {
		u += v[i];
		if (u > 2) {
			ok = true;
		} 
	}
	if (ok) {
		cout << "NO";
	} else {
		cout << "YES";
	}
}
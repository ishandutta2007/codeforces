#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int y = 0;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; y += a[o];}
	sort(a.begin(), a.end());
	int u = n - y % n;
	int r = y / n;
	int i;
	int o = 0;
	for (i = 0; i < u; ++i) {
		o += abs(a[i] - r);
	}
	for (; i < n; ++i) {
		o += abs(a[i] - r - 1);
	} 
	o /= 2ll;
	cout << o << "\n";
}
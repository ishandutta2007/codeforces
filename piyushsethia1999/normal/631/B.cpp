#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int ar[6000][6000];
int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	int k; cin >> k;
	pair<int, int> a[n + 1] = {};
	pair<int, int> b[m + 1] = {};
	for (int i = 0; i < k; ++i)
	{
		int in; cin >> in;
		int l; cin >> l;
		int r; cin >> r;
		if (in == 1) {
			a[l - 1] = {r, i + 1};
		} else {
			b[l - 1] = {r, i + 1};
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << (a[i].second > b[j].second ? a[i].first : b[j].first) << " ";
		cout << "\n";
	}
}
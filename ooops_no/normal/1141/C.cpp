/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
using namespace std;

#define int long long
#define pb push_back
#define ld long double


signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	int mn = 0, mx = 0;
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		v[i] = v[i - 1] + a;
		mx = max(mx, v[i]);
		mn = min(mn, v[i]);
	}
	vector<int> v1;
	for (int i = 0; i < n; i++) {
		v1.pb(v[i]);
	}
	sort(v1.begin(), v1.end());
	for (int i = 1; i < n; i++) {
		if (v1[i] == v1[i - 1]) {
			cout << -1;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (mn + i == 1 && mx + i == n) {
			for (auto to : v) {
				cout << to + i << " ";
			}
			return 0;
		}
	}
	cout << -1;
}
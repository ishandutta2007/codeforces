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
	vector<ld> v(n), v1;
	map<ld, int> m;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		ld a;
		cin >> a;
		if (v[i] == 0 && a != 0) {
			continue;
		}
		if (v[i] == 0 && a == 0) {
			cnt++;
			continue;
		}
		if (a == 0) {
			m[0]++;
			v1.pb(0);
			continue;
		}
		m[v[i] / a]++;
		v1.pb(v[i] / a);
	}
	int mx = 0;
	for (auto to : v1) {
		mx = max(mx, m[to]);
	}
	cout << mx + cnt;
}
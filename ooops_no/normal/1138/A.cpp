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
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> c(n);
	int cnt = 0, st = 0;
	for (int i = 0; i < n - 1; i++) {
		cnt++;
		if (v[i] != v[i + 1]) {
			for (int j = st; j <= i; j++) {
				c[j] = cnt;
			}
			cnt = 0;
			st = i + 1;
		}
	}
	cnt++;
	for (int i = st; i < n; i++) {
		c[i] = cnt;
	}
	int mx = 0;
	for (int i = 0; i < n - 1; i++) {
		if (v[i] != v[i + 1]) {
			mx = max(mx, min(c[i], c[i + 1]) * 2);
		}
	}
	cout << mx;
}
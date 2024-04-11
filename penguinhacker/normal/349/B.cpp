#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int v, a[10], num, mn = 1e9;
string ans = "";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> v;
	for (int i=1; i<=9; ++i)
		cin >> a[i];
	for (int i=9; i>=1; --i) {
		if (a[i] < mn) {
			mn = a[i];
			num = i;
		}
	}
	if (mn > v) {
		cout << -1;
		return 0;
	}

	for (int i=0; i<v/mn; ++i)
		ans += (char)(num+'0');
	v %= mn;
	for (int i=9; i>=num; --i)
		a[i] -= mn;

	for (int i=0; i<ans.size(); ++i) {
		bool ok = 0;
		for (int j=9; j>num; --j) {
			if (v >= a[j]) {
				ans[i] = (char)(j+'0');
				v -= a[j];
				ok = 1;
				break;
			}
		}
		if (!ok) break;
	}
	cout << ans;
	return 0;
}
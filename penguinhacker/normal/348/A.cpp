#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, ans=0;
vector<int> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	a.resize(n);
	for (int i=0, x; i<n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	
	int x = *a.rbegin();
	int temp = x;
	a.pop_back();
	ans += x;
	for (int i : a) {
		temp -= x-i;
		if (temp < 0)
			break;
	}
	if (temp > 0) ans += (temp+n-2)/(n-1);

	cout << ans;
	return 0;
}
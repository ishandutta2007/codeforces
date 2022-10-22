#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n;
vector<pair<int, int>> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	a.resize(n);
	for (int i=0; i<n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());

	int day = 0;
	for (int i=0; i<n; ++i) {
		if (a[i].second >= day)
			day = a[i].second;
		else
			day = a[i].first;
	}
	
	cout << day;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, mx=0;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool pos=0;
	cin >> n;
	v.resize(n);
	for (int i=0; i<n; ++i)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	for (int i=0; i<n; ++i) {
		mx=max(mx,v[i].second);
		if (v[i].second<mx) {
			pos=1;
			break;
		}
	}
	cout << (pos?"Happy Alex":"Poor Alex");
	return 0;
}
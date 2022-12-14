#include"bits/stdc++.h"
using namespace std;

int n;

vector<pair<int, int> > v;
vector<pair<int, int> > vv;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back(make_pair(x, y));
	}
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		vv.push_back(make_pair(-a, -b));
	}
	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());
	cout << v[0].first - vv[0].first << " " << v[0].second - vv[0].second << endl;
	return 0;
}
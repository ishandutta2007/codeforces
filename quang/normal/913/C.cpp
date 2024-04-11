#include <bits/stdc++.h>

using namespace std;

const int N = 100;
const long long INF = (long long)2e18 + 1000;

long long n, l, c[N];
vector<pair<int, long long> > a;

bool cmp(pair<int, long long> u, pair<int, long long> v) {
	 return (1ll << (v.first - u.first)) * u.second >= v.second;
}

long long go(int id, long long l) {
	if (l <= 0) {
		return 0ll;
	}
	//cout << id << " " << l << endl;
	long long res = INF;
	if ((1ll << a[id].first) >= l) {
		res = min(res, a[id].second);
	}
	while (id > 0 && (1ll << a[id - 1].first) >= l) {
		id--;
		res = min(res, a[id].second);
	}
	while ((1ll << a[id].first) > l) {
		id--;
	}
	long long foo = l / (1ll << a[id].first);
	foo *= a[id].second;
	//cout << id << endl;
	// cout << id << " " <<  l / (1ll << a[id].first) << " " << foo << " " << l << endl;
	res = min(res, foo + go(id, l % (1ll << a[id].first)));
	return res;	
}

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	a.push_back(make_pair(0, c[0]));
	for (int i = 1; i < n; i++) {
		if (cmp(a.back(), make_pair(i, c[i]))) {
			a.push_back(make_pair(i, c[i]));
		}
	}
	// for (pair<int, long long> u: a) {
	// 	cout << u.first << " " << u.second << endl;
	// }
	cout << go(a.size() - 1, l) << endl;
	return 0;	
}
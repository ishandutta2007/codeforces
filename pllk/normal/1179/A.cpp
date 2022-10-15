#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, q;
deque<int> d;
int r[444444][2];
int z[333333][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	d.resize(n);
	for (int i = 0; i < n; i++) cin >> d[i];
	for (int i = 1; i <= 2*n; i++) {
		int a = d[0];
		int b = d[1];
		r[i][0] = a;
		r[i][1] = b;
		if (a > b) {
			d.pop_front();
			d.pop_front();
			d.push_front(a);
			d.push_back(b);
		} else {
			d.pop_front();
			d.push_back(a);
		}
	}
	vector<pair<ll,int>> v;
	for (int i = 1; i <= q; i++) {
		ll k;
		cin >> k;
		v.push_back({k,i});
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < q; i++) {
		if (v[i].first <= 2*n) {
			z[v[i].second][0] = r[v[i].first][0];
			z[v[i].second][1] = r[v[i].first][1];
		} else {
			ll k = v[i].first;
			k -= (2*n+1);
			z[v[i].second][0] = d[0];
			z[v[i].second][1] = d[1+k%(n-1)];
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << z[i][0] << " " << z[i][1] << "\n";
	}
}
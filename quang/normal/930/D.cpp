#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int INF = 1e9;
typedef pair<int, int> pi;

int n;
vector<pair<int, int> > a[2];

bool cmp(pi u, pi v){
	return u.second < v.second;
}

long long get(int x, int xx, int y, int yy) {
	if (x >= xx || y >= yy) {
		return 0ll;
	}
	int num1 = (xx - x) / 2;
	int num2 = (yy - y) / 2;
	return 1ll * num1 * num2;
}

long long go(int id) {
	sort(a[id].begin(), a[id].end(), cmp);
	vector<pair<int, int> > b, c;
	b.resize(a[id].size());
	c.resize(a[id].size());
	int l, r;
	l = INF, r = -INF;
	for (int i = 0; i < a[id].size(); i++) {
		l = min(l, a[id][i].first);
		r = max(r, a[id][i].first);
		b[i] = pi(l, r);
	}
	l = INF, r = -INF;
	for (int i = (int)a[id].size() - 1; i >= 0; i--) {
		l = min(l, a[id][i].first);
		r = max(r, a[id][i].first);
		c[i] = pi(l, r);
	}
	long long res = 0;
	for (int i = 0; i + 1 < a[id].size(); i++) {
		int l = max(b[i].first, c[i + 1].first);
		int r = min(b[i].second, c[i + 1].second);
		res += get(l, r, a[id][i].second, a[id][i + 1].second);
	}	
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		int id = (x + y) % 2;
		if (id < 0) {
			id += 2;
		}
		// cout << id << endl;
		a[id].push_back(make_pair(x + y, x - y));
	}
	long long res = 0ll;
	for (int i = 0; i < 2; i++) {
		res += go(i);
	}
	cout << res << endl;
	return 0;	
}
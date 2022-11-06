#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define MAXN 500004

using namespace std;

bool marked[MAXN * 4] = {};
int t[MAXN * 4];

void push(int v) {
    if (marked[v]) {
        t[v*2] = t[v*2+1] = t[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] = new_val;
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) 
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	std::vector<int> l(n);
	std::vector<pair<int, int>> r(n);
	for (int i = 0; i < n; ++i) {
		cin >> l[i];
		cin >> r[i].first;
		r[i].second = i;
	}
	sort(r.begin(), r.end());
	for (int i = 0; i < n; ++i)
		update(1, 0, 500000, l[r[i].second], r[i].first, r[i].first);
	std::vector<std::vector<int> > v(500001, std::vector<int> (20));
	for (int i = 0; i <= 500000; ++i) {
		v[i][0] = get(1, 0, 500000, i);
	}
	for (int i = 500000; i >= 0; --i)
		for (int j = 1; j < 20; ++j) 
			v[i][j] = v[v[i][j - 1]][j - 1];
	for (int o = 0; o < m; ++o) {
		int x; cin >> x;
		int y; cin >> y;
		bool ok = true;
		int yy = 1;
		if (v[x][19] < y) {
			cout << -1 << "\n";
			continue;
		} 
		while (true) {
			if (v[x][0] >= y) {
				break;
			} 
			for (int i = 19; i >= 0; --i) {
				if (v[x][i] < y) {
					yy += (1ll << i);
					x = v[x][i];
				} 
			}
		} 
		cout << yy << "\n";
	}
}
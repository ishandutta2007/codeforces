#include <bits/stdc++.h>

using namespace std;

const int N = 50010, K = 11;

int n, k;
int s[N][K];

struct Data {
	int mn[K], mx[K];
	int cnt;

	Data() {
		for (int i = 0; i < K; i++) {
			mn[i] = 1e9;
			mx[i] = -1e9;
		}
		cnt = 0;
	}

};

bool operator < (const Data &u, const Data &v) {
	for (int i = 1; i <= k; i++) {
		if (u.mx[i] != v.mx[i]) {
			return u.mx[i] < v.mx[i];
		}
	}
	return 1;
}

bool check(const Data &u, const Data &v) {
	int l = 0, r = 0;
	for (int i = 1; i <= k; i++) {
		if (u.mx[i] > v.mn[i]) {
			r = 1;
		}
		if (u.mn[i] < v.mx[i]) {
			l = 1;
		}
	}
	return l && r;
}

void update(Data &u, const Data &v) {
	for (int i = 1; i <= k; i++) {
		u.mx[i] = max(u.mx[i], v.mx[i]);
		u.mn[i] = min(u.mn[i], v.mn[i]);
	}
	u.cnt += v.cnt;
}

int main() {
    //freopen("a.inpa", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cin >> s[i][j];
		}
	}
	set<Data> a;
	for (int i = 1; i <= n; i++) {
//		cout << "A " << i << endl;
		Data foo;
		for (int j = 1; j <= k; j++) {
			foo.mx[j] = foo.mn[j] = s[i][j];
			foo.cnt = 1;
		}
		if (a.empty()) {
			a.insert(foo);
			cout << 1 << endl;
			continue;
		}
//		cout << "C " << a.size() << endl;
		while (!a.empty()) {
			auto it = a.lower_bound(foo);
			if (it == a.end()) {
				break;
			}
			Data bar = *it;
			if (check(foo, bar)) {
				update(foo, bar);
				a.erase(it);
			} else {
                break;
			}
		}
		while (!a.empty()) {
			auto it = a.lower_bound(foo);
			if (it == a.begin()) {
				break;
			}
			it--;
			Data bar = *it;
			if (check(bar, foo)) {
				update(foo, bar);
				a.erase(it);
			} else {
                break;
			}
		}
//		cout << "B " << i << endl;;
		a.insert(foo);
		cout << a.rbegin()->cnt << endl;
	}
	return 0;
}
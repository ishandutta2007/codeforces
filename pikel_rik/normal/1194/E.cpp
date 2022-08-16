#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 5000 + 5;

template <typename T>
class FenwickTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> bit;
    F f;

    FenwickTree(): n(), bit(), f() {}
    FenwickTree(int n, F f = plus<T>()): n(n), bit(n + 1, 0), f(f) {}

    void add(int i, T val) {
        for (; i <= n; i += i & -i) {
            bit[i] = f(bit[i], val);
        }
    }
    T query(int i) {
        T ans = T();
        for (; i; i -= i & -i) {
            ans = f(ans, bit[i]);
        }
        return ans;
    }
};

struct seg {
	int x1, y1;
	int x2, y2;
	seg(): x1(), y1(), x2(), y2() {}
};

int n;
seg a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
		if (a[i].x1 > a[i].x2) {
			swap(a[i].x1, a[i].x2);
		}if (a[i].y1 > a[i].y2) {
			swap(a[i].y1, a[i].y2);
		}
	}

	vector<seg> v, h;
	for (int i = 0; i < n; i++) {
		if (a[i].x1 == a[i].x2) {
			v.push_back(a[i]);
		} else {
			h.push_back(a[i]);
		}
	}

	sort(v.begin(), v.end(), [&] (const seg& a, const seg& b) {
		return a.x1 < b.x1;
	});

	ll ans = 0;
	FenwickTree<int> ft(10001);
	const int z = 5001;

	for (int i = 0; i < v.size(); i++) {
		vector<pair<int, int>> s;
		for (auto& hh : h) {
			if (v[i].y1 <= hh.y1 && hh.y1 <= v[i].y2 && hh.x1 <= v[i].x1 && v[i].x1 < hh.x2) {
				s.emplace_back(hh.x2 - v[i].x1, hh.y1);
				ft.add(z + hh.y1, 1);
			}
		}
		sort(s.begin(), s.end());
		reverse(s.begin(), s.end());

		for (int j = i + 1; j < v.size() && !s.empty(); j++) {
			if (v[j].x1 == v[i].x1) continue;
			while (!s.empty() and s.back().first < v[j].x1 - v[i].x1) {
				ft.add(z + s.back().second, -1);
				s.pop_back();
			}
			if (v[i].y2 <= v[j].y1 or v[j].y2 <= v[i].y1) {

			} else {
				int l = max(v[i].y1, v[j].y1), r = min(v[i].y2, v[j].y2);
				int qty = ft.query(z + r) - ft.query(z + l - 1);
				ans += ((ll)qty * qty - qty) / 2;
			}
		}
		while (!s.empty()) {
			ft.add(z + s.back().second, -1);
			s.pop_back();
		}
	}
	cout << ans << '\n';
	return 0;
}
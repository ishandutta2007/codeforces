#include <bits/stdc++.h>
using namespace std;

struct union_find {
	int n;
	std::vector<int> p, r, l;

	union_find() : n() {}
	union_find(int n) : n(n), p(n), r(n), l(n) {
		std::iota(p.begin(), p.end(), 0);
        iota(l.begin(), l.end(), 0);
	}

	int find(int x) {
		return x == p[x] ? x : p[x] = find(p[x]);
	}

	void merge(int x, int y) {
		int l1 = find(x);
        p[y] = l1;
        l[l1] = l[y];
        r[l1] += r[y];
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n + m);
    for (auto &x : a) cin >> x;

    vector<int> ind(n + m);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    vector<int> k(q);
    for (auto &x : k) cin >> x;

    vector<int> ind_k(q);
    iota(ind_k.begin(), ind_k.end(), 0);
    sort(ind_k.begin(), ind_k.end(), [&](int i, int j) {
        return k[i] < k[j];
    });

    vector<int> ind_diff(n + m - 1);
    iota(ind_diff.begin(), ind_diff.end(), 1);
    sort(ind_diff.begin(), ind_diff.end(), [&](int i, int j) {
        return a[ind[i]] - a[ind[i - 1]] < a[ind[j]] - a[ind[j - 1]];
    });

    vector<long long> ans(q);

    long long cur_ans = accumulate(a.begin(), a.begin() + n, 0ll);

    union_find uf(n + m);
    for (int i = 0; i < n + m; i++) {
        if (ind[i] < n) {
            uf.r[i] = 1;
        }
    }

    vector<long long> pref(n + m);
    for (int i = 0; i < n + m; i++) {
        pref[i] = a[ind[i]];
    }

    partial_sum(pref.begin(), pref.end(), pref.begin());

    auto contribution = [&](int u) -> long long {
        u = uf.find(u);
        return pref[u] - (u < uf.r[u] ? 0 : pref[u - uf.r[u]]);
    };

    int j = 0, jj;
    for (int qi : ind_k) {
        while (j < n + m - 1 && (jj = ind_diff[j], a[ind[jj]] - a[ind[jj - 1]] <= k[qi])) {
            cur_ans -= contribution(jj);
            cur_ans -= contribution(jj - 1);
            uf.merge(jj, jj - 1);
            cur_ans += contribution(jj);
            j += 1;
        }
        ans[qi] = cur_ans;
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

struct seg_tree {
    vector<int> tree{};
    int n{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }

    void upd(int v, int l, int r, int pos, int x) {
        if (l > pos || r <= pos) return;
        if (l + 1 == r) {
            tree[v] += x;
            return;
        }
        upd(v * 2, l, (l + r) / 2, pos, x);
        upd(v * 2 + 1, (l + r) / 2, r, pos, x);
        tree[v] += x;
    }

    int get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return 0;
        if (lq <= l && r <= rq) {
            return tree[v];
        }
        return get(v * 2, l, (l + r) / 2, lq, rq) + get(v * 2 + 1, (l + r) / 2, r, lq, rq);
    }

    void upd(int pos, int x) {
        upd(1, 0, n, pos, x);
    }

    int get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

bool comp(ar<int,3> &a, ar<int, 3> &b) {
    return a[1] < b[1];
}

void solve() {
    int n; cin >> n;
    vector<ar<int, 3>> horizontal, vertical;
    range(i, n) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1 += 5000;
        y1 += 5000;
        x2 += 5000;
        y2 += 5000;
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            vertical.push_back({x1, y1, y2});
        } else {
            if (x1 > x2) swap(x1, x2);
            horizontal.push_back({x1, x2, y1});
        }
    }
    sort(all(vertical));
    sort(all(horizontal));
    seg_tree st;
    st.build(10005);
    int j = 0;
    ll ans = 0;
    range(i, (int)vertical.size()) {
        int x = vertical[i][0];
        while(j < horizontal.size() && horizontal[j][0] <= x) {
            j++;
        }
        sort(horizontal.begin(), horizontal.begin() + j, comp);
        int k = j - 1;
        for(int e = (int)vertical.size() - 1; e > i; --e) {
            int x2 = vertical[e][0];
            int y1 = max(vertical[i][1], vertical[e][1]);
            int y2 = min(vertical[i][2], vertical[e][2]);
            while(k >= 0 && horizontal[k][1] >= x2) {
                st.upd(horizontal[k][2], 1);
                k--;
            }
            ll cnt = st.get(y1, y2 + 1);
            ans += cnt * (cnt - 1) / 2;
        }
        k++;
        while(k != j) {
            st.upd(horizontal[k][2], -1);
            k++;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}
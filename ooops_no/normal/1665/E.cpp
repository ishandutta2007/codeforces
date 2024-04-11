#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld double
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10, INF = 1e9 + 1e8;
pair<int,int> t[2 * N];
int n;

void upd(int i, int val) {
    i += n;
    t[i].first += val;
    for (; i >= 1; i /= 2) {
        t[i / 2] = min(t[i], t[i ^ 1]);
    }
}

pair<int,int> get(int l, int r) {
    l += n, r += n + 1;
    pair<int,int> ans{INF, INF};
    while (l < r) {
        if (l & 1) {
            ans = min(ans, t[l]);
            l++;
        }
        if (r & 1) {
            r--;
            ans = min(ans, t[r]);
        }
        l /= 2, r /= 2;
    }
    return ans;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n;
        for (int i = 0; i < 2 * n; i++) {
            t[i] = {0, i % n};
        }
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            upd(i, a[i]);
        }
        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            vector<int> b, ind;
            for (int j = 0; j < min(r - l + 1, 31ll); j++) {
                pair<int,int> p = get(l, r);
                upd(p.second, INF);
                ind.pb(p.second);
                b.pb(p.first);
            }
            int res = 0;
            while (b[1] > 0) {
                int mx = -1;
                for (int j = 0; j < 30; j++) {
                    if (b[1] & (1 << j)) {
                        mx = j;
                    }
                }
                int val = (1 << mx);
                res += val;
                if (b[0] < val) {
                    for (int j = 1; j < b.size(); j++) {
                        b[j] -= val;
                    }
                    for (int j = 0; j + 1 < b.size(); j++) {
                        if (b[j] > b[j + 1]) swap(b[j], b[j + 1]);
                        else break;
                    }
                } else {
                    for (int j = 0; j < b.size(); j++) {
                        b[j] -= val;
                    }
                }
            }
            cout << res << endl;
            for (auto to : ind) {
                upd(to, -INF);
            }
        }
    }
    return 0;
}
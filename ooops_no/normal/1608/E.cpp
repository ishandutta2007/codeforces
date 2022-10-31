#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double

mt19937 rnd(51);

struct st {
    vector<int> t;
    st(int n) {
        t.resize(4 * n);
    }
    void update(int v, int l, int r, int pos, int val) {
        if (l == r) {
            t[v] += val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) {
            update(2 * v, l, m, pos, val);
        } else {
            update(2 * v + 1, m + 1, r, pos, val);
        }
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
    int go(int v, int l, int r, int k) {
        if (l == r) {
            return l;
        }
        int m = (l + r) / 2;
        if (t[v * 2] >= k) {
            return go(2 * v, l, m, k);
        }
        else{
            return go(2 * v + 1, m + 1, r, k - t[v * 2]);
        }
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (tl == l && tr == r) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return get(2 * v, tl, tm, l, min(r, tm)) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }
};

struct Point {
    int x, y, t;
};

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Point> a(n);
    vector<int> u_x, u_y;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].t;
        a[i].t--;
        u_x.pb(a[i].x);
        u_y.pb(a[i].y);
    }
    sort(u_x.begin(), u_x.end());
    u_x.erase(unique(u_x.begin(), u_x.end()), u_x.end());
    sort(u_y.begin(), u_y.end());
    u_y.erase(unique(u_y.begin(), u_y.end()), u_y.end());
    for (int i = 0; i < n; i++) {
        a[i].x = lower_bound(u_x.begin(), u_x.end(), a[i].x) - u_x.begin();
        a[i].y = lower_bound(u_y.begin(), u_y.end(), a[i].y) - u_y.begin();
    }
    int ans = 0, szx = u_x.size(), szy = u_y.size();
    for (int q = 0; q < 4; q++) {
        vector<int> p(3);
        iota(p.begin(), p.end(), 0);
        do {
            int j = 0, cnt0 = 0;
            st F1x(n), F1y(n), F2x(n), F2y(n);
            sort(a.begin(), a.end(), [&](Point i, Point j) {return i.x < j.x || (i.x == j.x && p[i.t] > p[j.t]);});
            for (int i = 0; i < n; i++) {
                if (p[a[i].t] == 1) {
                    F1x.update(1, 0, n - 1, a[i].x, 1);
                    F1y.update(1, 0, n - 1, a[i].y, 1);
                } else if (p[a[i].t] == 2) {
                    F2x.update(1, 0, n - 1, a[i].x, 1);
                    F2y.update(1, 0, n - 1, a[i].y, 1);
                }
            }
            for (int i = 0; i < u_x.size(); i++) {
                while (j < a.size() && a[j].x <= i) {
                    if (p[a[j].t] == 0) {
                        cnt0++;
                        if (F1x.get(1, 0, n - 1, 0, n - 1) >= cnt0) {
                            int ind = F1x.go(1, 0, n - 1, cnt0);
                            ans = max(ans, min(cnt0, F2x.get(1, 0, n - 1, ind + 1, n - 1)));
                            ind = F1y.go(1, 0, n - 1, cnt0);
                            ans = max(ans, min(cnt0, F2y.get(1, 0, n - 1, ind + 1, n - 1)));
                        }
                    } else if (p[a[j].t] == 1) {
                        F1x.update(1, 0, n - 1, a[j].x, -1);
                        F1y.update(1, 0, n - 1, a[j].y, -1);
                    } else if (p[a[j].t] == 2) {
                        F2x.update(1, 0, n - 1, a[j].x, -1);
                        F2y.update(1, 0, n - 1, a[j].y, -1);
                    }
                    j++;
                }
            }
        } while (next_permutation(p.begin(), p.end()));
        if (q == 0) {
            for (int i = 0; i < n; i++) {
                a[i].x = szx - a[i].x - 1;
            }
        } else if (q == 1) {
            for (int i = 0; i < n; i++) {
                a[i].x = szx - a[i].x - 1;
                swap(a[i].x, a[i].y);
            }
        } else if (q == 2) {
            for (int i = 0; i < n; i++) {
                a[i].x = szy - a[i].x - 1;
            }
        }
    }
    cout << ans * 3 << endl;
    return 0;
}
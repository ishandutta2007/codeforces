#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 305;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}


int rev(int a) {
    return binpow(a, md - 2);
}

struct component {
    int l, r;
    int p_left;
    int p_right;
    int p_mid;

    component() = default;

    component(int x) : r(x) {}
};

bool operator<(const component &a, const component &b) {
    return a.r < b.r;
}

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), v(n), p(n);
    int r100 = rev(100);
    set<component> s;
    range(i, n) {
        cin >> x[i] >> v[i] >> p[i];
        p[i] = mul(p[i], r100);
        component cur;
        cur.l = cur.r = i;
        cur.p_left = sub(1, p[i]);
        cur.p_right = p[i];
        cur.p_mid = 1;
        s.insert(cur);
    }
    vector<ar<int, 4>> events;
    range(i, n - 1) {
        int w = x[i + 1] - x[i];
        {
            events.push_back({w, v[i] + v[i + 1], i, -1});
        }
        if (v[i] > v[i + 1]) {
            // 
            events.push_back({w, v[i] - v[i + 1], i, 1});
        } else if (v[i + 1] > v[i]) {
            // 
            events.push_back({w, -v[i] + v[i + 1], i, 0});
        }
    }
    sort(all(events), [&](const ar<int, 4> &a, const ar<int, 4> &b) {
        return 1ll * a[0] * b[1] < 1ll * a[1] * b[0];
    });
    int ans = 0;
    int previous = 0;
    int prob = 1;
    vector<int> must(n, -1);
    for (auto &[d1, d2, i, t] : events) {
        int curt = mul(d1 % md, rev(d2 % md));
        ans = add(ans, mul(sub(curt, previous), prob));
        previous = curt;
        if (t == -1) {
            if (must[i] == 0) continue;
            if (must[i + 1] == 1) continue;
            if (must[i + 1] == 0 && must[i] == 1) {
                prob = 0;
                break;
            }
            if (must[i] == 1) {
                auto it2 = s.lower_bound(i + 1);
                auto comp2 = *it2;
                s.erase(it2);
                prob = mul(prob, rev(comp2.p_mid));
                for (int j = comp2.l; j <= comp2.r; ++j) {
                    must[j] = 1;
                }
                prob = mul(prob, comp2.p_right);
            } else if (must[i + 1] == 0) {
                auto it1 = s.lower_bound(i);
                auto comp1 = *it1;
                s.erase(it1);
                prob = mul(prob, rev(comp1.p_mid));
                for (int j = comp1.l; j <= comp1.r; ++j) {
                    must[j] = 0;
                }
                prob = mul(prob, comp1.p_left);
            } else {
                auto it1 = s.lower_bound(i);
                auto it2 = s.lower_bound(i + 1);
                auto comp1 = *it1;
                auto comp2 = *it2;
                s.erase(it2);
                s.erase(it1);
                prob = mul(prob, rev(mul(comp1.p_mid, comp2.p_mid)));
                component new_comp;
                new_comp.l = comp1.l;
                new_comp.r = comp2.r;
                new_comp.p_mid = sub(
                        add(mul(comp1.p_mid, comp2.p_right), mul(comp2.p_mid, comp1.p_left)),
                        mul(comp1.p_left, comp2.p_right));
                new_comp.p_right = mul(comp1.p_right, comp2.p_right);
                new_comp.p_left = mul(comp1.p_left, comp2.p_left);
                s.insert(new_comp);
                prob = mul(prob, new_comp.p_mid);
            }
        } else if (t == 1) {
            // i -> i + 1
            if (must[i] == 1) {
                prob = 0;
                break;
            }
            if (must[i] == 0) continue;
            auto it = s.lower_bound(i);
            auto comp = *it;
            s.erase(it);
            prob = mul(prob, rev(comp.p_mid));
            int lc = 1;
            for(int j = comp.l; j <= i; ++j) {
                comp.p_mid = sub(comp.p_mid, mul(lc, comp.p_right));
                comp.p_right = mul(comp.p_right, rev(p[j]));
                comp.p_left = mul(comp.p_left, rev(sub(1, p[j])));
                lc = mul(lc, sub(1, p[j]));
                must[j] = 0;
            }
            prob = mul(prob, comp.p_mid);
            if (comp.r == i) continue;
            comp.p_mid = mul(comp.p_mid, rev(lc));
            comp.l = i + 1;
            s.insert(comp);
        } else if (t == 0) {
            // i <- i + 1
            if (must[i + 1] == 0) {
                prob = 0;
                break;
            }
            if (must[i + 1] == 1) continue;
            auto it = s.lower_bound(i + 1);
            auto comp = *it;
            s.erase(it);
            prob = mul(prob, rev(comp.p_mid));
            int rc = 1;
            for(int j = comp.r; j >= i + 1; --j) {
                comp.p_mid = sub(comp.p_mid, mul(rc, comp.p_left));
                comp.p_right = mul(comp.p_right, rev(p[j]));
                comp.p_left = mul(comp.p_left, rev(sub(1, p[j])));
                rc = mul(rc, p[j]);
                must[j] = 1;
            }
            prob = mul(prob, comp.p_mid);
            if (comp.l == i + 1) continue;
            comp.p_mid = mul(comp.p_mid, rev(rc));
            comp.r = i;
            s.insert(comp);
        }
    }
    ans = sub(ans, mul(prob, previous));
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

const int MOD = 1e9 + 7, INF = 1e18;
int n, m, seed, v_max;
map<pair<int,int>, int> val;

set<pair<int,int>> st;

int rnd() {
    int res = seed;
    seed = (seed * 7 + 13) % MOD;
    return res;
}

int binpow(int a, int n, int mod) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int g = binpow(a, n / 2, mod);
        return (g * g % mod);
    } else {
        return (binpow(a, n - 1, mod) * a % mod);
    }
}

void add(int i) {
    auto it = st.lower_bound({i, INF});
    it--;
    pair<int,int> seg = *it;
    if (seg.first == i) return;
    st.erase(seg);
    st.insert({seg.first, i - 1});
    st.insert({i, seg.second});
    val[{seg.first, i - 1}] = val[{i, seg.second}] = val[seg];
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> seed >> v_max;
    vector<int> a(n);
    int last = 0;
    for (int i = 0; i < n; i++) {
        a[i] = rnd() % v_max + 1;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            st.insert({last, i - 1});
            val[{last, i - 1}] = a[i - 1];
            last = i;
        }
    }
    st.insert({last, n - 1});
    val[{last, n - 1}] = a.back();
    st.insert({n, n});
    for (int i = 0; i < m; i++) {
        int t = rnd() % 4 + 1, l = rnd() % n, r = rnd() % n, x, y;
        if (l > r) swap(l, r);
        if (t == 3) {
            x = rnd() % (r - l + 1) + 1;
        } else {
            x = rnd() % v_max + 1;
        }
        if (t == 4) {
            y = rnd() % v_max + 1;
        }
        add(l);
        add(r + 1);
        if (t == 1) {
            auto it = st.lower_bound({l, 0});
            while (it->second <= r) {
                val[*it] += x;
                it++;
            }
        } else if (t == 2) {
            vector<pair<int,int>> u;
            auto it = st.lower_bound({l, 0});
            while (it->second <= r) {
                u.pb(*it);
                it++;
            }
            for (auto to : u) {
                st.erase(to);
            }
            st.insert({l, r});
            val[{l, r}] = x;
        } else if (t == 3) {
            vector<pair<int,int>> u;
            auto it = st.lower_bound({l, 0});
            while (it->second <= r) {
                u.pb({val[*it], it->second - it->first + 1});
                it++;
            }
            sort(u.begin(), u.end());
            for (int j = 0; j < u.size(); j++) {
                if (u[j].second >= x) {
                    cout << u[j].first << endl;
                    break;
                } else {
                    x -= u[j].second;
                }
            }
        } else {
            int res = 0;
            auto it = st.lower_bound({l, 0});
            while (it->second <= r) {
                res += (binpow(val[*it] % y, x, y) * (it->second - it->first + 1)) % y;
                it++;
            }
            cout << res % y << endl;
        }
    }
    return 0;
}
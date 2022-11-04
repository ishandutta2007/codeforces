/*

      #     #     #####  #####  #           #  #
     # #   # #    #      #   #  #     #     #  #
    #   # #   #   #####  #   #   #   # #   #   #
   #     #     #  #      #   #    # #   # #     
   #           #  #####  #####     #     #     @

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-7;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define rep(i, f, t) for (int i = f; i < t; i++)

ll power(ll x, ll y, ll mod = MOD) {
    if (y == 0) {
        return 1;
    }
    if (y & 1) {
        return power(x, y - 1, mod) * x % mod;
    } else {
        ll tmp = power(x, y / 2, mod);
        return tmp * tmp % mod;
    }
}

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

template<typename T> void read(T first, T last) {
    while (first != last) {
        cin >> *(first++);
    }
}

template<typename T> void print(T first, T last) {
    while (first != last) {
        cout << *(first++) << " ";
    }
    cout << "\n";
}  

void run();

#define TASK ""

int main() {
#ifdef LOCAL
    if (strlen(TASK) > 0) {
        cerr << "Reminder: you are using file i/o, filename: " TASK "!" << endl << endl;
    }
#endif
#ifndef LOCAL
    if (strlen(TASK)) {
        freopen(TASK ".in", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    cout << fixed << setprecision(12);
    run();
    return 0;
}

// == SOLUTION == //
const int N = (int) 1e5 + 123;
const int M = (int) sqrt(N) + 5;

struct SegMax {
    vector<int> a, st;
    vector<int> p, ma, rnk;
    
    SegMax() {
        a.reserve(N);
        st.reserve(N);
        p.reserve(N);
        ma.reserve(N);
        rnk.reserve(N);
    }
    
    int get(int v) {
        if (v == p[v]) return v;
        return (p[v] = get(p[v]));
    }
    
    void unite(int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v) return;
        if (rnk[u] < rnk[v]) swap(u, v);
        if (rnk[u] == rnk[v]) rnk[u]++;
        p[v] = u;
        ma[u] = max(ma[u], ma[v]);
    }
    
    void add(int x) {
        a.push_back(x);
        ma.push_back(a[sz(a) - 1]);
        p.push_back(sz(a) - 1);
        rnk.push_back(0);
        while (!st.empty() && a[st.back()] <= x) {
            unite(st.back(), sz(a) - 1);
            st.pop_back();
        }
        st.push_back(sz(a) - 1);
    }
    
    int get_max(int pos) {
        if (pos <= 0 || pos > sz(a)) return -INF;
        return ma[get(sz(a) - pos)];
    }
    
    void clear() {
        a.clear();
        st.clear();
        p.clear();
        ma.clear();
        rnk.clear();
    }
};

int n, m, q;
vector<int> to[N];
int from[N];

int go[N][M], dp[N][M];

void run() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
         int l, r;
         cin >> l >> r;
         from[r] = l;
         to[l].push_back(r);
     }
     for (int i = 1; i <= n; i++) {
         sort(to[i].begin(), to[i].end());
     }
     
     for (int l = n; l >= 1; l--) {
         int ptr = -1;
         for (int j = 1; j < M; j++) {
             int r = j * M;
             if (r < l || r > n) continue;
             while (ptr + 1 < sz(to[l]) && to[l][ptr + 1] <= r) ptr++;
             go[l][j] = (ptr == -1 ? l : to[l][ptr]);
         }
     }
     
     SegMax qmax;
     for (int j = 1; j < M; j++) {
         for (int l = n; l >= 1; l--) {
             int r = j * M;
             if (r < l || r > n) continue;
             dp[l][j] = max(go[l][j], qmax.get_max(go[l][j] - l));
             qmax.add(dp[l][j]);
         }
         qmax.clear();
     }
     
     int q;
     cin >> q;
     for (int qq = 0; qq < q; qq++) {
         int l, r;
         cin >> l >> r;
         
         int j = 0;
         while ((j + 1) * M <= r) j++;
         int mx = max(l, dp[l][j]);
         for (int i = max(l, j * M) + 1; i <= r; i++) {
             if (from[i] && l <= from[i] && from[i] <= mx) {
                 mx = i;
             }
         }
         
         cout << mx << "\n";
     }
}
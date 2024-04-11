#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x -= y;
    if(x < 0)
        x += MOD;
}

struct RMQ { //min
    vector < vector <int> > rmq;
    vector <int> arr, lg;
    int n;
    inline void init(int _n) {
        n = _n;
        lg.resize(n + 1);
        for(int i = 2; i <= n; i++) {
            lg[i] = lg[i >> 1] + 1;
        }
        rmq.resize(n + 1, vector <int>(lg[n] + 1));
        arr.resize(n + 1);
    }
    inline void compute() {
        for(int bit = 1; (1 << bit) <= n; bit++) {
            for(int i = 1; i + (1 << bit) <= n + 1; i++) {
                int a = rmq[i][bit - 1], b = rmq[i + (1 << (bit - 1))][bit - 1];
                if(arr[a] > arr[b]) {
                    rmq[i][bit] = b;
                }
                else {
                    rmq[i][bit] = a;
                }
            }
        }
    }
    inline int get(int l, int r) {
        int bit = lg[r - l + 1];
        int a = rmq[l][bit], b = rmq[r - (1 << bit) + 1][bit];
        if(arr[a] < arr[b]) return a;
        return b;
    }
};

struct LCA {
    vector < vector <int> > g;
    vector <int> lvl, first;
    int n, sz;
    RMQ R;
    inline void init(int _n) {
        n = _n;
        sz = 0;
        g.resize(n + 1);
        lvl.resize(n + 1);
        first.resize(n + 1);
        R.init(2 * n - 1);
    }
    inline void addEdge(int x, int y) {
        g[x].push_back(y);
        g[y].push_back(x);
    }
    void dfs(int nod, int par) {
        lvl[nod] = lvl[par] + 1;

        R.arr[nod] = lvl[nod];
        R.rmq[++sz][0] = nod;
        first[nod] = sz;

        for(auto it : g[nod]) {
            if(it != par) {
                dfs(it, nod);
                R.rmq[++sz][0] = nod;
            }
        }
    }
    inline void compute() {
        dfs(1, 0);
        R.compute();
    }
    inline int get(int x, int y) {
        x = first[x], y = first[y];
        if(x > y) {
            swap(x, y);
        }
        return R.get(x, y);
    }
}lca;

struct Fenwick {
    vector <int> aib;
    int n;
    inline void init(int _n) {
        n = _n;
        aib.resize(n + 1);
    }
    inline void update(int pos, int val) {
        for(int i = pos; i <= n; i += lsb(i)) {
            aib[i] += val;
        }
    }
    inline int query(int pos) {
        int ans = 0;
        for(int i = pos; i > 0; i -= lsb(i)) {
            ans += aib[i];
        }
        return ans;
    }
    inline int sum(int l, int r) {
        return query(r) - query(l - 1);
    }
};

struct PlusMinus {
    vector < vector <int> > g;
    vector <int> first, last, arr;
    int n, sz;
    Fenwick fen;
    inline void init(int _n) {
        n = _n;
        sz = 0;
        g.resize(n + 1);
        first.resize(n + 1);
        last.resize(n + 1);
        arr.resize(n + 1);
        fen.init(2 * n);
    }
    inline void addEdge(int x, int y) {
        g[x].push_back(y);
        g[y].push_back(x);
    }
    void dfs(int nod, int par) {
        first[nod] = ++sz;
        for(auto it : g[nod]) {
            if(it != par) {
                dfs(it, nod);
            }
        }
        last[nod] = ++sz;
    }
    inline void compute() {
        dfs(1, 0);
    }
    inline void update(int x, int val) {
        fen.update(first[x], val);
        fen.update(last[x], -val);
        arr[x] += val;
    }
    inline int query(int x, int anc) {
        return fen.query(first[x]) - fen.query(first[anc]);
    }
    inline int solve(int x, int y) {
        int nod = lca.get(x, y);
        return query(x, nod) + query(y, nod) + arr[nod];
    }
}pm;

bool cmp(const pair <int, int> &a, const pair <int, int> &b) {
    return a.second < b.second;
}

const int MAXM = 300;

int dp[2][MAXM + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    pm.init(n);
    lca.init(n);
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        lca.addEdge(x, y);
        pm.addEdge(x, y);
    }
    lca.compute();
    pm.compute();
    while(q > 0) {
        q--;
        int k, m, r;
        cin >> k >> m >> r;
        vector < pair <int, int> > arr;
        for(i = 1; i <= k; i++) {
            int nod;
            cin >> nod;
            pm.update(nod, 1);
            arr.push_back({nod, 0});
        }
        for(auto &it : arr) {
            it.second = pm.solve(it.first, r) - 1;
        }
        sort(arr.begin(), arr.end(), cmp);
        for(i = 1; i <= m; i++) {
            dp[0][i] = 0;
        }
        dp[0][1] = 1;
        for(i = 1; i < k; i++) {
            for(j = 1; j <= m; j++) {
                dp[i & 1][j] = (dp[1 - i & 1][j - 1] + 1LL * dp[1 - i & 1][j] * (j - arr[i].second)) % MOD;
            }
        }
        for(auto it : arr) {
            pm.update(it.first, -1);
        }
        int ans = 0;
        for(i = 1; i <= m; i++) {
            add(ans, dp[1 - k & 1][i]);
        }
        cout << ans << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}
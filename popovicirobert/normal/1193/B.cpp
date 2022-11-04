#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = (int) 1e9 + 7;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

/*int fact[], invfact[];

inline void prec(int n) {
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invfact[n] = lgput(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--) {
        invfact[i] = (1LL * invfact[i + 1] * (i + 1)) % MOD;
    }
}

inline int comb(int n, int k) {
    if(n < k) return 0;
    return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
}*/

using namespace std;

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1];
pair <int, int> arr[MAXN + 1];

map <int, ll> mp[MAXN + 1];

void dfs(int nod) {
    for(auto it : g[nod]) {
        dfs(it);
        if(mp[nod].size() < mp[it].size()) {
            swap(mp[nod], mp[it]);
        }
        for(auto itr : mp[it]) {
            mp[nod][itr.first] += itr.second;
        }
    }

    if(arr[nod].first > 0) {
        auto it = mp[nod].upper_bound(arr[nod].first);
        mp[nod][arr[nod].first] += arr[nod].second;

        while(1) {
            if(it == mp[nod].end()) {
                break;
            }
            if(it -> second > arr[nod].second) {
                it -> second -= arr[nod].second;
                break;
            }
            arr[nod].second -= it -> second;
            mp[nod].erase(it++);
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    for(i = 2; i <= n; i++) {
        int par;
        cin >> par;
        g[par].push_back(i);
    }

    arr[1] = {k, 0};
    for(i = 1; i <= m; i++) {
        int nod, day, cst;
        cin >> nod >> day >> cst;
        arr[nod] = {day, cst};
    }

    dfs(1);

    ll ans = 0;
    for(auto it : mp[1]) {
        ans += it.second;
    }

    cout << ans;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1000000000000000000LL;
//const int mod = 1000000007;

struct Hash {
    int p, mod;
    
    Hash(int _p, int _mod) : p(_p), mod(_mod) {}
    
    int value(const vector<int> &v) {
        int res = 0;
        for (int i : v) {
            res = (res * p + i) % mod;
        }
        return res;
    }
};

Hash h1(500069, 1000000007), h2(500083, 1000000009);

struct Algo {
    vector<int> v;
    vector<vector<int> > drogi;
    int n, m;
    map<pair<int, int>, int> mapa;
    
    Algo() {
        cin >> n >> m;
        v.resize(n + 10);
        drogi.resize(n + 10);
        
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        for (int a, b, i = 1; i <= m; i++) {
            cin >> a >> b;
            drogi[b].push_back(a);
        }
        
        for (int i = 1; i <= n; i++) {
            sort(drogi[i].begin(), drogi[i].end());
            if (drogi[i].size()) {
                mapa[{h1.value(drogi[i]), h2.value(drogi[i])}] += v[i];
            }
        }
        
        int res = 0;
        for (auto i : mapa) {
            res = __gcd(res, i.second);
        }
        cout << res << "\n";
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        Algo p;
    }
    
    return 0;
}/*

*/
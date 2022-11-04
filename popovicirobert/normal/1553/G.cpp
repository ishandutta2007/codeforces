#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;

constexpr int MAXVAL = (int)1e6;

int par[MAXVAL + 1];

int root(int x) {
    return par[x] == 0 ? x : par[x] = root(par[x]);
}

inline void join(int x, int y) {
    x = root(x), y = root(y);
    if (x != y) {
        par[x] = y;
    }
}


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);

    auto Get = [&](int x) {
        vector<int> fact;

        int d = 2;
        while (d * d <= x) {
            int e = 0;
            while (x % d == 0) {
                x /= d;
                e++;
            }
            if (e) {
                fact.push_back(d);
            }
            d++;
        }
        if (x > 1) {
            fact.push_back(x);
        }

        return fact;
    };


    vector<vector<int>> fact(n + 1);
    map<pair<int, int>, bool> mp;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        auto x = Get(a[i]);
        for (auto itr1 : x) {
            for (auto itr2 : x) {
                join(itr1, itr2);
            }
        }

        fact[i] = std::move(x);
    }

    for (int i = 1; i <= n; i++) {
        auto y = Get(a[i] + 1);

        for (auto itr1 : y) {
            int r1 = root(itr1);
            for (auto itr2 : y) {
                int r2 = root(itr2);
                if (r1 != r2) {
                    mp[{r1, r2}] = true;
                }
            }
        }

        for (auto xx : fact[i]) {
            int rx = root(xx);
            for (auto yy : y) {
                int ry = root(yy);
                if (rx != ry) {
                    mp[{rx, ry}] = true;
                }
            }
        }
    }
    
    while (q--) {
        int s, t;
        cin >> s >> t;

        int answer = 2;
        if (root(fact[s].back()) == root(fact[t].back())) {
            answer = 0;
        }

        if (answer == 2) {
            if (a[s] % 2 && a[t] % 2) {
                int r1 = root(fact[s].back()), r2 = root(fact[t].back());
                if (mp.find({r1, r2}) != mp.end() || mp.find({r2, r1}) != mp.end()) {
                    answer = 1;
                }
            } else {
                answer = 1;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
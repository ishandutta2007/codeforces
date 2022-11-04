#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = 998244353;

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

using namespace std;

struct DSU {
    vector <int> par, sz;
    int n;

    inline void init(int _n) {
        n = _n;
        par.resize(n + 1), sz.resize(n + 1, 1);
    }

    int root(int x) {
        if(par[x] == 0)
            return x;
        return par[x] = root(par[x]);
    }

    inline void join(int x, int y) {
        x = root(x), y = root(y);
        if(x != y) {
            sz[y] += sz[x];
            par[x] = y;
        }
    }
};

inline string get(vector < pair <int, int> > &a) {
    if(a.size() == 0) {
        return "";
    }
    cout << "Q " << a.size() << " ";
    for(auto it : a) {
        cout << it.first << " " << it.second << " ";
    }
    cout << endl;

    string ans;
    cin >> ans;

    return ans;
}

inline vector <bool> ask(vector <int> &pos) {
    vector < pair <int, int> > a, b;
    int i;

    for(i = 0; i + 1 < pos.size(); i += 2) {
        a.push_back({pos[i], pos[i + 1]});
        if(i + 2 < pos.size()) {
            b.push_back({pos[i + 1], pos[i + 2]});
        }
    }

    string sa, sb;
    sa = get(a), sb = get(b);

    vector <bool> ans(pos.size());
    for(i = 0; i < sa.size(); i++) {
        ans[2 * i] = sa[i] - '0';
        if(i < sb.size()) {
            ans[2 * i + 1] = sb[i] - '0';
        }
    }

    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, t, i;
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {

        cin >> n;

        vector <int> pos(n);
        iota(pos.begin(), pos.end(), 1);

        vector <bool> eq = ask(pos);
        DSU dsu; dsu.init(n);

        for(i = 1; i < n; i++) {
            if(eq[i - 1]) {
                dsu.join(i, i + 1);
            }
        }

        pos.clear(), i = 1;
        while(i <= n) {
            int j = i;
            while(j <= n && eq[j - 1]) {
                j++;
            }
            pos.push_back(i);
            i = j + 1;
        }

        vector <int> pos1, pos2;
        for(i = 0; i < pos.size(); i += 2) {
            pos1.push_back(pos[i]);
            if(i + 1 < pos.size()) {
                pos2.push_back(pos[i + 1]);
            }
        }

        vector <bool> eq1 = ask(pos1);
        vector <bool> eq2 = ask(pos2);

        eq.clear(); eq.resize(max(0, (int) pos.size() - 2));
        for(i = 0; i < eq1.size(); i++) {
            eq[2 * i] = eq1[i];
            if(i < eq2.size()) {
                eq[2 * i + 1] = eq2[i];
            }
        }

        int p = 0;
        for(i = 0; i < eq.size(); i++) {
            p = max(p, i + 1);
            while(p < eq.size() && eq[p] == 1) {
                p++;
            }

            if(eq[i]) {
                dsu.join(pos[i], pos[i + 2]);
            }
            else {
                if(p < eq.size()) {
                    dsu.join(pos[i], pos[p + 2]);
                }
            }
        }

        vector <bool> vis(n + 1);
        vector < vector <int> > sol(3);
        int id = -1;

        for(i = 1; i <= n; i++) {
            int cur = dsu.root(i);
            if(vis[cur] == 0) {
                vis[cur] = 1, id++;
                for(int j = 1; j <= n; j++) {
                    if(dsu.root(j) == cur) {
                        sol[id].push_back(j);
                    }
                }
            }
        }

        cout << "A " << sol[0].size() << " " << sol[1].size() << " " << sol[2].size() << "\n";
        for(auto it : sol) {
            for(auto itr : it) {
                cout << itr << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
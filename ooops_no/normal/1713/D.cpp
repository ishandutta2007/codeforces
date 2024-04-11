#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

int ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int res;
    cin >> res;
    return res;
}

void answer(int a) {
    cout << "! " << a << endl;
}

struct game {
    int a, b, res;
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<game> g;
        for (int i = 1; i <= (1 << n); i += 2) {
            g.pb({i, i + 1, 0});
        }
        while (g.size() > 1) {
            vector<game> g_nw;
            for (int i = 0; i + 1 < g.size(); i += 2) {
                int u = 0, v = 0, good = 0;
                if (g[i].res != 0) {
                    u = g[i].res;
                    if (g[i + 1].res != 0) {
                        v = g[i + 1].res;
                    } else if (ask(g[i + 1].a, g[i + 1].b) == 1) {
                        v = g[i + 1].a;
                    } else {
                        v = g[i + 1].b;
                    }
                } else if (g[i + 1].res != 0) {
                    v = g[i + 1].res;
                    if (g[i].res != 0) {
                        u = g[i].res;
                    } else if (ask(g[i].a, g[i].b) == 1) {
                        u = g[i].a;
                    } else {
                        u = g[i].b;
                    }
                } else {
                    int res = ask(g[i].a, g[i + 1].a);
                    if (res == 1) {
                        u = g[i].a, v = g[i + 1].b;
                        if (ask(u, v) == 1) {
                            good = u;
                        } else {
                            good = v;
                        }
                    } else if (res == 2) {
                        u = g[i].b, v = g[i + 1].a;
                        if (ask(u, v) == 1) {
                            good = u;
                        } else {
                            good = v;
                        }
                    } else {
                        if (ask(g[i].b, g[i + 1].b) == 1) {
                            u = g[i].b, v = g[i + 1].b, good = g[i].b;
                        } else {
                            u = g[i].b, v = g[i + 1].b, good = g[i + 1].b;
                        }
                    }
                }
                g_nw.pb({u, v, good});
            }
            g = g_nw;
        }
        if (g[0].res != 0) {
            answer(g[0].res);
        } else if (ask(g[0].a, g[0].b) == 1) {
            answer(g[0].a);
        } else {
            answer(g[0].b);
        }
    }
    return 0;
}
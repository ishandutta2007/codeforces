#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 1005;

int t;
vector<int> mem[MAXN];

int tot = 0;

vector<int> get(int v) {
    if (szof(mem[v])) {
        return mem[v];
    }
    ++tot;
    assert(tot <= 16);
    cout << "? " << v + 1 << endl;
    int k;
    scanf("%d", &k);
    if (k == 0) {
        exit(0);
    }
    vector<int> ret;
    for (int i = 0; i < k; ++i) {
        int num;
        scanf("%d", &num);
        --num;
        ret.puba(num);
    }
    random_shuffle(bend(ret));
    mem[v] = ret;
    return ret;
}

void solve() {
    tot = 0;
    for (int i = 0; i < MAXN; ++i) {
        mem[i].clear();
    }
    int h;
    scanf("%d", &h);

    int start = 0;
    vector<int> init = get(start);
    if (szof(init) == 2) {
        cout << "! " << start + 1 << endl;
        return;
    }
    vector<int> path = {start};
    if (szof(init) == 3) {
        int prev = start;
        int now = init[0];
        while (true) {
            vector<int> tmp = get(now);
            if (szof(tmp) == 2) {
                cout << "! " << now + 1 << endl;
                return;
            }
            path.puba(now);
            if (szof(tmp) == 1) {
                break;
            }
            int next = tmp[0];
            if (next == prev) {
                next = tmp[1];
            }
            prev = now;
            now = next;
        }
        prev = start;
        now = init[1];
        reverse(bend(path));
        while (true) {
            vector<int> tmp = get(now);
            if (szof(tmp) == 2) {
                cout << "! " << now + 1 << endl;
                return;
            }
            path.puba(now);
            if (szof(tmp) == 1) {
                break;
            }
            int next = tmp[0];
            if (next == prev) {
                next = tmp[1];
            }
            prev = now;
            now = next;
        }
    }
    while (true) {
        /*
        cerr << "current path" << endl;
        for (int v : path) {
            cerr << v + 1 << " ";
        }
        cerr << endl;*/
        int nd = h - 1 - szof(path) / 2;
        if (nd == 1) {
            int pos = szof(path) / 2;
            vector<int> tmp = get(path[pos]);
            if (szof(path) == 1) {
                cout << "! " << tmp[0] + 1 << endl;
                return;
            }
            for (int v : tmp) {
                if (v != path[pos - 1] && v != path[pos + 1]) {
                    cout << "! " << v + 1 << endl;
                    return;
                }
            }
            assert(false);
        }
        if (nd == 2) {
            int pos = szof(path) / 2;
            vector<int> tmp = get(path[pos]);
            int par = -1;
            if (szof(path) == 1) {
                par = tmp[0];
            } else {
                for (int v : tmp) {
                    if (v != path[pos - 1] && v != path[pos + 1]) {
                        par = v;
                        break;
                    }
                }
            }
            assert(par != -1);
            tmp = get(par);
            vector<int> rest;
            for (int v : tmp) {
                if (v != path[pos]) {
                    rest.puba(v);
                }
            }
            if (szof(get(rest[0])) == 2) {
                cout << "! " << rest[0] + 1 << endl;
            } else {
                cout << "! " << rest[1] + 1 << endl;
            }
            return;
        }

        if (nd == 3) {
            int pos = szof(path) / 2;
            vector<int> tmp = get(path[pos]);
            int par = -1;
            if (szof(path) == 1) {
                par = tmp[0];
            } else {
                for (int v : tmp) {
                    if (v != path[pos - 1] && v != path[pos + 1]) {
                        par = v;
                        break;
                    }
                }
            }
            assert(par != -1);
            
            tmp = get(par);

            int c = 1;
            for (int v : tmp) {
                if (v != path[pos]) {
                    ++c;
                    vector<int> tmp2 = get(v);
                    for (int v2 : tmp2) {
                        if (v2 != par) {
                            ++c;
                            if (c == 7) {
                                cout << "! " << v2 + 1 << endl;
                                return;
                            }
                            if (szof(get(v2)) == 2) {
                                cout << "! " << v2 + 1 << endl;
                                return;
                            }
                        }
                    }
                }
            }
            assert(false);
        }
        
        int pos = szof(path) / 2;
        vector<int> tmp = get(path[pos]);
        int par = -1;
        if (szof(path) == 1) {
            par = tmp[0];
        } else {
            for (int v : tmp) {
                if (v != path[pos - 1] && v != path[pos + 1]) {
                    par = v;
                    break;
                }
            }
        }
        assert(par != -1);
        
        int now = par;

        int prev = path[pos];
        path.resize(pos + 1);
        while (true) {
            tmp = get(now);
            if (szof(tmp) == 2) {
                cout << "! " << now + 1 << endl;
                return;
            }
            path.puba(now);
            if (szof(tmp) == 1) {
                break;
            }
            int next = tmp[0];
            if (next == prev) {
                next = tmp[1];
            }
            prev = now;
            now = next;
        }
    }

}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        solve();
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}
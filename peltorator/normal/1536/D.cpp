#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 7;

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    vector<int> b(n);
    for (int &val : b) {
        cin >> val;
    }
    vector<int> prevind(1, -1), nextind(1, -1), val(1, b[0]);
    int curind = 0;
    for (int i = 1; i < n; i++) {
        int newval = b[i];
        int leftbound = -INF, rightbound = INF;
        if (nextind[curind] != -1) {
            rightbound = val[nextind[curind]];
        }
        if (prevind[curind] != -1) {
            leftbound = val[prevind[curind]];
        }
        if (newval < leftbound || newval > rightbound) {
            cout << "NO\n";
            return 0;
        }
        if (newval == val[curind]) {
            continue;
        }
        if (newval == leftbound) {
            curind = prevind[curind];
            continue;
        }
        if (newval == rightbound) {
            curind = nextind[curind];
            continue;
        }
        if (newval < val[curind]) {
            int oldprev = prevind[curind];
            int newind = sz(val);
            val.push_back(newval);
            nextind.push_back(0);
            prevind.push_back(0);
            prevind[curind] = newind;
            nextind[newind] = curind;
            prevind[newind] = oldprev;
            if (oldprev != -1) {
                nextind[oldprev] = newind;
            }
            curind = newind;
        } else {
            int oldnext = nextind[curind];
            int newind = sz(val);
            val.push_back(newval);
            prevind.push_back(0);
            nextind.push_back(0);
            nextind[curind] = newind;
            prevind[newind] = curind;
            nextind[newind] = oldnext;
            if (oldnext != -1) {
                prevind[oldnext] = newind;
            }
            curind = newind;
        }
    }
    cout << "YES\n";
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
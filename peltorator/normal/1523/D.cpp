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
//mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    int m, p;
    cin >> m >> p;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    int ans = 0;
    string s = "";
    for (int i = 0; i < m; i++) {
        s.push_back('0');
    }
    int e = (n + 1) / 2;
    string qqq = s;
    for (int _ = 0; _ < 50; _++) {
        int x = rnd() % n;
        vector<int> inds(m, -1);
        int curind = 0;
        vector<int> bits;
        for (int i = 0; i < m; i++) {
            if (g[x][i] == '1') {
                inds[i] = curind++;
                bits.push_back(i);
            }
        }
        int B = (1 << curind);
        vector<int> sm(B, 0);
        for (int i = 0; i < n; i++) {
            int ms = 0;
            for (int j = 0; j < curind; j++) {
                if (g[i][bits[j]] == '1') {
                    ms |= (1 << j);
                }
            }
            sm[ms]++;
        }
        for (int len = 1; len < B; len *= 2) {
            for (int i = 0; i < B; i++) {
                if ((i & len) == 0) {
                    sm[i] += sm[i ^ len];
                }
            }
        }
        for (int i = 0; i < B; i++) {
            int curval = __builtin_popcount(i);
            if (sm[i] >= e && curval > ans) {
                ans = curval;
                s = qqq;
                for (int j = 0; j < curind; j++) {
                    if ((i >> j) & 1) {
                        s[bits[j]] = '1';
                    }
                }
            }
        }
    }
    cout << s << endl;
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
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
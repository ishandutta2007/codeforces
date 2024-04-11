#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
    int ca, cb, cab, cba;
    cin >> ca >> cb >> cab >> cba;
    string s;
    cin >> s;
    int n = sz(s);
    int cnta = 0, cntb = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            cnta++;
        } else {
            cntb++;
        }
    }
    if (cnta != ca + cab + cba) {
        cout << "NO\n";
        return 0;
    }
    if (cntb != cb + cab + cba) {
        cout << "NO\n";
        return 0;
    }
    vector<int> ab, aba, ba, bab;
    int l = 0;
    for (int i = 1; i <= n; i++) {
        if (i == n || s[i] == s[i - 1]) {
            if (i - l == 1) {
                if (s[l] == 'A') {
                    if (ca == 0) {
                        cout << "NO\n";
                        return 0;
                    }
                    ca--;
                } else {
                    if (cb == 0) {
                        cout << "NO\n";
                        return 0;
                    }
                    cb--;
                }
            } else if ((i - l) % 2 == 0) {
                if (s[l] == 'A') {
                    ab.push_back(i - l);
                } else {
                    ba.push_back(i - l);
                }
            } else {
                if (s[l] == 'A') {
                    aba.push_back(i - l);
                } else {
                    bab.push_back(i - l);
                }
            }
            l = i;
        }
    }
    sort(ab.rbegin(), ab.rend());
    sort(ba.rbegin(), ba.rend());
    sort(aba.rbegin(), aba.rend());
    sort(bab.rbegin(), bab.rend());
    vector<vector<int>> xy = {ab, ba}, xyx = {aba, bab};
    vector<int> c = {cab, cba};
    for (int tp = 0; tp < 2; tp++) {
        while (!xy[tp].empty() && c[tp] != 0) {
            while (xy[tp].back() != 0 && c[tp] != 0) {
                xy[tp].back() -= 2;
                c[tp]--;
            }
            if (xy[tp].back() == 0) {
                xy[tp].pop_back();
            }
        }
    }
    for (int tp = 0; tp < 2; tp++) {
        for (int ntp = 0; ntp < 2; ntp++) {
            while (!xyx[ntp].empty() && c[tp] != 0) {
                while (xyx[ntp].back() != 1 && c[tp] != 0) {
                    xyx[ntp].back() -= 2;
                    c[tp]--;
                }
                if (xyx[ntp].back() == 1) {
                    xyx[ntp].pop_back();
                }
            }
        }
    }
    for (int tp = 0; tp < 2; tp++) {
        int ntp = (tp ^ 1);
        while (!xy[ntp].empty() && c[tp] != 0) {
            xy[ntp].back()--;
            while (xy[ntp].back() != 1 && c[tp] != 0) {
                xy[ntp].back() -= 2;
                c[tp]--;
            }
            if (xy[ntp].back() == 1) {
                xy[ntp].pop_back();
            }
        }
    }
    if (c[0] == 0 && c[1] == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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
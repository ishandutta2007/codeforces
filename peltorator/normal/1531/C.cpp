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

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    if (n == 2) {
        cout << "-1\n";
        return 0;
    }
    int k = 1;
    while (k * k < n) {
        k++;
    }
    vector<string> s;
    if (k * k == n + 2) {
        string t = "";
        k++;
        for (int i = 0; i < k; i++) {
            t.push_back('o');
        }
        s.assign(k, t);
        s[0][k - 1] = '.';
        for (int i = 1; i < k - 1; i++) {
            s[0][i] = '.';
            s[i][k - 1] = '.';
        }
        s[1][k - 3] = s[1][k - 2] = s[2][k - 3] = s[2][k - 2] = '.';
    } else {
        string t = "";
        for (int i = 0; i < k; i++) {
            t.push_back('o');
        }
        s.assign(k, t);
        n = k * k - n;
        if (n > 0) {
            s[0][k - 1] = '.';
            n--;
        }
        if (n % 2 == 1) {
            s[1][k - 2] = '.';
            n--;
        }
        int x = 1;
        while (n) {
            s[0][k - x - 1] = '.';
            s[x][k - 1] = '.';
            n -= 2;
            x++;
        }
    }
    cout << sz(s) << endl;
    for (int i = 0; i < sz(s); i++) {
        cout << s[i] << '\n';
    }
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
#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
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

const int N = 505;

string s[N];
int n, m;

void print() {
    for (int i = 0; i < n; i++) {
        cout << s[i] << '\n';
    }
}

int solve() {
    if (!(cin >> n)) {
        return 1;
    }
    cin >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    if (m == 1 || n == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                s[i][j] = 'X';
            }
        }
        print();
        return 0;
    }
    int st = 1;
    if (n % 3 == 1) {
        st = 0;
    }
    for (int i = st; i < n; i += 3) {
        for (int j = 0; j < m; j++) {
            s[i][j] = 'X';
        }
    }
    for (int i = st + 1; i + 1 < n; i += 3) {
        if (s[i][1] == 'X' || s[i + 1][1] == 'X') {
            s[i][1] = 'X';
            s[i + 1][1] = 'X';
        } else {
            s[i][0] = 'X';
            s[i + 1][0] = 'X';
        }
    }
    print();
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
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
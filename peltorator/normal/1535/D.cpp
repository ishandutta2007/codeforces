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

string s;
int n;

const int N = 1012345;

int tree[N];

void relax(int i) {
    if (i >= n) {
        if (s[i] == '?') {
            tree[i] = 2;
        } else {
            tree[i] = 1;
        }
    } else {
        if (s[i] == '?') {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        } else if (s[i] == '1') {
            tree[i] = tree[2 * i];
        } else {
            tree[i] = tree[2 * i + 1];
        }
    }
}

int solve() {
    int k;
    cin >> k;
    cin >> s;
    n = (sz(s) + 1) / 2;
    reverse(s.begin(), s.end());
    s = "." + s;
    for (int i = 2 * n - 1; i > 0; i--) {
        relax(i);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int pos;
        char c;
        cin >> pos >> c;
        pos = 2 * n - pos;
        s[pos] = c;
        while (pos) {
            relax(pos);
            pos /= 2;
        }
        cout << tree[1] << '\n';
    }
    return 1;
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
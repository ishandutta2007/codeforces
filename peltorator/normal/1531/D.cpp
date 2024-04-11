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

const int T = (1 << 21);

string col[2][T];
int state[2][T];

string s[T];

void pull(int v) {
    for (int i = 0; i < 2; i++) {
        state[i][v] = state[state[i][2 * v]][2 * v + 1];
        col[i][v] = col[state[i][2 * v]][2 * v + 1];
        if (col[i][v] == "") {
            col[i][v] = col[i][2 * v];
        }
    }
}

void buildPoint(int v, int l) {
    if (s[l] == "lock") {
        col[1][v] = col[0][v] = "";
        state[1][v] = state[0][v] = 1;
    } else if (s[l] == "unlock") {
        col[1][v] = col[0][v] = "";
        state[1][v] = state[0][v] = 0;
    } else {
        col[1][v] = "";
        col[0][v] = s[l];
        state[1][v] = 1;
        state[0][v] = 0;
    }
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        buildPoint(v, l);
        return;
    }
    int mid = (r + l) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid, r);
    pull(v);
}

void update(int v, int l, int r, int qi) {
    if (l + 1 == r) {
        buildPoint(v, l);
        return;
    }
    int mid = (r + l) / 2;
    if (qi < mid) {
        update(2 * v, l, mid, qi);
    } else {
        update(2 * v + 1, mid, r, qi);
    }
    pull(v);
}

string find() {
    string ans = col[0][1];
    if (ans == "") {
        ans = "blue";
    }
    return ans;
}

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    build(1, 0, n);
    int q;
    cin >> q;
    cout << find() << '\n';
    while (q--) {
        int i;
        cin >> i;
        i--;
        string x;
        cin >> x;
        s[i] = x;
        update(1, 0, n, i);
        cout << find() << '\n';
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
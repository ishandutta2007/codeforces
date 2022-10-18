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

vector<int> vec = {-1, -1, 0, 0};

int ask(vector<int> a, vector<int> b) {
#ifdef ONPC
    int l = 0, r = 0;
    for (int i : a) {
        l += vec[i - 1];
    }
    for (int i : b) {
        r += vec[i - 1];
    }
    return l * r;
#else
    cout << "? " << sz(a) << ' ' << sz(b) << '\n';
    for (int i : a) {
        cout << i << ' ';
    }
    cout << '\n';
    for (int i : b) {
        cout << i << ' ';
    }
    cout << endl;
    int x;
    cin >> x;
    return x;
#endif
}

int solve() {
    int n;
#ifdef ONPC
    n = sz(vec);
#else
    if (!(cin >> n)) {
        return 1;
    }
#endif
    int i = 2;
    vector<int> v;
    while (true) {
        v.push_back(i - 1);
        int x = ask({i}, v);
        if (x != 0) {
            break;
        }
        i++;
    }
    int l = 0, r = i - 1;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        vector<int> ve;
        for (int j = 1; j <= mid; j++) {
            ve.push_back(j);
        }
        int x = ask({i}, ve);
        if (x != 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    vector<int> ans;
    for (int j = 1; j < i; j++) {
        if (j != r) {
            ans.push_back(j);
        }
    }
    for (int j = i + 1; j <= n; j++) {
        if (ask({i}, {j}) == 0) {
            ans.push_back(j);
        }
    }
    cout << "! " << sz(ans) << ' ';
    for (int j : ans) {
        cout << j << ' ';
    }
    cout << endl;
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
#ifdef ONPC
    TET = 1;
#else
    cin >> TET;
#endif
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
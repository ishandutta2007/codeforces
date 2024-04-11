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
    vector<int> a(n);
    for (int &val : a) {
        cin >> val;
    }
    sort(a.begin(), a.end());
    if (a[0] < 0) {
        cout << "NO\n";
        return 0;
    }
    queue<int> que;
    for (int val : a) {
        que.push(val);
    }
    set<int> q;
    vector<int> curarr;
    while (!que.empty() && sz(q) < 305) {
        int newval = que.front();
        que.pop();
        q.insert(newval);
        for (int oldval : curarr) {
            int diff = abs(newval - oldval);
            if (!q.count(diff)) {
                q.insert(diff);
                que.push(diff);
            }
        }
        curarr.push_back(newval);
    }
    if (sz(q) <= 300) {
        cout << "YES\n";
        cout << sz(q) << '\n';
        for (int val : curarr) {
            cout << val << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }
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
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

int solve2() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    vector<int> a(n);
    for (int &val : a) {
        cin >> val;
    }
    sort(a.begin(), a.end());
    deque<int> q;
    q.push_back(a.back());
    int l = 0, r = n - 2;
    while (l <= r) {
        q.push_back(a[l]);
        l++;
        if (l <= r) {
            q.push_front(a[l]);
            l++;
        }
        if (l <= r) {
            q.push_back(a[r]);
            r--;
        }
        if (l <= r) {
            q.push_front(a[r]);
            r--;
        }
    }
    bool ok = true;
    a.clear();
    for (int val : q) {
        a.push_back(val);
    }
    for (int i = 0; i < n; i++) {
        if (!(a[i] != a[(i - 1 + n) % n] && a[i] != a[(i + 1) % n] && (a[i] < a[(i - 1 + n) % n]) == (a[i] < a[(i + 1) % n]))) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int val : a) {
        cout << val << ' ';
    }
    cout << '\n';
    return 0;
}

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &val : a) {
        cin >> val;
    }
    if (n % 2 != 0) {
        cout << "NO\n";
        return 0;
    }
    sort(a.begin(), a.end());
    vector<int> b;
    int l = n / 2 - 1, r = n - 1;
    for (int i = 0; i < n / 2; i++) {
        b.push_back(a[r--]);
        b.push_back(a[l--]);
    }
    bool ok = true;
    a = b;
    for (int i = 0; i < n; i++) {
        if (!(a[i] != a[(i - 1 + n) % n] && a[i] != a[(i + 1) % n] && (a[i] < a[(i - 1 + n) % n]) == (a[i] < a[(i + 1) % n]))) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int val : a) {
        cout << val << ' ';
    }
    cout << '\n';
    return 0;

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
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

vector<int> p;

vector<pair<int, int>> q;

void f(int x, int y) {
    q.push_back({x, y});
    swap(p[x], p[y]);
}

void merge_cycles(vector<int> x, vector<int> y) {
    for (int i = 0; i < sz(x); i++) {
        f(x[i], y[0]);
  //      q.push_back({x[i], y[0]});
    }
    for (int j = 1; j < sz(y); j++) {
        f(x[0], y[j]);
//        q.push_back({x[0], y[j]});
    }
    f(x[0], y[0]);
  //  q.push_back({x[0], y[0]});
}

void do_cycle(vector<int> x) {
    int n = sz(x);
    for (int i = 0; i < n - 2; i++) {
        f(x[i], x[n - 1]);
//        q.push_back({x[i], x[n - 1]});
    }
    f(x[0], x[n - 2]);
    f(x[n - 2], x[n - 1]);
    f(x[0], x[n - 1]);
//    q.push_back({x[0], x[n - 2]});
  //  q.push_back({x[n - 2], x[n - 1]});
    //q.push_back({x[0], x[n - 1]});
}

void do_pair(int a, int b) {
    int c = 0;
    while (c == a || c == b) {
        c++;
    }
    f(a, c);
    f(b, c);
    f(a, c);
//    q.push_back({a, c});
  //  q.push_back({b, c});
    //q.push_back({a, c});
}

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    p.clear();
    p.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    q.clear();

    vector<vector<int>> cycles;
    vector<int> used(n, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i] && p[i] != i) {
            vector<int> cur;
            cur.push_back(i);
            used[i] = true;
            int j = p[i];
            while (j != i) {
                used[j] = true;
                cur.push_back(j);
                j = p[j];
            }
            cycles.push_back(cur);
        }
    }
    for (int i = 0; i + 1 < sz(cycles); i += 2) {
        merge_cycles(cycles[i], cycles[i + 1]);
    }
    if (sz(cycles) % 2 == 1) {
        vector<int> c = cycles.back();
        if (sz(c) > 2) {
            do_cycle(c);
        } else {
            do_pair(c[0], c[1]);
        }
    }
    assert(sz(q) <= n + 1);
    for (int i = 0; i < n; i++) {
        assert(p[i] == i);
    }
    cout << sz(q) << '\n';
    for (int i = 0; i < sz(q); i++) {
        cout << q[i].first + 1 << ' ' << q[i].second + 1 << '\n';
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
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
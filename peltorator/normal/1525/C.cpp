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
    int m;
    cin >> m;
    vector<pair<int, pair<char, int>>> x(n);
    for (int i = 0; i < n; i++) {
        x[i].second.second = i;
        cin >> x[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i].second.first;
    }
    sort(x.begin(), x.end());

    vector<int> ans(n, -1);
    vector<pair<int, int>> stack[2];
    for (auto it : x) {
        int pos = it.first;
        int ind = it.second.second;
        char dir = it.second.first;
        if (dir == 'R') {
            stack[pos % 2].push_back({pos, ind});
        } else {
            if (!stack[pos % 2].empty()) {
                int ind2 = stack[pos % 2].back().second;
                int pos2 = stack[pos % 2].back().first;
                ans[ind] = ans[ind2] = (pos - pos2) / 2;
                stack[pos % 2].pop_back();
            } else {
                stack[pos % 2].push_back({-pos, ind});
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        while (sz(stack[i]) >= 2) {
            auto [pos, ind] = stack[i].back();
            stack[i].pop_back();
            auto [pos2, ind2] = stack[i].back();
            stack[i].pop_back();
            ans[ind] = ans[ind2] = m - (pos + pos2) / 2;
        }
    }

    for (int i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
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
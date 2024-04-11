#include <bits/stdc++.h>
using namespace std;
using lint = long long;
// #define TESTCASE
int solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #ifdef TESTCASE
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    #else
    solve();
    #endif
}


pair<int, int> query(vector<int> A) {
    cout << "? ";
    for (auto i : A) {
        cout << i + 1 << " ";
    }
    cout << endl;
    pair<int, int> res;
    cin >> res.first >> res.second;
    res.first--;
    return res;
}

int solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << "! " << 1 << endl;
        return 0;
    }

    vector<int> a(n), b(n, -1);
    iota(begin(a), end(a), 0);
    int ptr = k;
    
    vector<int> guess(n);
    iota(begin(guess), end(guess), 0);
    while (ptr <= guess.size()) {
        auto cur = query(vector<int>(begin(a), begin(a) + k));
        if (b[cur.first] != -1) {
            break;
        }
        
        b[cur.first] = cur.second;
        if (ptr == n) {
            break;
        }
        for (int j = 0; j < k; j++) {
            if (a[j] == cur.first) {
                a[j] = guess[ptr];
            }
        }
        ptr++;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << "\n";

    vector<pair<int, int>> sorted;
    
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            sorted.emplace_back(b[i], i);
        }
    }

    sort(begin(sorted), end(sorted));
    if (sorted.size() >= k) {
        vector<int> q;
        for (int i = 0; i < k; i++) {
            q.emplace_back(sorted[i].second);
        }
        pair<int, int> ans = query(q);
        int m;
        for (int i = 0; i < n; i++) {
            if (ans.first == sorted[i].second) {
                m = i + 1;
            }
        }
        cout << "! " << m << endl;
        return 0;
    }
    
    vector<int> low, high;
    int k1 = sorted[0].second, k2 = sorted[1].second;
    vector<int> unknown;

    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            unknown.emplace_back(i);
        }
    }

    for (int e = 0; e < unknown.size(); e++) {
        vector<int> q; q.emplace_back(k1), q.emplace_back(k2);
        for (int i = 0; i < unknown.size(); i++) if (i != e) {
            q.emplace_back(unknown[i]);
        }
        pair<int, int> g = query(q);
        if (g.first == k1) {
            high.emplace_back(unknown[e]);
        } else if (g.first == k2) {
            low.emplace_back(unknown[e]);
        } else {
            assert(0);
        }
    }
    cout << "! " << (low.size() + 1) << endl;

}
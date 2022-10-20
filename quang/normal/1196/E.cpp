#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int DELTA = 1000000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int b, w;
        cin >> b >> w;
        pair<int, int> root(DELTA, DELTA);
        if (w < b) {
            swap(w, b);
            root.first++;
        }
        vector<pair<int, int>> res;
        res.reserve(w + b);
        pair<int, int> cur = root;
        for (int i = 0; i < b; i++) {
            res.push_back(cur);
            cur.first++;
            res.push_back(cur);
            cur.first++;
        }
        if (w > b) {
            w--;
            res.push_back(cur);
        }
        w -= b;
        if (b * 2 < w) {
            cout << "NO\n";
        } else {
            cur = root;
            cur.first++;
            cur.second--;
            for (int i = 0; i < b && w > 0; i++, w--) {
                res.push_back(cur);
                cur.first += 2;
            }
            cur = root;
            cur.first++;
            cur.second++;
            for (int i = 0; i < b && w > 0; i++, w--) {
                res.push_back(cur);
                cur.first += 2;
            }
            cout << "YES\n";
            for (auto u : res) {
                cout << u.first << ' ' << u.second << '\n';
            }
        }
    }
    return 0;
}
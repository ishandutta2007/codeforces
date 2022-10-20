#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
char s[N];
int used[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> (s + 1);
    n = strlen(s + 1);
    vector<vector<int>> res;
    while (1) {
        vector<int> cur;
        int l = 1, r = n;
        while (l < r) {
            while (l <= n && (used[l] || s[l] == ')')) l++;
            while (r >= 1 && (used[r] || s[r] == '(')) r--;
            if (l >= r) break;
            cur.push_back(l);
            cur.push_back(r);
            used[l] = 1;
            used[r] = 1;
        }
        if (cur.empty()) break;
        sort(cur.begin(), cur.end());
        res.push_back(cur);
    }
    cout << res.size() << '\n';
    for (auto u : res) {
        cout << u.size() << '\n';
        for (int v : u) cout << v << ' ';
            cout << '\n';
    }
    return 0;
}
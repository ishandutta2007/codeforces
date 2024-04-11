#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> res;
    while (1) {
        pair<int, int> now(0, 0);
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i] == a[j] + 1) {
                    now = {i, j};
                }
            }
        }
        if (now.first == 0) break;
        int pos = now.second;
        while (pos > 1 && a[pos - 1] == a[pos] - 1) pos--;
        vector<int> cur;
        if (now.first > 1) cur.push_back(now.first - 1);
        cur.push_back(pos - now.first);
        cur.push_back(now.second - pos + 1); 
        if (now.second < n) cur.push_back(n - now.second);
        res.push_back(cur);


        vector<vector<int>> aa;
        int it = 1;
        for (int u : cur) {
            vector<int> foo;
            for (int i = 0; i < u; i++, it++) {
                foo.push_back(a[it]);
            }
            aa.push_back(foo);
        }

        reverse(aa.begin(), aa.end());
        it = 1;
        for (auto u : aa) {
            for (int i = 0; i < u.size(); i++, it++) {
                a[it] = u[i];
            }
        }
    }   
    cout << res.size() << '\n';
    for (auto u : res) {
        cout << u.size() << ' ';
        for (int v : u) cout << v << ' ';
            cout << '\n';
    }
    return 0;
}
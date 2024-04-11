#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    map<char, pair<int, int>> move;
    move['L'] = {-1, 0};
    move['R'] = {1, 0};
    move['U'] = {0, 1};
    move['D'] = {0, -1};
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a;
        cin >> a;
        map<pair<int, int>, int> pos;
        pair<int, int> cur = {0, 0};
        int ans = n + n;
        int x, y;
        x = y = -1;
        pos[{0, 0}] = -1;
        for (int i = 0; i < n; i++) {
            cur.first += move[a[i]].first;
            cur.second += move[a[i]].second;
            if (pos.count(cur)) {
                if (ans > i - pos[cur] + 1) {
                    x = pos[cur] + 1;
                    y = i;
                }
                ans = min(ans, i - pos[cur] + 1);
            }
            pos[cur] = i;
        }
        if (ans == n + n) {
            cout << -1 << "\n";
        } else {
            cout << x + 1 << " " << y + 1 << "\n";
        }
    }


}
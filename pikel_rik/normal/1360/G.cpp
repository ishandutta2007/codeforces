#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 998244353;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        for (int j = 0; j < m; j++) {
            q.push({0, j});
        }

        vector<vector<int>> ans(n, vector<int> (m));

        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a; j++) {
                auto p = q.top();
                q.pop();
                p.first += 1;
                ans[i][p.second] = 1;
                q.push(p);
            }
        }

        while (!q.empty()) {
            auto p = q.top();
            q.pop();

            if (p.first != b) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ans[i][j];
                }
                cout << "\n";
            }
        }
        else cout << "NO\n";
    }
    return 0;
}
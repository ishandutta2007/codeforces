#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vint;
typedef pair<int, int> pint;
const double PI = 3.14159265358979323846;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

int n, m;
int d[110][110];
int p[1100000];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)d[i][j + 1] = s[j] == '1' ? 1 : 1145141919;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)cin >> p[i];
    vint ans;
    ans.push_back(p[0]);
    int cur = 0;
    while (cur != m - 1) {
        for (int i = min(m - 1, cur + 110); i > cur; i--)
            if (i - cur == d[p[cur]][p[i]] && p[i] != p[cur]) {
                cur = i, ans.push_back(p[cur]);
                break;
            }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)cout << ans[i] << " ";
    cout << endl;

}
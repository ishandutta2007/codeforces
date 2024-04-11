#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vvi ans(k);
    int cur = 0;

    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            for (int j = 1; j <= m; j++) {
                ans[cur].push_back(i);
                ans[cur].push_back(j);
                if (cur != k - 1 and ans[cur].size() == 4)
                    cur += 1;
            }
        }
        else {
            for (int j = m; j >= 1; j--) {
                ans[cur].push_back(i);
                ans[cur].push_back(j);
                if (cur != k - 1 and ans[cur].size() == 4)
                    cur += 1;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << ans[i].size() / 2 << " ";
        for (int &x : ans[i])
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
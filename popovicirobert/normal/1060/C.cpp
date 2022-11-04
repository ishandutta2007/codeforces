#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXN = 2000;

ll a[MAXN + 1], b[MAXN + 1];
ll mna[MAXN + 1], mnb[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for(i = 1; i <= m; i++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    int x;
    cin >> x;
    for(int len = 1; len <= n; len++) {
        mna[len] = INF;
        for(i = len; i <= n; i++) {
            mna[len] = min(mna[len], a[i] - a[i - len]);
        }
    }
    for(int len = 1; len <= m; len++) {
        mnb[len] = INF;
        for(i = len; i <= m; i++) {
            mnb[len] = min(mnb[len], b[i] - b[i - len]);
        }
    }
    int ans = 0;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(mna[i] * mnb[j] <= x) {
                ans = max(ans, i * j);
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
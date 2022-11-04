#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5 + 5;

int v[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int ans = 10 * MAXN + 1;
    v[n + 1] = (int) 1e6;
    v[0] = 1;
    for(i = 0; i <= n; i++) {
        ans = min(ans, max(v[i] - 1, (int) 1e6 - v[i + 1]));
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
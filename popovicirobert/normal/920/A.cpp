#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 113

using namespace std;

const int MAXN = (int) 1e5;

int x[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k, t;
    ios::sync_with_stdio(false);
    cin >> t;
    while(t > 0) {
        t--;
        cin >> n >> k;
        int ans = 0;
        for(i = 1; i <= k; i++) {
            cin >> x[i];
        }
        ans = max(ans, x[1]);
        ans = max(ans, n - x[k] + 1);
        for(i = 2; i <= k; i++) {
            ans = max(ans, (x[i] - x[i - 1] + 2) / 2);
        }
        cout << ans << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}
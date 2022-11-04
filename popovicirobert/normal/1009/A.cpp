#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

int c[1001], a[1001];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(i = 1; i <= m; i++) {
        cin >> a[i];
    }
    int ans = 0, pos = 1;
    for(i = 1; i <= n; i++) {
        if(pos <= m && a[pos] >= c[i]) {
            pos++;
            ans++;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

int a[1001], b[1001];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, k1, k2, n;
    ios::sync_with_stdio(false);
    cin >> n >> k1 >> k2;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int k = k1 + k2;
    while(k > 0) {
        k--;
        int mx = -1e9, pos;
        for(i = 1; i <= n; i++) {
            if(mx < abs(a[i] - b[i])) {
                mx = abs(a[i] - b[i]);
                pos = i;
            }
        }
        if(a[pos] > b[pos]) {
            b[pos]++;
        }
        else {
            a[pos]++;
        }
    }
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        ans += 1LL * (a[i] - b[i]) * (a[i] - b[i]);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
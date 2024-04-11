#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

ll a[100], b[100];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= m; i++) {
        cin >> b[i];
    }
    ll mn = (1LL << 60);
    for(i = 1; i <= n; i++) {
        ll mx = -(1LL << 60);
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= n; k++)
                if(k != i)
                    mx = max(mx, a[k] * b[j]);
        }
        mn = min(mx, mn);
    }
    cout << mn;
    //cin.close();
    //cout.close();
    return 0;
}
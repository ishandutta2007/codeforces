#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int i, j;
        if(k==1) {
            cout <<"YES\n";
            for(i=1;i<=n;i++) cout << i << '\n';
            continue;
        }
        if(n%2==1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(i=1;i<=n;i++) {
            for(j=0;j<=k-1;j++) {
                cout << n * j + i << ' ';
            }
            cout << '\n';
        }
    }
}
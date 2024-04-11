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
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);
        if(a[2] == a[0] + a[1]) {
            cout << "YES\n";
        }
        else {
            if(a[0]==a[1]&&a[2]%2==0) cout <<"YES\n";
            else if(a[1]==a[2]&&a[0]%2==0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
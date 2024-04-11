#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[30];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x, n;
        cin >> x >> n;
        int d = 0;
        if(n % 4 == 0) d = 0;
        if(n % 4 == 1) d = -n;
        if(n % 4 == 2) d = 1;
        if(n % 4 == 3) d = n + 1;
        if((x + 100000000000000) % 2 == 0) cout << x + d << '\n';
        else cout << x - d << '\n';
    }
}
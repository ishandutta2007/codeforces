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
        int n, x, y;
        cin >> n >> x >> y;
        int a;
        int sum = 0;
        while(n--) {
            cin >> a;
            sum += a;
        }
        if((x+sum)%2==y%2) cout << "Alice\n";
        else cout << "Bob\n";
    }
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, n, x, y, d;
    ios::sync_with_stdio(false);
    cin >> t;
    while(t > 0) {
        t--;
        cin >> n >> x >> y >> d;
        if(abs(x - y) % d == 0) {
            cout << abs(x - y) / d << "\n";
            continue;
        }
        int ans = 2e9;
        if((n - y) % d == 0) {
            ans = min(ans, (n - x + d - 1) / d + (n - y) / d);
        }
        if((y - 1) % d == 0) {
            ans = min(ans, (x - 1 + d - 1) / d + (y - 1) / d);
        }
        if(ans == 2e9) {
            ans = -1;
        }
        cout << ans << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}
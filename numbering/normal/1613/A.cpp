#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int i, j, k;
    while(t--) {
        int x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        if(abs(p1-p2)>=10) {
            if(p1 > p2) cout << ">\n";
            else cout << "<\n";
        }
        else {
            int m = min(p1, p2);
            p1 -= m;
            p2 -= m;
            while(p1--) {
                x1 *= 10;
            }
            while(p2--) {
                x2 *= 10;
            }
            if(x1==x2) cout << "=\n";
            else if(x1>x2) cout << ">\n";
            else cout << "<\n";
        }
    }
}
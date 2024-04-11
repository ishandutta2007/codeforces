#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, x;
    ios::sync_with_stdio(false);
    cin >> t;
    while(t > 0) {
        t--;
        bool ok = 0;
        cin >> x;
        if(x == 0) {
            cout << 1 << " " << 1 << "\n";
            ok = 1;
        }
        if(x == 1) {
            cout << -1 << "\n";
            ok = 1;
        }
        for(int d = 1; d * d <= x && !ok; d++) {
            if(x % d == 0) {
                int a = d, b = x / d;
                if((a + b) % 2 == 0) {
                    int n = (a + b) / 2;
                    if(b - n > 0 && 1.0 * n / (b - n + 1) - n / (b - n) < 0) {
                        cout << n << " " << n / (b - n) << "\n";
                        ok = 1;
                        break;
                    }
                }
            }
        }
        if(!ok)
            cout << -1 << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int q;
    ios::sync_with_stdio(false);
    cin >> q;
    while(q > 0) {
        q--;
        ll n, m, k;
        cin >> n >> m >> k;
        ll mx = max(n, m);
        if(mx > k) {
            cout << -1 << "\n";
            continue;
        }
        if((n + m) & 1) {
            cout << k - 1 << "\n";
        }
        else if((k - mx) % 2 == 0) {
            cout << k << "\n";
        }
        else {
            cout << k - 2 << "\n";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}
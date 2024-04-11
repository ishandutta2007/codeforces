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
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    int mn = 1e9, mx = 0;
    for(i = 1; i <= n; i++) {
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    cout << mx - mn + 1 - n;
    //cin.close();
    //cout.close();
    return 0;
}
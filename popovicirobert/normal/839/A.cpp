#include <bits/stdc++.h>

using namespace std;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k, a;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int x = 0;
    int ans = 0;
    for(i = 1; i <= n; i++) {
         cin >> a;
         x += a;
         if(x <= 8) {
            ans += x;
            x = 0;
         }
         else {
            ans += 8;
            x -= 8;
         }
         if(ans >= k) {
            cout << i;
            return 0;
         }
    }
    cout << -1;
    //cin.close();
    //cout.close();
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int g[5];

int main() {
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        int t;
        cin >> t;
        g[t]++;
    }
    int ans = 0;
    ans += g[4];
    g[4] = 0;
    ans += g[3];
    if ( g[3] > 0 ) {
       if ( g[1] >= g[3] ) {
          g[1] -= g[3];
       }
       else {
            g[1] = 0;
       }
    }
    g[3] = 0;
    if ( g[2] % 2 == 0 ) {
         ans += g[2]/2;
    }
    else {
         ans += g[2]/2;
         if ( g[1] >= 2 ) {
              g[1] -= 2;
              ans++;
         }
         else if ( g[1] == 1 ) {
              g[1] -= 1;
              ans++;
         }
         else {
              ans++;
         }
    }
    if ( g[1] % 4 == 0 ) {
         ans += g[1]/4;
    }
    else {
         ans += g[1]/4+1;
    }
    cout << ans << endl;
    return 0;
}
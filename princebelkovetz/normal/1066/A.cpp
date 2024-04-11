#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    /*
      
    */
    int tt; cin >> tt;
    while (tt-->0){
        int L, v, l, r; cin >> L >> v >> l >> r;
        int ans = 0;
        ans += L / v;
        r = r / v * v;
        l = l / v * v + (l % v ? v : 0);
        cout << ans - (r - l) / v - 1 << '\n';
        
    }
    return 0;
}
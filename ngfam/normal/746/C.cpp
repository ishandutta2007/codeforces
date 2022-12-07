/*** Riven is not just my life :) ***/

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e6 + 1, mod = 1e9 + 7;

void MAIN(){
    int s, x1, x2, p, d, t1, t2;
    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;

    int ans = abs(x1 - x2) * t2;
    int cur = 0;
    while(p != x1){
        if(p == s){
            d = -1;
        }
        if(p == 0){
            d = 1;
        }
        cur += t1;
        p += d;
    }

    while(p != x2){
        if(p == s){
            d = -1;
        }
        if(p == 0){
            d = 1;
        }
        cur += t1;
        p += d;
    }
    cout << min(ans, cur);
}
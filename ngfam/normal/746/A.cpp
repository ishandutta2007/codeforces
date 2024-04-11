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
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int times = min(min(b / 2, c / 4), a);

    printf("%d", times * 7);
}
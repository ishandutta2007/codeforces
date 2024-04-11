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
    int n; scanf("%d", &n);
    if(n == 2) { puts("1"); puts("2"); return; }
    printf("%d\n", n / 2);
    while(n > 3){
        printf("2 ");
        n -= 2;
    }
    printf("%d ", n);
}
/* Riven is not just my life :) */

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
     //   freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e6 + 1, mod = 1e9 + 7;

int n;

void MAIN(){
    scanf("%d", &n);

    if(n == 0){
        puts("1");
        return;
    }

    if(n % 4 == 1){
        puts("8");
    }
    else if(n % 4 == 2){
        puts("4");
    }

    else if(n % 4 == 3){
        puts("2");
    }
    else{
        puts("6");
    }
}
/* Riven is not just my life :) */

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

int a[N], n, c;

void MAIN(){
    scanf("%d%d", &n, &c);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }

    int ans = 1;
    for(int i = 2; i <= n; ++i){
        if(a[i] - a[i - 1] > c){
            ans = 1;
        }
        else ++ans;
    }
    printf("%d", ans);
}
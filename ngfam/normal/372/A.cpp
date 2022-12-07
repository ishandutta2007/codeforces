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
typedef multiset<int>::iterator iter;

multiset < int > s;
int n, a[N];

int bigger[N], smaller[N], nbig, nsmall;

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n / 2; ++i){
        smaller[++nsmall] = a[i];
    }
    for(int i = n / 2 + 1; i <= n; ++i){
        bigger[++nbig] = a[i];
    }

    int low = nsmall, ans = n;
    for(int i = nbig; i >= 1; --i){
        while(low >= 1 && smaller[low] * 2 > bigger[i]){
            --low;
        }
        ans -= (low > 0);
        if(low > 0) --low;
    }
    printf("%d", ans + low);
}
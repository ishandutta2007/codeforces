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

int a[N], n, cnt[1010], b[N], m;

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
        ++cnt[a[i]];
    }

    sort(a + 1, a + n + 1);
    int d = 1, c = 1;

    while(true){
        int appear = 0;
        for(int i = 1; i <= 1000; ++i){
            if(cnt[i] > 0) b[++m] = i, ++appear, --cnt[i];
        }
        if(appear == 0) break;
    }
    int ans = 0;
    for(int i = 2; i <= n; ++i){
        ans += (b[i] > b[i - 1]);
    }
    printf("%d", ans);


}
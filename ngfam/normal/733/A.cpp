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

char s[N];

void MAIN(){
    scanf("%s", s + 1);

    int n = strlen(s + 1), ans = 0, last = 0;

    s[++n] = 'A';
    for(int i = 1; i <= n; ++i){
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y'){
            ans = max(ans, i - last);
            last = i;
        }
    }
    printf("%d", ans);
}
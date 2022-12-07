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

int n, a, b;
char s[N];

void MAIN(){
    scanf("%d%d%d", &n, &a, &b);
    scanf("%s", s + 1);
    printf("%d", (s[a] != s[b]));
}
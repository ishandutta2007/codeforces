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

int n, a[N], live[N];
stack < int > s;

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }

    live[0] = mod; s.push(0);
    for(int i = 1; i <= n; ++i){
        live[i] = 1;
        while(!s.empty() && a[i] > a[s.top()]){
            live[i] = max(live[i], live[s.top()] + 1);
            s.pop();
        }
        s.push(i);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(live[i] > mod) continue;
        ans = max(ans, live[i]);
    }
    printf("%d", ans);
}
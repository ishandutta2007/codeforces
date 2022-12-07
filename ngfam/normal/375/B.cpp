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
const llint N = 5e3 + 1, mod = 1e9 + 7;

int n, m, best[N][N], len[N][N];
char s[N][N];

void MAIN(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%s", s[i] + 1);
        for(int j = 1; j <= m; ++j){
            if(s[i][j] == '1'){
                len[i][j] = len[i][j - 1] + 1;
            }
            ++best[j][len[i][j]];
        }
    }

    for(int i = m - 1; i >= 1; --i){
        for(int j = 1; j <= m; ++j){
            best[j][i] += best[j][i + 1];
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; ++i){
        for(int len = 1; len <= m; ++len){
            ans = max(ans, len * best[i][len]);
        }
    }
    printf("%d", ans);
}
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
const llint N = 1e3 + 1, mod = 1e9 + 7;

int a[N][N], n, m, rowl[N][N], coll[N][N], rowr[N][N], colr[N][N];

void MAIN(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            rowl[i][j] = max(rowl[i - 1][j], a[i][j]);
            coll[i][j] = max(coll[i][j - 1], a[i][j]);
        }
    }

    for(int i = n; i >= 1; --i){
        for(int j = m; j >= 1; --j){
            rowr[i][j] = max(rowr[i + 1][j], a[i][j]);
            colr[i][j] = max(colr[i][j + 1], a[i][j]);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i][j] == 1) continue;
            ans += rowl[i][j] + rowr[i][j] + coll[i][j] + colr[i][j];
        }
    }
    printf("%d", ans);
}
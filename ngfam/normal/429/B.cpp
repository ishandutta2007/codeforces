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
const llint N = 1e3 + 10, mod = 1e9 + 7;

int a[N][N], hub[N][N], bina[N][N], n, m;
int work[N][N], gym[N][N];

void MAIN(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf("%d", &a[i][j]);
            hub[i][j] = bina[i][j] = a[i][j];
            gym[i][j] = work[i][j] = a[i][j];
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            hub[i][j] = max(hub[i - 1][j], hub[i][j - 1]) + a[i][j];
        }
    }

    for(int i = n; i >= 1; --i){
        for(int j = 1; j <= m; ++j){
            bina[i][j] = max(bina[i + 1][j], bina[i][j - 1]) + a[i][j];
        }
    }

    for(int i = n; i >= 1; --i){
        for(int j = m; j >= 1; --j){
            gym[i][j] = max(gym[i + 1][j], gym[i][j + 1]) + a[i][j];
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = m; j >= 1; --j){
            work[i][j] = max(work[i - 1][j], work[i][j + 1]) + a[i][j];
        }
    }


    int ans = 0;
    for(int i = 2; i < n; ++i){
        for(int j = 2; j < m; ++j){
            ans = max(ans, hub[i][j - 1] + gym[i][j + 1] + bina[i + 1][j] + work[i - 1][j]);
            ans = max(ans, hub[i - 1][j] + gym[i + 1][j] + bina[i][j - 1] + work[i][j + 1]);
        }
    }
    printf("%d", ans);
}
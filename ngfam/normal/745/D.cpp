/*** Riven is not just my life :) ***/

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
        //freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e3 + 1, mod = 1e9 + 7;

int quest[30][N], n, ans[N];
vector < int > appear[N], ginz[N];

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= 10; ++j){
            if(i & (1 << (j - 1))){
                appear[j].push_back(i);
            }
            else{
                ginz[j].push_back(i);
            }
        }
    }

    memset(ans, 60, sizeof ans);
    for(int i = 1; i <= 10; ++i){
        if(appear[i].size() == 0) continue;
        printf("%d\n", int(appear[i].size()));
        for(int j = 0; j < appear[i].size(); ++j){
            printf("%d ", appear[i][j]);

        }
        fflush(stdout);
        for(int k = 1; k <= n; ++k){
            int val; scanf("%d", &val);

            if(((k >> (i - 1)) & 1) == 0){
                ans[k] = min(ans[k], val);
            }
        }
        printf("\n");
    }

    for(int i = 1; i <= 10; ++i){
        if(ginz[i].size() == 0) continue;
        printf("%d\n", int(ginz[i].size()));
        for(int j = 0 ; j < ginz[i].size(); ++j){
            printf("%d ", ginz[i][j]);
        }
        fflush(stdout);

        for(int k = 1; k <= n; ++k){
            int val; scanf("%d", &val);
            if(((k >> (i - 1)) & 1) == 1) ans[k] = min(ans[k], val);
        }
        printf("\n");
    }
    printf("-1\n");
    for(int i = 1; i <= n; ++i){
        printf("%d ", ans[i]);
    }
    fflush(stdout);
}
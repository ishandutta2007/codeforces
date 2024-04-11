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

int n, a[N], k, b[N], sum[N], pos[N];

void AnswerNO(){
    puts("NO");
    exit(0);
}

void dfs(int x, int y, int l, int r, int val, int cur){
    if(x > l && val > a[x - 1]){
        printf("%d L\n", cur);
        --cur;
        val += a[l];
        dfs(x - 1, y, l, r, val, cur);
        return;
    }
    if(y < r && val > a[x + 1]){
        printf("%d R\n", cur);
        val += a[r];
        dfs(x, y + 1, l, r, val, cur);
    }
}

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
        sum[i] = sum[i - 1] + a[i];
    }

    scanf("%d", &k);
    for(int i = 1; i <= k; ++i){
        scanf("%d", b + i);
    }

    int cur = 1;
    for(int i = 1; i <= n; ++i){
        if(cur > k){
            AnswerNO();
        }
        if(sum[i] - sum[pos[cur - 1]] == b[cur]){
            pos[cur++] = i;
        }
        else
            if(sum[i] - sum[pos[cur - 1]] > b[cur]){
                AnswerNO();
            }
    }
    if(cur <= k) AnswerNO();

    int sub = 0;
    for(int i = 1; i <= k; ++i){
        int fr = pos[i - 1] + 1, to = pos[i], ok = 0;
        if(to - fr == 0) continue;
        for(int j = fr + 1; j <= to; ++j){
            if(a[j] != a[fr]){
                ok = 1;
                break;
            }
        }
        if(ok == 0) AnswerNO();
    }
    puts("YES");

    for(int i = 1; i <= k; ++i){
        int fr = pos[i - 1] + 1, to = pos[i], ok = 0;
        int max_ = fr;
        for(int j = fr + 1; j <= to; ++j){
            if(a[j] >= a[max_]){
                if(j != to){
                    if(a[j] != a[j - 1] || a[j] != a[j + 1]){
                        max_ = j;
                    }
                }
                else{
                    if(a[j] != a[j - 1])
                        max_ = j;
                }
            }
        }
        dfs(max_, max_, fr, to, a[max_], max_ - sub);
        sub += to - fr;
    }
}
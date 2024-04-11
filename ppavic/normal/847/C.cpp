#include <cstdio>

using namespace std;

typedef long long int llint;

int n;
llint k;
int len = 0;

int main(){
    scanf("%d%I64d",&n,&k);
    if(k > (llint)n * (llint)(n-1) / 2LL){
        printf("Impossible\n");
        return 0;
    }
    int cnt2 = 0;
    while(k - (llint)(n - cnt2 - 1) >= 0LL){
        if(cnt2 == n) break;
        k -= (llint)n - (llint)cnt2 - 1;
        cnt2++;
        printf("(");len += 2;
    }
    while(k > 0){
        int cnt = 1;
        llint sm = 0;
        while(sm + cnt <= k) sm += (llint)cnt++;
        for(int i = 0;i<cnt;i++)
            printf("(");
        for(int i = 0;i<cnt;i++)
            printf(")");
        len += 2 * cnt;
        k -= sm;
    }
    while(len < 2 * n){
        printf("()");
        len += 2;
    }
    for(int i = 0;i<cnt2;i++){
        printf(")");
    }
    printf("\n");
}
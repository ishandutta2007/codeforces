#include <iostream>

using namespace std;
int lev[10000];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        long long k;
        scanf("%lld", &k);
        if(k%2==1){
            printf("-1\n");
            continue;
        }
        int x = 1, cnt=0;
        while((1LL<<x) <= k){
            if((1LL<<x)&k){
                if(x==1) lev[cnt++] = 1;
                else{
                    lev[cnt++]=1;
                    for(int i=1;i<=x-2;i++){
                        lev[cnt++]=0;
                    }
                    lev[cnt++]=1;
                }
            }
            x++;
        }
        printf("%d\n", cnt);
        for(int i=0;i<cnt;i++){
            printf("%d ", lev[i]);
        }
        printf("\n");
    }
}
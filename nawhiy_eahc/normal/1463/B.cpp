#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        long long a[52], b[52];
        for(int i=1;i<=n;i++){
            scanf("%lld", &a[i]);
        }
        for(int i=1;i<=n;i++){
            b[i] = 0;
            for(int j=0;j<=28;j++){
                if(a[i]<=((1LL<<j)+(1LL<<(j+1)))/2){
                    b[i] = 1LL << j;
                    break;
                }
            }
            if(!b[i]) b[i] = 1LL<<29;
        }

        for(int i=1;i<=n;i++){
            printf("%lld ", b[i]);
        }
        printf("\n");
    }
}
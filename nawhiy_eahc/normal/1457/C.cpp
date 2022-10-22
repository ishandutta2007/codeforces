#include <iostream>

using namespace std;
int plat[100002];
int kk[100002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, p, k;
        scanf("%d %d %d", &n, &p, &k);
        for(int i=1;i<=n;i++){
            scanf("%1d", &plat[i]);
        }
        long long x, y;
        scanf("%lld %lld", &x, &y);
        long long result = 1000000000000LL;
        for(int i=0;i<k;i++){
            int m = 0, cnt = 0;
            m = (n-p-i)/k;
            while(m>=0){
                if(plat[p+m*k+i]==0) cnt++;
                result = min(result, y*(k*m+i) + x*cnt);
                m--;
            }
        }
        printf("%lld\n", result);
    }
}
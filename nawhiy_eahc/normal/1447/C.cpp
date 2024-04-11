#include <iostream>

using namespace std;
int a[200002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        long long n, w;
        bool b = true;
        bool p = true;
        scanf("%lld %lld", &n, &w);
        long long m, sum = 0;
        if(w%2) m = w/2+1;
        else m = w/2;
        int cnt = 0;
        for(int i=1;i<=n;i++){
            long long k;
            scanf("%lld", &k);
            if(!b || !p) continue;
            if(k>w) continue;
            if(k>=m){
                printf("1\n%d\n", i);
                b = false;
                continue;
            }
            sum+=k;
            a[cnt++] = i;
            if(sum>=m){
                p = false;
                continue;
            }

        }
        if(b && sum>=m){
            printf("%d\n", cnt);
            for(int i=0;i<cnt;i++){
                printf("%d ", a[i]);
            }
            printf("\n");
        }
        else if(b)
            printf("-1\n");
    }
}
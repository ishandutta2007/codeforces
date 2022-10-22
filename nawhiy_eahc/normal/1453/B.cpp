#include <iostream>

using namespace std;
long long a[200002];
long long b[200002];
long long c[200002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        long long n, m = -100000000000LL, sum = 0;
        scanf("%lld", &n);
        for(int i=1;i<=n;i++){
            scanf("%lld", &a[i]);
        }
        for(int i=2;i<=n;i++){
            b[i] = abs(a[i]-a[i-1]);
            sum += b[i];
        }
        for(int i=3;i<=n;i++){
            c[i] = abs(a[i] - a[i-2]);
        }
        m = b[2];
        for(int i=3;i<=n;i++){
            m = max(m, b[i]+b[i-1]-c[i]);
        }
        m = max(m, b[n]);

        printf("%lld\n", sum - m);
    }
}
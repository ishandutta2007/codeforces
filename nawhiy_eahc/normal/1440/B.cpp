#include <iostream>
#include <algorithm>

using namespace std;
long long a[1000002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i=1;i<=n*k;i++){
            scanf("%lld", &a[i]);
        }
        int index = n*k-n/2;
        long long sum = 0;
        for(int i=1;i<=k;i++){
            sum+=a[index];
            index-=(n/2)+1;
        }

        printf("%lld\n", sum);
    }
}
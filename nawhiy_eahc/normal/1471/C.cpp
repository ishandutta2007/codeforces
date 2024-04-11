#include <bits/stdc++.h>

using namespace std;

long long k[300002];
long long c[300002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=1;i<=n;i++){
            scanf("%lld", &k[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%lld", &c[i]);
        }

        sort(k+1, k+n+1);

        long long sum_d = 0, sum_p = 0, ans;

        for(int i=1;i<=n;i++){
            sum_d += c[k[i]];
        }

        ans = sum_d;

        for(int i=n;i>=max(1, n-m+1);i--){
            sum_d -= c[k[i]];
            sum_p += c[n-i+1];

            ans = min(ans, sum_d + sum_p);
        }

        printf("%lld\n", ans);
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        long long sum=0;
        long long mn=1e9+7;
        for(int i=0;i<n*2;i++) {
            for(int j=0;j<n*2;j++) {
                long long x;
                scanf("%lld",&x);
                if (i>=n&&j>=n) {
                    sum+=x;
                }
                if ((i==0||i==n-1)&&(j==n||j==2*n-1)) {
                    mn=min(mn,x);
                }
                if ((i==n||i==2*n-1)&&(j==0||j==n-1)) {
                    mn=min(mn,x);
                }
            }
        }
        printf("%lld\n",sum+mn);
    }
    return 0;
}
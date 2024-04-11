#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        ll n, k;
        scanf("%lld %lld", &n, &k);
        int m = n - k + 1;
        for(int i=1;i<=k-m;i++){
            printf("%d ", i);
        }
        for(int i=k-m+1;i<=k;i++){
            printf("%d ", k - i + k - m + 1);
        }
        printf("\n");
    }
}
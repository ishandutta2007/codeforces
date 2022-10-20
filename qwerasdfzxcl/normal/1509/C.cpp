#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[2020], dp[2020][2020];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%lld", a+i);
    sort(a, a+n);
    for (int i=0;i<n;i++) dp[i][i] = 0;
    for (int d=1;d<n;d++){
        for (int i=0;i<n-d;i++){
            dp[i][i+d] = min(dp[i][i+d-1], dp[i+1][i+d])+a[i+d]-a[i];
        }
    }
    printf("%lld\n", dp[0][n-1]);
    return 0;
}
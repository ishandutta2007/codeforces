#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[11][300300], dp[300300], ans;

void solve(int n, int m, int x){
    for (int i=1;i<=n;i++){
        dp[i] = max(a[x][i], dp[i-1]+a[x][i]);
        if (i%m==x) ans = max(ans, dp[i]);
    }
}

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i=1;i<=n;i++){
        scanf("%lld", a[0]+i);
        for (int j=1;j<m;j++) a[j][i] = a[0][i];
        a[i%m][i] -= k;
    }
    for (int i=0;i<m;i++) solve(n, m, i);
    printf("%lld\n", ans);
    return 0;
}
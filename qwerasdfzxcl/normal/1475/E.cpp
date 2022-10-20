#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[1010];
ll dp[1010][1010], MOD=1e9+7;

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    sort(a, a+n, greater<int>());
    int tmp=a[k-1], c=0, d=0;
    for (int i=0;i<n;i++){
        if (a[i]==tmp) c++;
        if (a[i]==tmp && i<=k-1) d++;
    }
    printf("%lld\n", dp[c][d]);
}

int main(){
    for (int i=0;i<1010;i++){
        for (int j=0;j<=i;j++){
            if (j==0 || j==i) dp[i][j]=1;
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
        }
    }
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
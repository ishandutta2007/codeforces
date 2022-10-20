#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], dp[100100];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", a+i);

    dp[0] = 0;
    map<int, int> mp;
    mp[0] = 0;
    int cur = 0;
    for (int i=1;i<=n;i++){
        cur ^= a[i];

        dp[i] = dp[i-1] + 1;
        if (mp.find(cur)!=mp.end()) dp[i] = min(dp[i], dp[mp[cur]] + (i-mp[cur]-1));

        mp[cur] = i;
        //printf("%d ", dp[i]);
    }
    //printf("\n");

    printf("%d\n", dp[n]);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int dp[1<<21];
int vis[1<<21];
int a[1<<20];
void update(int mask, int tot){
    if(dp[mask] > 1 || vis[mask] == tot) return;
    dp[mask]++;
    vis[mask] = tot;
    for(int i = 0; i <= 20; ++i) {
        if(mask&(1<<i)) update(mask^(1<<i), tot);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int ans = 0;
    int tot = 0;
    for(int i = n; i > 0; --i){
        int res = 0;
        int t = 0;
        for(int j = 20; j >= 0; --j){
            if((a[i]>>j)&1) res |= (1<<j);
            else if(dp[t|(1<<j)] > 1) res |= (1<<j), t |= (1<<j);
        }
        if(i <= n-2) ans = max(ans, res);
        update(a[i], ++tot);
    }
    cout<<ans<<endl;
}
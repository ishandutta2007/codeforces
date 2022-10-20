#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int c[5050];
ll cost[5050], dp1[5050], dp2[5050], dpmx1[5050], dpmx2[5050];

ll val(int i, int j){
    if (i==j) return 0;
    if (c[i]==c[j]) return -1e14;
    return abs(cost[i]-cost[j]);
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", c+i);
    for (int i=0;i<n;i++) scanf("%lld", cost+i);
    for (int i=0;i<n;i++){
        dp1[i]=0, dp2[i]=0, dpmx1[i]=0, dpmx2[i]=0;
    }
    for (int i=1;i<n;i++){
        for (int j=i-1;j>=0;j--){
            dp2[j]=dpmx2[j]+val(i, j);
            dpmx1[j]=max(dpmx1[j+1], dp2[j+1]);
        }
        for (int j=0;j<i;j++){
            dp1[j]=dpmx1[j]+val(i, j);
            dpmx2[j]=max(dpmx2[j], dp1[j]);
        }
        dpmx2[i]=max(dpmx1[0], dp2[0]);
    }
    ll ans=0;
    for (int i=0;i<n;i++) ans = max(ans, max(dp1[i], dp2[i]));
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
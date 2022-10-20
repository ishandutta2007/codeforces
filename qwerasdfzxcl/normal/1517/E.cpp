#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = 998244353;
ll a[200200];
ll s1[200200], s2[2][200200], srev[200200];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%lld", a+i);
    s1[0] = 0, s2[0][0] = 0, s2[1][1] = a[1], s1[1] = a[1];
    s2[0][1] = 0, s2[1][0] = 0;
    for (int i=2;i<=n;i++){
        s1[i] = s1[i-1]+a[i];
        s2[i&1][i] = s2[i&1][i-2] + a[i];
        s2[(i&1)^1][i] = s2[(i&1)^1][i-1];
    }
    ll ans=0, S=s1[n];
    ll C = (S+1)/2;
    ///start in a[1]
    for (int i=1;i<=n-1;i++){
        //printf("%lld ", ans);
        ll val=0;
        if (s1[i]*2>=S) break;
        int idx = lower_bound(s2[i&1]+i+1, s2[i&1]+n, C+s2[i&1][i]-s1[i])-s2[i&1];
        if (idx==n){
            val += (n-i-1)/2+1;
        }
        else{
            //printf("YES%d\n", i);
            idx -= 2;
            val += (idx-i)/2+1;
        }
        if ((s1[i]+a[n])*2>=S){
            ans = (ans+val)%MOD;
            continue;
        }
        int idx2 = lower_bound(s2[i&1]+i+1, s2[i&1]+n+1, C+s2[i&1][i]-a[n]-s1[i])-s2[i&1];
        if (idx2==n+1){
            val += (n-i)/2;
        }
        else{
            idx2 -= 2;
            val += (idx2-i)/2+1;
        }
        //printf("%d: %d %d\n", i, idx, idx2);
        //assert(idx>=i && idx2>=i);
        ans = (ans+val)%MOD;
    }
    ///start in a[2]
    for (int i=2;i<=n-1;i++){
        //printf("%lld ", ans);
        ll val=0;
        if ((s1[i]-a[1])*2>=S) break;
        int idx = lower_bound(s2[i&1]+i+1, s2[i&1]+n, C+s2[i&1][i]-s1[i]+a[1])-s2[i&1];
        if (idx==n){
            val += (n-i-1)/2+1;
        }
        else{
            idx -= 2;
            val += (idx-i)/2+1;
        }
        if ((s1[i]+a[n]-a[1])*2>=S){
            ans = (ans+val)%MOD;
            continue;
        }
        int idx2 = lower_bound(s2[i&1]+i+1, s2[i&1]+n+1, C+s2[i&1][i]-a[n]-s1[i]+a[1])-s2[i&1];
        if (idx2==n+1){
            val += (n-i)/2;
        }
        else{
            idx2 -= 2;
            val += (idx2-i)/2+1;
        }
        //printf("%d: %d %d\n", i, idx, idx2);
        //assert(idx>=i && idx2>=i);
        ans = (ans+val)%MOD;
    }
    ///start in n>=3
    //printf("%lld ", ans);
    srev[0] = a[n];
    for (int i=n-1;i>1;i--) srev[n-i] = srev[n-i-1]+a[i];
    int idx = lower_bound(srev, srev+n-1, C)-srev;
    ans = (ans+idx+1)%MOD;
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
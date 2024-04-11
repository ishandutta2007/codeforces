#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = 998244353;
ll dp[1001000], S[1001000];
bool prime[1010];
vector<int> p;

ll calc(int x){
    ll ret = 1;
    for (auto &y:p){
        int cnt=0;
        while(x%y==0){
            x/=y;
            cnt++;
        }
        ret *= (cnt+1);
        if (ret>MOD) ret %=MOD;
    }
    if (x!=1) ret = (ret*2)%MOD;
    return ret;
}

int main(){
    fill(prime+2, prime+1010, 1);
    for (int i=2;i<1010;i++){
        if (!prime[i]) continue;
        p.push_back(i);
        for (int j=2;i*j<1010;j++) prime[i*j]=0;
    }
    int n;
    scanf("%d", &n);
    dp[1] = S[1] = 1;
    for (int i=2;i<=n;i++){
        dp[i] += calc(i);
        dp[i] %= MOD;
        dp[i] = (dp[i]+S[i-1])%MOD;
        S[i] = (dp[i]+S[i-1])%MOD;
    }
    printf("%lld\n", dp[n]);
    return 0;
}
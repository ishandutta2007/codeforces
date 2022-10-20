#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = 998244353;
string s[23];
int dp[1<<23], val[23][26], ans[1<<23], n;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> s[i];
        int pt = 0;
        for (int j=0;j<26;j++){
            int prv = pt;
            while(pt<(int)s[i].size() && s[i][pt]=='a'+j) pt++;
            val[i][j] = pt - prv;
        }
    }

    for (int msk=1;msk<(1<<n);msk++){
        dp[msk] = 1;
        for (int j=0;j<26;j++){
            int tmp = 1e9;
            for (int i=0;i<n;i++) if (msk&(1<<i)) tmp = min(tmp, val[i][j]);
            dp[msk] = (ll)dp[msk] * (tmp+1) % MOD;
        }
    }

    for (int z=1;z<(1<<n);z++){
        ans[z] = dp[z] * ((__builtin_popcount(z)&1)?1:-1);
        if (ans[z]<0) ans[z] += MOD;
    }
    for (int i=0;i<n;i++){
        for (int z=1;z<(1<<n);z++) if (z&(1<<i)){
            ans[z] += ans[z^(1<<i)];
            if (ans[z]>=MOD) ans[z] -= MOD;
        }
    }

    ll rans = 0;
    for (int z=1;z<(1<<n);z++){
        ll tmp = __builtin_popcount(z), tmp2 = 0;
        for (int j=0;j<n;j++) if (z&(1<<j)) tmp2 += j+1;
        rans ^= tmp*tmp2*ans[z];
    }
    printf("%lld\n", rans);
    return 0;
}
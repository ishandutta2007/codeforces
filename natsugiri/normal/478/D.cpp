#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)


const LL MOD = 1e9 + 7;

LL dp[200011]; // [using Red]
LL tmp;

int R, G;

int main() {
    scanf("%d%d", &R, &G);
    if (R > G) swap(R, G);

    dp[0] = 1;
    for (int i=1, sum=1; sum<=R+G; i++) {
        for (int j=min(R, sum); j>=0; j--) {
            tmp = 0;
            if (j >= i) tmp = dp[j-i];
            if (sum - j <= G) tmp += dp[j];

            if (tmp >= MOD) tmp -= MOD;
            dp[j] = tmp;
        }
        // REP (j, min(R, sum)+1) cerr << dp[j] << " "; cerr <<endl;
        sum += i + 1;
    }

    tmp = 0;
    REP (i, 200011) tmp = (tmp + dp[i]) % MOD;

    printf("%d\n", int(tmp));

    return 0;
}
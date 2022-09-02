#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#define norm(x) if (x >= MOD) x -= MOD

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXL = 5001;

int MOD;
int cnt[MAXL][MAXL];
int c[MAXL];
int f[MAXL];
int dp[MAXL];
int sum;
int sum2;
int n,m;

vector<int> v;



int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d %d",&n,&m);
    scanf("%d",&MOD);

    for (int i = 1; i < MAXL; i++)
        cnt[i][0] = 0, cnt[0][i] = 0;
    cnt[0][0] = 1;

    for (int i = 1; i < MAXL; i++)
        for (int j = 1; j < MAXL; j++)
            cnt[i][j] = ((j-1) * 1LL * cnt[i-1][j] + cnt[i-1][j-1]) % MOD;       

    c[0] = 1;

/*    for (int i = 1; i < MAXL; i++){
        v.pb(m - i + 1);
        for (int j = 0; j < i; j++)
            if (v[j] % i == 0)
                v[j] /= i;
        int& ans = c[i];
        ans = 1;

        for (int j = 0; j < i; j++)
            ans = (ans * 1LL* v[j]) % MOD;
    }*/

    f[0] = 1;

    for (int i = 1; i < MAXL; i++) {
        c[i] = (c[i-1] * 1LL * (m-i+1)) % MOD;
        f[i] = (f[i-1] * 1LL * i) % MOD;
    }




    sum = 1;

    m = min(m,MAXL-1);
    int l2 = 0;

    //cerr << cnt[1][1] << endl;

    for (int i = 0; i < n; i++){
        int l;
        scanf("%d",&l);
        sum2 = 0;

        for (int j = 1; j <= l; j++){
            //cerr << i <<" "<<j<<" "<<sum <<" "<<c[j] <<" "<<dp[j] <<" "<<cnt[l][j] << endl;
            dp[j] = ((sum * 1LL * c[j] - (dp[j]* 1LL * f[j]) % MOD + MOD) % MOD * 1LL* cnt[l][j]) % MOD;
            dp[j] += MOD;
            norm(dp[j]);
            sum2 += dp[j];
            norm(sum2);
        }

        for (int j = l+1; j <= l2; j++)
            dp[j] = 0;
        l2 = l;

        //cerr <<dp[1] <<" "<<dp[2]<<endl;

        sum = sum2;
    }

    cout << sum << endl;
    return 0;
}
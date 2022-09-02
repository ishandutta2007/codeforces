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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;


const int MOD = 1000*1000 + 3;


char **s,**st;


int dp[510*1000];

int solve(char *s,int len){
    memset(dp,0,sizeof(int)*(len+10));
    dp[0] = 1;
    for (int i = 0; i < len; i++){
        if (s[i] == '.'){
            if (i+1 == len || s[i+1] == '.' || s[i+1] == '1' || s[i+1] == '2'){
                dp[i+2] += dp[i];
                if (dp[i+2] >= MOD)
                    dp[i+2] -= MOD;
            }
            if (i-1 == -1 /*|| s[i-1] == '.' || s[i-1] == '3' || s[i-1] == '4'*/)
                dp[i+1] += dp[i];
                if (dp[i+1] >= MOD)
                    dp[i+1] -= MOD;
        }

        if (s[i] == '3' || s[i] == '4'){
            if (i+1 == len || s[i+1] == '.' || s[i+1] =='1' || s[i+1] == '2'){
                dp[i+2] += dp[i];
                if (dp[i+2] >= MOD)
                    dp[i+2] -= MOD;
            }
        }

        if (i == 0 && (s[i] == '1' || s[i] =='2'))
            dp[i+1] += dp[i];           
    }

/*  cerr << string(s,s+len) <<" "<<dp[len] + dp[len+1] << endl;
    cerr << dp[0] <<" "<<dp[1] <<" "<<dp[2] <<" "<<dp[3] <<" "<<dp[4] << endl;*/

    return dp[len] + dp[len+1];
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m;
    char _temp[100];
    gets(_temp);
    sscanf(_temp,"%d %d",&n,&m);
    s = new char*[n];
    st = new char*[m];

    for (int i = 0; i < n; i++)
        s[i] = new char[m+1];

    for (int i = 0; i < m; i++)
        st[i] = new char[n+1];

    for (int i = 0; i < n; i++){
        gets(s[i]);
        for (int j = 0; j < m; j++){
            st[j][i] = s[i][j];
            if (st[j][i] == '2')
                st[j][i] = '4';
            else if (st[j][i] == '4')
                st[j][i] = '2';             
        }
    }

    int ans = 1;

    for (int i = 0; i < n; i++)
        ans = (ans * 1LL * solve(s[i],m)) % MOD;
    for (int j = 0; j < m; j++)
        ans = (ans * 1LL * solve(st[j],n)) % MOD;

    cout << ans << endl;        
  return 0;
}
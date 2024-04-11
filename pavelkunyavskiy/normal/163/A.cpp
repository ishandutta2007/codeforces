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

int dp[5100][5100];

char s[5100];
char t[5100];

int calc(int a,int b){
    if (!s[a] || !t[b])
        return 0;
    int& ans = dp[a][b];
    if (ans != -1)
        return ans;
    ans = 0;
    ans += calc(a,b+1);
    if (s[a] == t[b])
        ans += calc(a+1,b+1)+1;
    ans %= 1000000007;
    return ans;
}



int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    gets(s);
    gets(t);

    memset(dp,-1,sizeof(dp));


    int ans = 0;
    for (int i = 0; s[i]; i++){
        ans += calc(i,0);
        ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}
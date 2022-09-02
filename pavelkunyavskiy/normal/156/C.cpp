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

#define ADD(x,y) if ((x += y) >= MOD) x-=MOD
#define SUB(x,y) if ((x -= y) < 0) x += MOD


#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

char s[210];

int ans[110][3000];


void Precalc(){
    ans[0][0] = 1;
    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 3000-26; j++)
            for (int k = 0; k < 26; k++)
                ADD(ans[i+1][j+k],ans[i][j]);

}




void solve(){
    gets(s);
    int sum = 0;

    //cerr << s << endl;

    for (int i = 0; s[i]; i++)
        sum += s[i] - 'a';

    int res = ans[strlen(s)][sum];
    SUB(res,1);

    printf("%d\n",res);
}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  Precalc();

  int t;
  gets(s);
  sscanf(s,"%d",&t);
  while (t --> 0)
    solve();
  return 0;
}
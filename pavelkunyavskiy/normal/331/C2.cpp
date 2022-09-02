//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"

typedef long long ll;
typedef long double ld;

const int MAXN = 1100000;

ll cnt[20][10][10];
ll to[20][10][10];

int getmax(ll n){
    ll res = 0;
    while (n) {
        res = max(res, n % 10);
        n /= 10;
    }
    return res;
}

ll solve(ll x){
//  eprintf("SOLVE "LLD":\n",x);
    if (x == 0) return 0;
    ll ans = 0;
    ll cur = x % 10;
    for (int i = 0; x != -1; i++){
        x /= 10;
        while ((x+10) % 10 != 9){
//          eprintf("X: "LLD"\n",x);
            ans += cnt[i][cur][getmax(x)];
            cur = to[i][cur][getmax(x)];
            x--;
        }
    }
    ans--;
    return ans;
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)    
            if (j > i)
              cnt[0][i][j] = 1, to[0][i][j] = (i - j + 10)%10;
            else
              cnt[0][i][j] = 2, to[0][i][j] = (10 - j);

    for (int k = 1; k < 20; k++){
        for (int x = 0; x < 10; x++)
            for (int j = 0; j < 10; j++){
                cnt[k][x][j] = 0;
                to[k][x][j] = x;
                for (int f = 9; f >= 0; f--) {
                    cnt[k][x][j] += cnt[k-1][to[k][x][j]][max(j,f)];
                    to[k][x][j] = to[k-1][to[k][x][j]][max(j,f)];
//                  if (k == 1 && x == 1 && j == 0)
//                      eprintf(LLD" "LLD"\n", cnt[k][x][j], to[k][x][j]);
                    assert(to[k][x][j] != 0);
                }
            }
    }

                 

    ll n;
    scanf(LLD,&n);
    printf(LLD"\n",solve(n));
      
    TIMESTAMP(end);
    return 0;
}
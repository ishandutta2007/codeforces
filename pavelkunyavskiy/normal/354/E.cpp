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

#define TASKNAME "E"

#ifdef LOCAL
static struct __timestamper {
    ~__timestamper(){
        TIMESTAMP(end);
    }
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;

set<ll> failed;

vector<int> prec[10][5];

void go(ll x,vector<ll> &res){
    if (x < 0 || failed.find(x) != failed.end())
        return ;
    if (x == 0){
        res = vector<ll> (6, 0);
        return;
    }
//  eprintf(LLD"\n", x);
    int last = x % 10;
    for (int i = 0; i < 5; i++)
        if (!prec[last][i].empty()){
            go((x - last) / 10 - i, res);
            if (!res.empty()){
                for (int j = 0; j < 6; j++)
                    res[j] = 10 * res[j] + prec[last][i][j];
                #ifdef LOCAL
                    ll sum = 0;
                    for (int j = 0; j < 6; j++)
                        sum += res[j];
                    assert(sum == x);
                #endif
                return ;
            }
        }
    failed.insert(x);
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    for (int i = 0; i < 3*3*3*3*3*3; i++){
        vector<int> v;
        int sum = 0;
        int t = i;
        for (int j = 0; j < 6; j++){
            int x = t % 3; 
            t /= 3;
            if (x == 1)
                x = 4;
            else if (x == 2)
                x = 7;
            v.pb(x);
            sum += x;
        }
        prec[sum % 10][sum / 10] = v;
    }

    
    int tst;
    scanf("%d",&tst);

    while (tst --> 0){
        failed.clear();
        ll x;
        scanf(LLD,&x);
        vector<ll> res;
        go(x,res);
        if (res.empty()){
            printf("-1\n");
            continue;
        }
        for (int i = 0; i < 6; i++)
            printf(LLD"%c", res[i], " \n"[i==5]);
    }

      
  return 0;
}
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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "A"

typedef long long ll;
typedef long double ld;

int l[110000];
int r[110000];
int d[110000];
int a[110000];

ll dlt[110000];
ll dlt2[110000];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);

    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
        

    for (int i = 0; i < m; i++)
        scanf("%d %d %d",&l[i],&r[i],&d[i]);

    for (int i = 0; i < k; i++){
        int l,r;
        scanf("%d %d",&l,&r);
        dlt[r]--;
        dlt[l-1]++;
    }

    ll cnt = 0;

    for (int i = 0; i < m; i++){
        cnt += dlt[i];
        eprintf(LLD"\n",cnt);
        dlt2[l[i]-1] += d[i] * cnt;
        dlt2[r[i]] -= d[i] * cnt;
    }

    ll sum = 0;

    for (int i = 0; i < n; i++){
        sum += dlt2[i];
        printf(LLD"%c",sum+a[i]," \n"[i==n-1]);
    }


      
  TIMESTAMP(end);
  return 0;
}
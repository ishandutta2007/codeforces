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

#define TASKNAME "A"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#endif

typedef long long ll;
typedef long double ld;

const int MAXN = 100100;

int cnt[3][MAXN];

char s[MAXN];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    gets(s);

    for (int i = 0; s[i]; i++){
        cnt[s[i] - 'x'][i+1]++;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 1; s[j-1]; j++)
           cnt[i][j] += cnt[i][j-1];

    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        int l, r;
        scanf("%d %d",&l, &r);
        --l;
        int cntr[3];
        for (int j = 0; j < 3; j++)
           cntr[j] = cnt[j][r] - cnt[j][l];
        sort(cntr, cntr + 3);
        if (cntr[2] <= cntr[0] + 1 || (r - l <= 2))
           printf("YES\n");
        else
           printf("NO\n");
    }

      
  return 0;
}
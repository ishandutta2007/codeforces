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

typedef long long ll;
typedef long double ld;

map<int,int> first;
map<int,int> last;

ll ans;
int lf, rg;

int a[310000];
ll sum[310000];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        sum[i+1] = sum[i] + max(a[i],0);
        last[a[i]] = i;
        if (!first.count(a[i])) first[a[i]] = i;
    }

    ans = -(1LL<<60);

    for (map<int,int>::iterator iter = first.begin(); iter != first.end(); ++iter){
        int l = iter->second;
        int r = last[a[l]];
        if (l == r) continue;
        ll cur = a[l] + a[r] + sum[r] - sum[l+1];
        if (cur > ans){
            ans = cur;
            lf = l;
            rg = r;
        }
    }
    int cnt = n;
    for (int i = 0; i < n; i++)
        if (i == lf || i == rg || (lf < i && i < rg && a[i] > 0))
            cnt--;

    printf(LLD" %d\n",ans, cnt);
    for (int i = 0; i < n; i++)
        if (!(i == lf || i == rg || (lf < i && i < rg && a[i] > 0)))
            printf("%d ",i+1);
    
    TIMESTAMP(end);
    return 0;
}
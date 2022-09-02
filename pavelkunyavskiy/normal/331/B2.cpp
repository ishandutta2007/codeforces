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

#define TASKNAME "B"

typedef long long ll;
typedef long double ld;

const int MAXN = 310000;

int a[MAXN];
int ra[MAXN];

int value[MAXN];
int bit[MAXN];
int n;

void update(int pos,int to){         
    int diff = to - value[pos];
    value[pos] += diff;
    assert(value[pos] == to);
//  eprintf("SET %d to %d diff is %d\n",pos,to, diff);
    for (;pos < n; pos = pos | (pos+1))
        bit[pos] += diff;
}

int get(int r){
    int ans = 0;
    for (;r != -1; r = (r & (r+1))-1)
        ans += bit[r];
    return ans;
}

int get(int l,int r){
//  eprintf("GET [%d,%d) is %d\n",l,r,get(r-1) - get(l-1));
    return get(r-1) - get(l-1);
}

void erase(int x){
    update(x,0);
    if (x) update(x-1,0);
}

void insert(int x){
    if (x != n-1 && ra[x] > ra[x+1]) update(x,1);
    if (x != 0   && ra[x-1] > ra[x]) update(x-1,1);
}

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]), --a[i], ra[a[i]] = i;

    for (int i = 0; i < n; i++)
        insert(i);

    int q;
    scanf("%d",&q);

    eprintf("init\n");

    for (int i = 0; i < q; i++){
        int t;
        scanf("%d",&t);
        if (t == 1){
            int l,r;
            scanf("%d %d",&l,&r);
            --l,--r;
            printf("%d\n",get(l,r)+1); 
        } else {
            int x,y;
            scanf("%d %d",&x,&y);
            --x,--y;
            erase(a[x]);
            erase(a[y]);
            swap(a[x],a[y]);
            ra[a[x]] = x;
            ra[a[y]] = y;
            insert(a[x]);
            insert(a[y]);
        }
    }
      
    TIMESTAMP(end);
    return 0;
}
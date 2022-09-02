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

#define TASKNAME "E"

typedef long long ll;
typedef long double ld;


const int MAXN = 110000;

int a[MAXN];
int b[MAXN];
int n,m;
int tree[MAXN*4];
int lst = 0;

int update(int v,int l,int r,int L,int R,int start){
//  eprintf("!!! %d %d %d %d %d\n",v,l,r,L,R);
    if (r < L || R < l)
        return 0;
    if (L <= l && r <= R){
    //  eprintf("+++\n");
        tree[v] = start;
        return r-l+1;
    }
    if (tree[v] != -1){
        tree[2*v] = tree[v];
        tree[2*v+1] = tree[v] + (r - l + 1)/2;
        tree[v] = -1;
    }
    int tmp = update(2*v,l,(l+r)/2,L,R,start);
    tmp += update(2*v+1,(l+r)/2+1,r,L,R,start+tmp);
    return tmp;
}

int get(int pos){
//  eprintf("?%d\n",pos);
    int l = 0;
    int r = lst-1;
    int v = 1;
    while (r - l > 0){
    //  eprintf("!!%d %d %d %d\n",v,tree[v],l,pos);
        if (tree[v] != -1)
            return tree[v] + (pos - l);
        int mid = (l+r)/2;
        if (l <= pos && pos <= mid)
            r = mid, v = 2*v;
        else
            l = mid+1, v = 2*v+1;
    }

    return tree[v];
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d",&b[i]);

    lst = 2;
    while (lst < n)
        lst *= 2;
    memset(tree,-1,sizeof(tree));

    for (int i = 0; i < m; i++){
        int ty;
        scanf("%d",&ty);
        if (ty == 1){
            int x,y,k;
            scanf("%d %d %d",&x,&y,&k);
            --x,--y;
            assert(update(1,0,lst-1,y,y+k-1,x) == k);
        }
        else {
            int pos;
            scanf("%d",&pos);
            --pos;
            int val = get(pos);
    //      eprintf("%d\n",val);
            if (val == -1)
                printf("%d\n",b[pos]);
            else
                printf("%d\n",a[val]);
        }

    //  for (int i = 1; i <= 2*lst-1; i++)
    //      eprintf("%d%c",tree[i]," \n"[!(i&(i+1))]);
    }
      
    TIMESTAMP(end);
    return 0;
}
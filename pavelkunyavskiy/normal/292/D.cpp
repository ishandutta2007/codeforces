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

#define TASKNAME "D"

typedef long long ll;
typedef long double ld;

const int MAXN = 510;


int n;

namespace dsu{
    int p[MAXN];

    void reset(){   
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int root(int a){
        if (a == p[a]) return a;
        return p[a] = root(p[a]);
    }

    bool join(int a,int b){
        a = root(a);
        b = root(b);
        if (p[a] == p[b])
            return false;
        p[a] = b;
        return true;
    }
    
}

int a[21000];
int b[21000];

vector<int> v1,v2;



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int m;
    scanf("%d %d",&n,&m);

    for (int i = 0; i < m; i++){
        scanf("%d %d",&a[i],&b[i]);
        --a[i],--b[i];
    }

    dsu::reset();
    for (int i = 0; i < m; i++)
        if (dsu::join(a[i],b[i]))
            v1.pb(i);
    dsu::reset();
    for (int i = m-1; i >= 0; i--)
        if (dsu::join(a[i],b[i]))
            v2.pb(i);

    //eprintf("%d %d\n",v1.size(),v2.size());

    int q;
    scanf("%d",&q);
    for (int i = 0; i < q; i++){
        dsu::reset();
        int l,r;
        scanf("%d %d",&l,&r);
        --l,--r;
        int ans = n;
        for (int j = 0; j < (int)v1.size() && v1[j] < l; j++)
            if (dsu::join(a[v1[j]],b[v1[j]]))
                ans--;
        for (int j = 0; j < (int)v2.size() && v2[j] > r; j++)
            if (dsu::join(a[v2[j]],b[v2[j]]))
                ans--;
        printf("%d\n",ans);
    }



      
  TIMESTAMP(end);
  return 0;
}
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

const int MAXN = 210000;

int bit[MAXN];
int n,m;
vector<int> d[MAXN];

void update(int x){
    for (;x < MAXN; x = (x | (x+1)))
        bit[x]++;
}

ll get(int r){
    ll ans = 0;
    for (; r != -1; r = (r & (r+1)) - 1)
        ans += bit[r];
    return ans;
}

int get(int l,int r){
    return get(r) - get(l-1);
}


                    
int a[MAXN];
int inva[MAXN];

ll ans[MAXN];

struct event{
    int x,ly,ry;
    int coef;
    int id;
    event(int x,int ly,int ry,int coef,int id):x(x),ly(ly),ry(ry),coef(coef),id(id){
    }
    bool operator<(const event& r) const{
        return x < r.x;
    }
};


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]), inva[a[i]] = i;

    for (int i = 1; i <= n; i++)
        for (int j = 1; i*j <= n; j++)
            d[inva[i*j]].pb(inva[i]);

    vector<event> evs;

    for (int i = 0; i < m; i++){
        int l,r;
        scanf("%d %d",&l,&r);
        --l,--r;
        if (l) evs.pb(event(l-1,l,r,-1,i));
        evs.pb(event(r,l,r,1,i));
    }   

    sort(evs.begin(),evs.end());
    int ptr = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < (int)d[i].size(); j++)
            update(d[i][j]);
        while (ptr < (int)evs.size() && evs[ptr].x == i){
            ans[evs[ptr].id] += evs[ptr].coef * get(evs[ptr].ly,evs[ptr].ry);
            ptr++;
        }
    }

    for (int i = 0; i < m; i++)
        printf(LLD"\n",ans[i]);
      
    TIMESTAMP(end);
    return 0;
}
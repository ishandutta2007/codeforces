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

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "D"

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

struct request {
    int k;
    int* ans;
    request();
    request(int k,int* ans): k(k), ans(ans){
    };
};


struct _node;
typedef _node* node;

struct _node {
    node l,r;
    int cnt,x,y;
    int mycnt;
    _node(){}
    _node(int x):x(x){
        l = r = 0;
        cnt = mycnt = 1;
        y = rand() ^ (rand() << 15);
    }
};

void update(node v){
    v->cnt = v->mycnt;
    if (v->l) v->cnt += v->l->cnt;
    if (v->r) v->cnt += v->r->cnt;
}


node merge(node l, node r){
    if (!l) return r;
    if (!r) return l;
    if (l->y < r->y){
        l->r = merge(l->r, r);
        update(l);
        return l;
    }
    r->l = merge(l, r->l);
    update(r);
    return r;       
}

void split(node v, int x,node& l, node& r){
    if (!v) { l = r = 0; return;}
    if (v->x <= x){
        l = v;
        split(l->r, x, l->r, r);
        update(l);
        return;
    }
    r = v;
    split(r->l, x, l, r->l);
    update(r);
    return;
}

void erase(node& v, int x){
    node l, m, r;
    split(v, x, l, r);
    split(l, x-1, l, m);
    if (m) {
      assert(m->x == x);
      m->mycnt--;
      update(m);
      if (m->mycnt == 0) m = 0;
    }
    v = merge(merge(l, m), r);
}

void insert(node& v, int x){
    node l, m, r;
    split(v, x, l, r);
    split(l, x-1, l, m);
    if (m) {
      m->mycnt++;
      update(m);
      assert(m->x == x);
    }
    else 
      m = new _node(x);
    v = merge(merge(l, m), r);
}

struct Magic {
    map<int, int> col2cnt;
    node cnts;

    void add(int c, int cnt){
        map<int,int>::iterator iter = col2cnt.find(c);
        if (iter != col2cnt.end()){
            erase(cnts, col2cnt[c]);
        }
        col2cnt[c] += cnt;
        insert(cnts, col2cnt[c]);
    }

    void mergeTo(Magic& r){ 
        if (col2cnt.size() < r.col2cnt.size()){
            col2cnt.swap(r.col2cnt);
            swap(cnts, r.cnts);
        }
        for (map<int,int>::iterator iter = r.col2cnt.begin(); iter != r.col2cnt.end(); ++iter)
            add(iter->first, iter->second);
    }

    int getmore(int x){
        node l, r;
        split(cnts, x-1, l, r);
        int ans = 0;
        if (r) ans = r->cnt;
        cnts = merge(l, r);
        #ifdef LOCAL
        int ans2 = 0;
        for (map<int,int>::iterator iter = col2cnt.begin(); iter != col2cnt.end(); ++iter)
            ans2 += (iter->second >= x);
        assert(ans == ans2);
        #endif
        return ans;
    }
};



const int MAXN = 110000;

vector<int> g[MAXN];
vector<request> rq[MAXN];
Magic mag[MAXN];
int color[MAXN];
int ccnt[MAXN];
int ans[MAXN];

void dfs(int v,int p){
    mag[v].add(color[v],1);
    for (int i = 0; i < (int)g[v].size(); i++){
        int to = g[v][i];
        if (to != p){
            dfs(to, v);
            mag[v].mergeTo(mag[to]);
        }
    }
/*  eprintf("%d: ", v+1);
    for (map<int,int>::iterator iter = mag[v].col2cnt.begin(); iter != mag[v].col2cnt.end(); ++iter)
        eprintf("(%d, %d)", iter->first, iter->second);
    eprintf("\n");*/
    for (int i = 0; i < (int)rq[v].size(); i++)
        *rq[v][i].ans = mag[v].getmore(rq[v][i].k);
}



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int n,q;
    scanf("%d %d",&n,&q);
    for (int i = 0; i < n; i++){
        scanf("%d", &color[i]);
    }
    for (int i = 0; i < n-1; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < q; i++){
        int v,k;
        scanf("%d %d",&v,&k);
        rq[v-1].pb(request(k,ans + i));
    }

    dfs(0, -1);
    for (int i = 0; i < q; i++)
        printf("%d\n", ans[i]);
      
    return 0;
}
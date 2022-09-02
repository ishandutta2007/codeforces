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

const int MOD = 95542721;

const int MAXN = 100000;
const int ITER = 48;

struct node{
    node *l,*r;
    int sum;
    node *next;
    //node *p;
};

int a[MAXN][ITER];
node tree[MAXN*3][ITER];
int n;
int lst;

int L,R;

int sum(node* v,int l,int r){
    if (r < L || R < l)
        return 0;
    if (L <= l && r <= R)
        return v->sum;
    return (sum(v->l,l,(l+r)/2) + sum(v->r,(l+r)/2+1,r)) % MOD;
}

node* cube(node* v,int l,int r){
    if (r < L || R < l)
        return v;
    if (L <= l && r <= R)
        return v->next;
    v->l = cube(v->l,l,(l+r)/2);
    v->r = cube(v->r,(l+r)/2+1,r);
    v->sum = v->l->sum + v->r->sum;
    if (v->sum >= MOD) v->sum -= MOD;
    return v;
}

node* root[ITER];

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    #ifndef TEST
    scanf("%d",&n);
    #else
    n = 100000;
    #endif
    for (int i = 0; i < n; i++){
        #ifndef TEST
        scanf("%d",&a[i][0]);
        a[i][0] %= 95542721;
        #else
        a[i][0] = i;
        #endif
        for (int j = 1; j < ITER; j++)
            a[i][j] = (((a[i][j-1] * 1LL * a[i][j-1]) % MOD) * 1LL * a[i][j-1]) % MOD;
    }

    lst = 2;
    while (lst < n) lst *= 2;

    for (int i = 0; i < ITER; i++){
        for (int j = 0; j < n; j++){
            tree[j+lst][i].sum = a[j][i];
            tree[j+lst][i].next = &tree[j+lst][(i+1) % ITER];
//          tree[j+lst][i].p = &tree[(j+lst)/2][i];
        }
        for (int j = lst - 1; j >= 0; j--){
            tree[j][i].sum = tree[2*j][i].sum + tree[2*j+1][i].sum;
            if (tree[j][i].sum >= MOD)
                tree[j][i].sum -= MOD;
            tree[j][i].l = &tree[2*j][i];
            tree[j][i].r = &tree[2*j+1][i];
//          tree[j][i].p = &tree[j/2][i];
            tree[j][i].next = &tree[j][(i+1) % ITER];
        }
    }

    for (int i = 0; i < ITER; i++)
        root[i] = &tree[1][i];

    TIMESTAMP(init);

    int q;
    #ifndef TEST
    scanf("%d",&q);
    #else
    q = 100000;
    #endif

    for (int i = 0; i < q; i++){
        int ty;
        #ifndef TEST
        scanf("%d %d %d",&ty,&L,&R);
        #else
            ty = rand() % 2;
            L = rand() % n;
            R = rand() % n;
            L++, R++;
            if (L > R) swap(L,R);
        #endif
        --L,--R;
        if (ty == 1){
            int res = sum(root[0],0,lst-1);
            printf("%d\n",res);
        } else {
            for (int j = 0; j < ITER; j++)
                root[j] = cube(root[j],0,lst-1);
        }
    }
      
    TIMESTAMP(end);
    return 0;
}
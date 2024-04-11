#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1000100;
const int MAXLST = 1<<20;
const int MAXSZ = MAXLST*2+100;


struct item{
    int cnt4,cnt7;
    int ansu,ansd;
    item(){
        cnt4 = cnt7 = ansu = ansd = 0;
    }
};

item tree[MAXSZ];
bool inv[MAXSZ];


inline void invert(int v){
    inv[v] ^= 1;
    swap(tree[v].cnt4,tree[v].cnt7);
    swap(tree[v].ansu,tree[v].ansd);
}

inline void push(int v){
    if (inv[v]){
        inv[v] = false;
        invert(2*v);
        invert(2*v+1);
    }
}

inline void update(int v){
    item& l = tree[2*v];
    item& r = tree[2*v+1];
    item& p = tree[v];

    p.cnt4 = l.cnt4 + r.cnt4;
    p.cnt7 = l.cnt7 + r.cnt7;
    p.ansu = max(l.ansu+r.cnt7,l.cnt4+r.ansu);
    p.ansd = max(l.ansd+r.cnt4,l.cnt7+r.ansd);
}


void invert(int v,int l,int r,int L,int R){
    if (r < L  || R < l)
        return;
    if (L <= l && r <= R){
        invert(v);
        return;
    }
    push(v);
    invert(2*v,l,(l+r)/2,L,R);
    invert(2*v+1,(l+r)/2+1,r,L,R);
    update(v);
}

char buf[1100000];


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,m;
    gets(buf);
    sscanf(buf,"%d %d",&n,&m);
    int lst = 2;
    while (lst < n)
        lst *= 2;
    gets(buf);
    for (int i = 0; i < n; i++){
        if (buf[i] == '4'){
            tree[lst+i].ansu = tree[lst+i].ansd = tree[lst+i].cnt4 = 1;
            tree[lst+i].cnt7 = 0;
        }
        else {
            tree[lst+i].ansu = tree[lst+i].ansd = tree[lst+i].cnt7 = 1;
            tree[lst+i].cnt4 = 0;
        }
    }

    for (int i = lst-1; i > 0; i--)
        update(i);


    for (int i = 0; i < m; i++){
        int a,b;
        if (scanf(" switch %d %d",&a,&b) == 2)
            invert(1,0,lst-1,a-1,b-1);
        else {
            scanf(" count");
            printf("%d\n",tree[1].ansu);
        }
    }

    return 0;
}
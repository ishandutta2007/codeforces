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

typedef long long int64;
typedef long double ld;

struct _node;

typedef _node* node;

struct _node{
    int x,y;
    int cnt;
    int64 sum;
    node l,r;
    _node(){
        x = y= cnt = 0;
        l=r=0;
    }
    _node(int X){
        x = X;
        y = rand();
        cnt = 1;
        sum = x;
        l=r=0;
    }
    void update(){
        cnt = 1;
        sum = x;
        if (l) cnt += l->cnt,sum += l->sum;
        if (r) cnt += r->cnt,sum += r->sum;
    }
};

int getcnt(node v){
    if (!v)
        return 0;
    return v->cnt;
}

int64 getsum(node v){
    if (!v)
        return 0;
    return v->sum;
}

node merge(node l,node r){
    if (!l) return r;
    if (!r) return l;
    if (l->y > r->y){
        l->r = merge(l->r,r);
        if (l) l->update();
        return l;
    }
    r->l = merge(l,r->l);
    if (r) r->update();
    return r;       
}

void splitval(node v,int x,node& l,node& r){
    if (!v){
        l=r=0;
        return;
    }   
    if (v->x < x){
        l = v;
        splitval(v->r,x,v->r,r);
        if (l) l->update();
        return;
    }
    r = v;
    splitval(v->l,x,l,v->l);
    if (r) r->update();
    return;
}

void splitcnt(node v,int x,node& l,node& r){
    if (!v){
        assert(x == 0);
        l=r=0;
        return;
    }
    if (x == 0){
        r=v;
        l=0;
        return;
    }
    if (v->l){
        if (v->l->cnt >= x){
            r=v;
            splitcnt(v->l,x,l,v->l);
            if (r) r->update();
            return;
        }
        x -= v->l->cnt;
    }
    if (x == 0){
        l = v->l;
        r = v;
        v->l = 0;
        if (l) l->update();
        if (r) r->update();
        return;     
    }
    --x;
    l = v;
    splitcnt(v->r,x,v->r,r);
    if (l) l->update();
    if (r) r->update();
}



node root;

node rt[5];

void add(int x){
    node nn = new _node(x);
    node l[5],r[5];
    node lr,rr;
    splitval(root,x,lr,rr);
    int cnt = getcnt(lr);
    root = merge(merge(lr,nn),rr);
    for (int i=0;i<5;i++)
        splitcnt(rt[i],cnt/5 + (i < cnt%5),l[i],r[i]);
    nn = new _node(x);
    l[cnt%5] = merge(l[cnt%5],nn);
    rotate(r,r+4,r+5);
    for (int i=0;i<5;i++)
        rt[i] = merge(l[i],r[i]);
}

void del(int x){
    node l[5],r[5];
    node lr,mr,rr;
    splitval(root,x,lr,rr);
    int cnt = getcnt(lr);
    splitval(rr,x+1,mr,rr);
    root = merge(lr,rr);
    delete mr;  
    for (int i=0;i<5;i++)
        splitcnt(rt[i],cnt/5 + (i <= cnt%5),l[i],r[i]);
    splitval(l[cnt%5],x,l[cnt%5],mr);
    delete mr;
    rotate(r,r+1,r+5);  
    for (int i=0;i<5;i++)
        rt[i] = merge(l[i],r[i]);
}

void sum(){
    printf(LLD"\n",getsum(rt[2]));  
}

void request(){
    int x;
    if (scanf(" add %d",&x) == 1)
        add(x);
    else if (scanf(" del %d",&x) == 1)
        del(x);
    else {
        scanf(" sum ");
        sum();
    }
}






int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int q;
    scanf("%d",&q);
    for (int i=0;i<q;i++)
        request();
    return 0;
}
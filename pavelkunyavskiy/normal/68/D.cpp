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
typedef double ld;

struct node{
    node *l,*r,*p;
    int sum,val;
    node(){
        l=r=p=NULL;
        sum=val=0;
    }
    void makesons(){
        l = new node();
        r = new node();     
        l->p = r->p = this;
        l->update();
        r->update();
    }
    
    void update(){
        sum = val;
        if (p)
            sum+=p->val;
        if (l){
            sum+=l->sum + r->sum - 2*val;
        }
    }
};

typedef unsigned int uint;

node* root;

void add(uint num,int val){
    uint tmp=1;
    while (tmp <= num && tmp<(1u<<31))
        tmp*=2;
    if (tmp != num)
        tmp>>=1;
    tmp>>=1;
    node* v=root;
    for (;tmp;tmp>>=1){
        if (!v->l)
            v->makesons();
        if (num & tmp)
            v=v->r;
        else
            v=v->l;
    }
    v->val += val;
    if (v->l){
        v->l->update();
        v->r->update();
    }
    for (;v;v=v->p)
        v->update();    
}

ld calc(){
    node* v=root;
    int val=0;
    ld ans=0;
    ld prob=1;
    node *l,*r;
    while (true){
        if (!v->l)
            return ans+prob*max(v->sum-(v->p?v->p->val:0),val);
        l=v->l;
        r=v->r;
        if (l->sum > r->sum)
            swap(l,r);
        if (r->sum <= val)
            return ans+prob*val;
        prob/=2;
        ans+=prob*r->sum;
        val=max(val,l->sum);
        v=r;        
    }
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    root = new node;
    int q,h;
    scanf("%d %d",&h,&q);
    for (int i=0;i<q;i++){
        uint num;
        int e;
        if (scanf(" add %u %d",&num,&e) == 2){
            add(num,e);
        }
        else {
            scanf(" decay");
            ld tmp=calc();
            printf("%.15lf\n",double(tmp));
        }
    }   
    return 0;
}
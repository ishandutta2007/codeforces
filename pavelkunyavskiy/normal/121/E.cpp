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

#define lf(x) ((x)<<1)
#define rg(x) (((x)<<1)|1)
#define par(x) ((x)>>1)


const int MAXN = 110000;
const int MAXLST = 1<<17;
const int MAXSZ = 2*MAXLST + 100; 


vector<int> luck;


int tmax[MAXSZ];
int tcnt[MAXSZ];
int tupd[MAXSZ];
int ptr[MAXN];
int n,m;              
int lst ,sz;

void gen(ll cur){
    if (cur > 10000)
        return;
    if (cur)
        luck.pb(cur);
    gen(10*cur+4);
    gen(10*cur+7);
}


void push(int v){
    if (lf(v) > sz)
        return;
    if (tupd[v]){
        tupd[lf(v)] += tupd[v];
        tmax[lf(v)] += tupd[v]; 
        tupd[rg(v)] += tupd[v];
        tmax[rg(v)] += tupd[v];
        tupd[v] = 0;
    }
}

void update(int v){
    push(v);
    if (lf(v) > sz)
        return;
    if (tmax[lf(v)] > tmax[rg(v)]){
        tmax[v] = tmax[lf(v)];
        tcnt[v] = tcnt[lf(v)];
    }
    else {
        tmax[v] = tmax[rg(v)];
        tcnt[v] = tcnt[rg(v)];
        if (tmax[lf(v)] == tmax[rg(v)])
            tcnt[v] += tcnt[lf(v)]; 
    }
}


void update(int v,int val){
    v = v + lst;
    tmax[v] += val;
    for (v=par(v);v; v = par(v))
        update(v);
}


void update(int v,int l,int r,int L,int R,int val){
    if (r < L || R < l)
        return;
    push(v);
    if (L <= l && r <= R){
        tupd[v] += val;
        tmax[v] += val;
        return;
    }
    update(lf(v),l,(l+r)/2,L,R,val);
    update(rg(v),(l+r)/2+1,r,L,R,val);
    update(v);
}

int getzeros(int v,int l,int r,int L,int R){
    if (r < L || R < l)
        return 0;
    push(v);
    if (L <= l && r <= R){
        if (tmax[v] == 0)
            return tcnt[v];
        return 0;   
    }
    return getzeros(lf(v),l,(l+r)/2,L,R) + getzeros(rg(v),(l+r)/2+1,r,L,R);
    
}


int findmax(){
    int v = 1;
    while (v < lst){
        push(v);
        if (tmax[v] == tmax[lf(v)])
            v = lf(v);
        else
            v = rg(v);
    }
    return v - lst;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d",&n,&m);
    for (lst=2; lst < n; lst*=2);

    sz = 2*lst - 1;
//  cerr << lst <<" "<<sz << endl;


    gen(0);
    sort(luck.begin(),luck.end());


    for (int i = 0; i < n; i++){
        scanf("%d",&tmax[lst+i]);
        tmax[lst+i] = tmax[lst+i] - luck[0];
        tcnt[lst+i] = 1;
        tupd[lst+i] = 0;
        ptr[i] = 0;
    }


    for (int i = n; i < lst; i++)
        tmax[i+lst] = -100000;

    for (int i = lst-1; i > 0; --i)
        update(i);



    for (int i = 0; i < m; i++){
        //cerr << i << endl;
        int a,b,c;
        if (scanf(" add %d %d %d",&a,&b,&c) == 3){
            --a,--b;
            update(1,0,lst-1,a,b,c);
        }
        else {
            int l,r;
            scanf(" count %d %d",&l,&r);
            --l,--r;
            while (tmax[1] > 0){
                int id = findmax();
                ++ptr[id];
                if (ptr[id] == luck.size())
                    update(id,-100000);
                else
                    update(id,luck[ptr[id]-1] - luck[ptr[id]]);
            }

            printf("%d\n",getzeros(1,0,lst-1,l,r));
        }

        //for (int j = 1; j <= sz; j++)
    //      cerr << tmax[j] <<" \n"[!(j&(j+1))];


    }
    
    
    
    return 0;
}
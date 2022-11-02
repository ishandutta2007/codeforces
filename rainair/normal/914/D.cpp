#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

namespace fastIO{ 
    #define BUF_SIZE 100000 
    #define OUT_SIZE 100000 
    #define ll long long 
    bool IOerror=0; 
    inline char nc(){ 
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE; 
        if (p1==pend){ 
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin); 
            if (pend==p1){IOerror=1;return -1;} 
        } 
        return *p1++; 
    } 
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';} 
    inline void read(int &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    inline void read(ll &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    #undef ll 
    #undef OUT_SIZE 
    #undef BUF_SIZE 
}; 
using namespace fastIO;

const int MAXN = 500000 + 5;

struct SegmentTree *New(int ,int ,SegmentTree *,SegmentTree *);

LL qgcd(LL x,LL y){
    if(!y) return x;
    return qgcd(y,x%y);
}

int cnt;

struct SegmentTree{
    int l,r;
    LL gcd;
    SegmentTree *lc,*rc;

    static SegmentTree *build(int l,int r){
        int mid = (l + r) >> 1;
        return (l == r) ? New(l,r,NULL,NULL) : New(l,r,build(l,mid),build(mid+1,r));
    }

    inline void pushup(){
        gcd = qgcd(lc->gcd,rc->gcd);
    }

    inline void update(LL x,int pos){
        if(l == r){
            gcd = x;
            return;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid) lc->update(x,pos);
        else rc->update(x,pos);
        pushup();
    }

    bool query(int L,int R,int g){
        // int mid = (L + R) >> 1;
        // if(l == r) return !(gcd % g);
        // if(L == l && R == r){
        //     if(!(gcd % g)) cnt++;
        //     return cnt <= 1;
        // }
        if(l == r){
            if(!(gcd % g)) return true;
            return (++cnt) <=1;
        }
        int mid = (l + r) >> 1;
        if(L == l && R == r){
            if(g == gcd) return true;
            if(!(lc->gcd % g)) return rc->query(mid + 1,R,g);
            if(!(rc->gcd % g)) return lc->query(L,mid,g);
            return false;
        }
        if(R <= mid) return lc->query(L,R,g);
        else if(L > mid) return rc->query(L,R,g);
        return lc->query(L,mid,g) && rc->query(mid + 1,R,g);
    }
}pool[(MAXN<<2) + 1],*frog = pool,*segt;

SegmentTree *New(int l,int r,SegmentTree *lc,SegmentTree *rc){
    SegmentTree *ret = ++frog;
    ret->l = l;ret->r = r;
    ret->lc = lc;ret->rc = rc;
    // ret->gcd = -1;
    return ret;
}

int N,Q;

int main(){
    read(N);
    segt = SegmentTree::build(1,N);
    FOR(i,1,N){
        LL x;read(x);
        segt->update(x,i);
    }
    read(Q);
    while(Q--){
        int l,r,opt;read(opt);read(l);read(r);
        if(!(opt & 1)){
            // segt->update(l,r);
            segt->update(r,l);
        }
        else{
            LL x;read(x);cnt = 0;
            printf("%s\n",segt->query(l,r,x) ? "YES" : "NO");
        }
    }
    return 0;
}

/*
2 6 3


*/
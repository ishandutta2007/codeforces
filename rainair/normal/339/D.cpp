#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define R register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(R int i = a;i <= b;++i)
#define RFOR(i,a,b) for(R int i = a;i >= b;--i)
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

const int MAXN = 1 << 17;

struct SegmentTree;
SegmentTree *New(LL ,LL ,SegmentTree *,SegmentTree *);

struct SegmentTree{
    LL l,r,val;
    SegmentTree *lc,*rc;

    static SegmentTree *build(LL l,LL r){
        LL mid = (l + r) >> 1;
        return (l == r) ? New(l,r,NULL,NULL) : New(l,r,build(l,mid),build(mid+1,r));
    }

    inline void pushup(LL opt){
        if(opt == 1) val = lc->val^rc->val;
        else val = lc->val|rc->val;
    }

    void update(LL pos,LL x,LL opt){
        if(l == r){
            val = x;
            return;
        }
        LL mid = (l + r) >> 1;
        if(pos <= mid) lc->update(pos,x,-opt);
        else rc->update(pos,x,-opt);
        pushup(opt);
    }

    LL query(LL left,LL right){
        if(left == l and right == r) return val;
        LL mid = (l + r) >> 1;
        if(right <= mid) return lc->query(l,r);
        if(left > mid) return rc->query(l,r);
        return query(l,mid)^query(mid+1,r);
    }
}pool[MAXN << 2],*frog = pool,*segt;

SegmentTree *New(LL l,LL r,SegmentTree *lc,SegmentTree *rc){
    SegmentTree *ret = ++frog;
    ret->l = l;ret->r = r;
    ret->lc = lc;ret->rc = rc;
    return ret;
}

LL N,M;

int main(){
    read(N);read(M);
    LL opt = (N & 1) ? -1ll : 1ll;
    N = 1 << N;
    segt = SegmentTree::build(1,N);
    FOR(i,1,N){
        int x;read(x);
        segt->update(i,x,opt);
    }
    while(M--){
        int pos,x;
        read(pos);read(x);
        segt->update(pos,x,opt);
        printf("%I64d\n",segt->query(1,N));
    }
    return 0;
}
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5e5 + 5;
int mx[MAXN<<2],tag[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void build(int x,int l,int r){
    tag[x] = 0;mx[x] = r-1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
}

inline void cover(int x,int d){
    mx[x] += d;tag[x] += d;
}

inline void pushdown(int x){
    if(tag[x]){
        cover(lc,tag[x]);
        cover(rc,tag[x]);
        tag[x] = 0;
    }
}

inline void modify(int x,int l,int r,int L,int R,int d){
    if(l == L && r == R){cover(x,d);return;}
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) modify(lc,l,mid,L,R,d);
    else if(L > mid) modify(rc,mid+1,r,L,R,d);
    else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    mx[x] = std::max(mx[lc],mx[rc]);
}

inline int query(int x,int l,int r,int L,int R){
    if(L > R) return 0;
    if(l == L && r == R) {return mx[x];}
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return std::max(query(lc,l,mid,L,mid),query(rc,mid+1,r,mid+1,R));
}

int n,k,m;
std::map<P,int> S;
std::multiset<int> SS;

int main(){
    scanf("%d%d%d",&n,&k,&m);
    build(1,1,2*n);SS.insert(n);
    FOR(i,1,m){
        int x,y;scanf("%d%d",&x,&y);
        int t = y+std::abs(k-x);
//        DEBUG(t);
        if(S[MP(x,y)]){
            modify(1,1,2*n,1,t,-1);
            SS.erase(SS.find(t));
        }
        else{
            modify(1,1,2*n,1,t,1);
            SS.insert(t);
        }
        S[MP(x,y)] ^= 1;
        printf("%d\n",query(1,1,2*n,1,*SS.rbegin()+1)-n);
    }
    return 0;
}
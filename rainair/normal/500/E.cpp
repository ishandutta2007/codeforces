/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-21 09:55:30
 */
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

const int MAXN = 2e5 + 5;
int p[MAXN],l[MAXN],n,q;

struct Node{
    int l,r,id;
    bool operator < (const Node &t) const {
        return l > t.l;
    }
}a[MAXN];

#define lc ((x)<<1)
#define rc ((x)<<1|1)
int sm[MAXN<<2];

inline void pushup(int x){
    sm[x] = sm[lc]+sm[rc];
}

inline void update(int x,int l,int r,int ps,int d){
    if(l == r){
        sm[x] = d;
        return;
    }
    int mid = (l + r) >> 1;
    if(ps <= mid) update(lc,l,mid,ps,d);
    else update(rc,mid+1,r,ps,d);
    pushup(x);
}

inline int query(int x,int l,int r,int L,int R){
    if(L > R) return 0;
    if(l == L && r == R) return sm[x];
    int mid = (l + r) >> 1;
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R);
}

std::stack<int> S;
int r[MAXN];
int f[MAXN],ans[MAXN];

inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

inline void merge(int x,int y){ // x is root
    int fx = find(x),fy = find(y);
    if(fx == fy) return;
    f[fy] = fx;
}

inline void add(int x){
    while(!S.empty() && p[S.top()] <= r[x]){
        r[x] = std::max(r[x],r[S.top()]);
        merge(x,S.top());
        update(1,1,n,S.top(),0);
        S.pop();
    }
    if(!S.empty()) update(1,1,n,x,std::max(0,p[S.top()]-r[x]));
    S.push(x);
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",p+i,l+i),r[i] = l[i]+p[i],f[i] = i;
    scanf("%d",&q);
    FOR(i,1,q) scanf("%d%d",&a[i].l,&a[i].r),a[i].id = i;
    std::sort(a+1,a+q+1);int now = n;
    //FOR(i,1,q) printf("%d %d\n",a[i].l,a[i].r);
    FOR(i,1,q){
        while(now >= 1 && now >= a[i].l){
            add(now--);
        }
//        DEBUG(now+1);DEBUG(a[i].l);
//        assert(now+1 == a[i].l);
        ans[a[i].id] = query(1,1,n,a[i].l,find(a[i].r)-1);
    }
    FOR(i,1,q) printf("%d\n",ans[i]);
    return 0;
}
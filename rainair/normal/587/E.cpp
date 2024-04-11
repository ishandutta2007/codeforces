#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
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
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 200000+5;

#define lc (x<<1)
#define rc (x<<1|1)

int base[MAXN<<2][60],cnt[MAXN<<2],a[MAXN],b[MAXN],A[66],B[66];
int n,q;

inline void merge(int z,int x,int y){ //z = x + y
    int tot = 0;
    FOR(i,1,cnt[x]) A[tot++] = base[x][i];
    FOR(i,1,cnt[y]) A[tot++] = base[y][i];
    CLR(B,0);
    FOR(i,0,tot-1){
        ROF(j,29,0){
            if(A[i]>>j & 1){
                if(!B[j]){
                    B[j] = A[i];
                    break;
                }
                else A[i] ^= B[j];
            }
        }
    }
    cnt[z] = 0;
    FOR(i,0,29) if(B[i]) base[z][++cnt[z]] = B[i];
}

inline void build(int x,int l,int r){
    if(l == r){
        if(b[l]) base[x][++cnt[x]] = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    merge(x,lc,rc);
}

inline void update(int x,int l,int r,int pos,int val){
    if(l == r){
        base[x][1] ^= val;
        cnt[x] = (base[x][1] > 0);
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) update(lc,l,mid,pos,val);
    else update(rc,mid+1,r,pos,val);
    merge(x,lc,rc);
}

inline void query(int x,int l,int r,int L,int R){
    if(L > R) return;
    if(l == L && r == R){
        merge(0,x,0);return;
    }
    int mid = (l + r) >> 1;
    if(R <= mid) query(lc,l,mid,L,R);
    else if(L > mid) query(rc,mid+1,r,L,R);
    else query(lc,l,mid,L,mid),query(rc,mid+1,r,mid+1,R);
}

struct BIT{
    #define lowbit(x) (x&-x)
    int tree[MAXN<<2];
    
    BIT(){CLR(tree,0);}

    inline void add(int pos,int x){
        while(pos <= n){
            tree[pos] ^= x;
            pos += lowbit(pos);
        }
    }

    inline int calc(int pos){
        int res = 0;
        while(pos){
            res ^= tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
}bit;

int main(){
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n-1) b[i] = a[i]^a[i+1];
    if(n > 1) build(1,1,n-1);
    while(q--){
        int opt,l,r,x;
        scanf("%d%d%d",&opt,&l,&r);
        if(opt & 1){
            scanf("%d",&x);
            if(l > 1) update(1,1,n-1,l-1,x);
            if(r < n) update(1,1,n-1,r,x);
            bit.add(l,x);bit.add(r+1,x);
        }
        else{
            cnt[0] = 0;
            int t = bit.calc(l)^a[l];
            if(t) base[0][++cnt[0]] = t;
            if(n > 1) query(1,1,n-1,l,r-1);
            printf("%d\n",1<<cnt[0]);
        }
    }
    return 0;
}
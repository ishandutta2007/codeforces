/*
 * Author: RainAir
 * Time: 2019-07-18 16:09:40
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
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define B std::bitset<62>
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 5e5 + 5;
const int ha = 1e9 + 7;
#define lc (x<<1)
#define rc (x<<1|1)
B S[MAXN<<2],tag2[MAXN<<2];
int sm[MAXN<<2],tag1[MAXN<<2];
int a[MAXN],n,q;B b[MAXN];

inline int qpow(int a,int n=ha-2){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%ha;
        a = 1ll*a*a%ha;
        n >>= 1;
    }
    return res;
}

inline void pushup(int x){
    S[x] = S[lc]|S[rc];
    sm[x] = 1ll*sm[lc]*sm[rc]%ha;
}

inline void build(int x,int l,int r){
    S[x].reset();sm[x] = 1;tag1[x] = 1;tag2[x].reset();
    if(l == r){
        sm[x] = a[l];
        S[x] = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(x);
}

inline void cover1(int x,int l,int r,int d){
    sm[x] = 1ll*sm[x]*qpow(d,(r-l+1))%ha;
    tag1[x] = 1ll*tag1[x]*d%ha;
}

inline void cover2(int x,int l,int r,B d){
    S[x] |= d;tag2[x] |= d;
}

inline void pushdown(int x,int l,int r){
    int mid = (l + r) >> 1;
    if(tag1[x] != 1){
        cover1(lc,l,mid,tag1[x]);
        cover1(rc,mid+1,r,tag1[x]);
        tag1[x] = 1;
    }
    if(tag2[x].count()){
        cover2(lc,l,mid,tag2[x]);
        cover2(rc,mid+1,r,tag2[x]);
        tag2[x].reset();
    }
}

inline void modify(int x,int l,int r,int L,int R,int d,B b){
    if(l == L && r == R){
        cover1(x,l,r,d);cover2(x,l,r,b);
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(x,l,r);
    if(R <= mid) modify(lc,l,mid,L,R,d,b);
    else if(L > mid) modify(rc,mid+1,r,L,R,d,b);
    else modify(lc,l,mid,L,mid,d,b),modify(rc,mid+1,r,mid+1,R,d,b);
    pushup(x);
}

inline int query1(int x,int l,int r,int L,int R){
    if(l == L && r == R) return sm[x];
    int mid = (l + r) >> 1;
    pushdown(x,l,r);
    if(R <= mid) return query1(lc,l,mid,L,R);
    if(L > mid) return query1(rc,mid+1,r,L,R);
    return 1ll*query1(lc,l,mid,L,mid)*query1(rc,mid+1,r,mid+1,R)%ha;
}

inline B query2(int x,int l,int r,int L,int R){
    if(l == L && r == R) return S[x];
    int mid = (l + r) >> 1;
    pushdown(x,l,r);
    if(R <= mid) return query2(lc,l,mid,L,R);
    if(L > mid) return query2(rc,mid+1,r,L,R);
    return query2(lc,l,mid,L,mid)|query2(rc,mid+1,r,mid+1,R);
}

const int MAXM = 300+5;
bool p[MAXN];
int prime[MAXN],cnt;
int ys[MAXN];

inline void prework(){
    FOR(i,2,300){
        if(!p[i]) prime[cnt++] = i;
        for(int j = 0;j < cnt && i*prime[j] <= 300;++j){
            p[i*prime[j]] = true;
            if(!(i%prime[j])) break;
        }
    }
    cnt--;FOR(i,0,cnt) ys[prime[i]] = i;
}

inline B calc(int x){
    B res;res.reset();
    FOR(i,0,cnt) if(!(x%prime[i])) res[i] = 1;
    return res;
}

char str[1231];

signed main(){
    prework();
    scanf("%lld%lld",&n,&q);
    FOR(i,1,n){
        scanf("%lld",a+i);
        b[i] = calc(a[i]);
    }build(1,1,n);
    FOR(i,1,q){
        scanf("%s",str+1);int l,r;scanf("%lld%lld",&l,&r);
        if(str[1] == 'M'){
            int x;scanf("%lld",&x);
            B t = calc(x);
            modify(1,1,n,l,r,x,t);
        }
        else{
            int t1 = query1(1,1,n,l,r);B t2 = query2(1,1,n,l,r);
            LL ans = 1ll;
            FOR(i,0,61){
                int p = prime[i];
                if(t2[i]) ans = 1ll*ans*(p-1)%ha*qpow(p)%ha;
            }
            ans = 1ll*ans*t1%ha;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
//dwdwx
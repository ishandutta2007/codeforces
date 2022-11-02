#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 3e5 + 5;
int h[MAXN],n,b[MAXN];
LL f[MAXN];
int st[MAXN],tp;
LL pre[MAXN],mx[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",h+i);
    FOR(i,1,n) scanf("%d",b+i);
    pre[0] = -1e18;
    FOR(i,1,n){
        LL tmx = f[i-1];
        while(tp && h[st[tp]] >= h[i]){
            tmx = std::max(tmx,mx[tp]);
            --tp;
        }
        st[++tp] = i;mx[tp] = tmx;
        pre[tp] = std::max(pre[tp-1],mx[tp]+b[i]);
        f[i] = pre[tp];
    }
    printf("%lld\n",f[n]);
    return 0;
}
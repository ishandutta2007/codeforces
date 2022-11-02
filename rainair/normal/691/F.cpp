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

const int MAXN = 3e6 + 5;
int a[MAXN],n,m = 3e6;
int f[MAXN];LL g[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),++f[a[i]];
    FOR(i,1,m){
        FOR(j,1,m){
            if(1ll*i*j > m) break;
            g[i*j] += 1ll*f[i]*f[j];
        }
    }
    FOR(i,1,n) if(1ll*a[i]*a[i] <= m) --g[a[i]*a[i]];
    FOR(i,1,m) g[i] += g[i-1];
    int q;scanf("%d",&q);
    while(q--){
        int x;scanf("%d",&x);
        printf("%lld\n",1ll*n*(n-1)-g[x-1]);
    }
    return 0;
}
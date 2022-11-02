#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5e5 + 5;
int n,a[MAXN];
LL f[MAXN];

inline bool chk(){
    FOR(i,1,n) f[i] = a[i]-f[i-1];
    FOR(i,1,n) if(f[i] < 0) return 0;
    if(f[n] != 0) return 0;
    return 1;
}

LL mn[MAXN];

inline void Solve(){
    scanf("%d",&n);FOR(i,1,n) scanf("%d",a+i);
    if(chk()) {puts("YES");return;}
    mn[n+1] = mn[n+2] = 1e18;
    ROF(i,n,1) mn[i] = std::min(mn[i+2],f[i]);
    FOR(i,2,n){
        if(f[i-2] < 0) break;
        LL gx = 2*a[i]-2*a[i-1];
        if(f[n]+((n-i)&1?1:-1)*gx != 0) continue;
        if(a[i]-f[i-2] < 0) continue;
        if(a[i-1]-(a[i]-f[i-2]) < 0) continue;
        if(mn[i+1]+gx < 0) continue;
        if(mn[i+2]-gx < 0) continue;
        puts("YES");return;
    }
    puts("NO");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}
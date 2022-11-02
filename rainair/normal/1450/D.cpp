#include <bits/stdc++.h>

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

const int MAXN = 3e5 + 5;
int n,a[MAXN];
bool vis[MAXN];
bool f[MAXN];
int cnt[MAXN];

inline void Solve(){
    scanf("%d",&n);FOR(i,1,n) cnt[i] = 0;
    FOR(i,1,n) scanf("%d",a+i),vis[i] = 0,++cnt[a[i]];
    FOR(i,1,n) vis[a[i]] = 1,f[i] = 0;f[0] = 1;
    int sm = 0;
    FOR(i,1,n) f[i] = f[i-1]&vis[i],sm += vis[i];
    std::reverse(f+1,f+n+1);
    int l = 1,r = n,now = 1;
    while(l <= r){
        if(a[l] != now && a[r] != now) break;
        --cnt[now];
        if(cnt[now]) break;
        if(a[l] == now) ++l,++now;
        else if(a[r] == now) --r,++now;
    }
    --now;
    FOR(i,1,n-now-1) f[i] = 0;
    if(sm == n) f[1] = 1;
    if(vis[1]) f[n] = 1;
    FOR(i,1,n) putchar('0'+f[i]);puts("");
}

int main(){
    int T;scanf("%d",&T);while(T--) Solve();
    return 0;
}
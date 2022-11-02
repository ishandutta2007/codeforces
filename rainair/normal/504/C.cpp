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

const int MAXN = 1e5 + 5;
int n,a[MAXN];
int cnt[MAXN];
int c1[MAXN],c2,c3,k;

inline LL solve(){
    LL res = 0;
    int p = n>>1;
    while(a[p] == a[n-p+1]) --p;CLR(c1,0);
    CLR(c1,0);c2 = c3 = 0;
    auto add1 = [&](int x,int d){
        if(c1[x]) --c2;
        if(c1[x] < 0) --c3;
        c1[x] += d;
        if(c1[x]) ++c2;
        if(c1[x] < 0) ++c3;
    };
    FOR(i,k,p-1) add1(a[i],1),add1(a[n-i+1],-1);
    FOR(i,p,(n>>1)){
        add1(a[i],1);add1(a[n-i+1],-1);
        if(!c2){
            return 1ll*k*(n-i+1);
        }
    }
    if(n&1){
        int p = (n+1)>>1;
        add1(a[p],1);
        if(c2 == 1) return 1ll*k*(n-p+1);
    }
    FOR(i,((n+1)>>1)+1,n-k+1){
        add1(a[i],2);
        if(!c3){
            return 1ll*k*(n-i+1);
        }
    }
    return 0;
}

int main(){
    scanf("%d",&n);FOR(i,1,n) scanf("%d",a+i),cnt[a[i]] ^= 1;
    int sm = 0;FOR(i,1,n) sm += cnt[i];
    if(sm > 1){
        puts("0");
        return 0;
    }
    bool flag = 1;
    FOR(i,1,n) flag &= (a[i] == a[n-i+1]);
    if(flag){
        printf("%lld\n",1ll*n*(n+1)/2);
        return 0;
    }
    k = 1;while(a[k] == a[n-k+1]) ++k;
    LL ans = solve();
    std::reverse(a+1,a+n+1);
    ans += solve();
    ans -= 1ll*k*k;
    printf("%lld\n",ans);
    return 0;
}
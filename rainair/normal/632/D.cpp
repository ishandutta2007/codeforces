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

const int MAXN = 1e6 + 5;
int a[MAXN],n,m;

inline int gcd(int x,int y){
    return !y ? x : gcd(y,x%y);
}

inline int lcm(int x,int y){
    return x/gcd(x,y)*y;
}

std::vector<int> G[MAXN];
int cnt[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("%d",a+i);
        if(a[i] <= m) ++cnt[a[i]],G[a[i]].pb(i);
    }
    ROF(i,m,1){
        for(int j = i;j <= m;j += i){
            cnt[j] += cnt[i];
        }
    }
    int ans = 0,ps = -1;
    FOR(i,1,m) if(ans < cnt[i]) ans = cnt[i],ps = i;
    if(ps == -1){
        puts("1 0");
        return 0;
    }
    int q = std::sqrt(1.0*ps);std::vector<int> S;
    int l = 1;
    FOR(i,1,q){
        if(!(ps%i)){
            for(auto x:G[i]) S.pb(x);
            l = lcm(l,i);
            l = lcm(l,ps/i);
            if(i != ps/i) for(auto x:G[ps/i]) S.pb(x);
        }
    }
    printf("%d %d\n",l,SZ(S));
    std::sort(all(S));
    for(auto x:S) printf("%d ",x);puts("");
    return 0;
}
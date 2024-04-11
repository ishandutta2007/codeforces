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

const int MAXN = 2e5 + 5;
int n,m,a,b;
int s[MAXN];

inline void Solve(){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    FOR(i,1,m) scanf("%d",s+i),++s[i];
    std::sort(s+1,s+m+1);std::reverse(s+1,s+m+1);
    if(a > b) a = n-a+1,b = n-b+1;
    int ans = 0,now = b-1;
    FOR(i,1,m){
        if(now < s[i]) continue;
        if(now < a+1) break;
        ++ans;--now;
    }
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}
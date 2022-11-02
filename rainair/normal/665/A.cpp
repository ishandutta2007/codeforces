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

int main(){
    int a,ta,b,tb;scanf("%d%d%d%d",&a,&ta,&b,&tb);
    int h,m;scanf("%d:%d",&h,&m);
    m += h*60;int ans = 0;
    int l = m-tb+1,r = m+ta-1;
    for(int i = 5*60;i <= 23*60+59;i += b){
        ans += (l <= i && i <= r);
    }
    printf("%d\n",ans);
    return 0;
}
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

const int c[] = {6,2,5,5,4,5,6,3,7,6};
int l,r;

inline int calc(int x){
    int res = 0;
    while(x) res += c[x%10],x /= 10;
    return res;
}

int main(){
    scanf("%d%d",&l,&r);
    LL ans = 0;
    FOR(i,l,r) ans += calc(i);
    printf("%lld\n",ans);
    return 0;
}
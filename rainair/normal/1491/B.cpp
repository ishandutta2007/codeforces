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

const int MAXN = 100+5;
int n,a[MAXN];

inline void Solve(){
    int u,v;
    scanf("%d%d%d",&n,&u,&v);
    FOR(i,1,n) scanf("%d",a+i);
    bool flag = 1;
    FOR(i,2,n) flag &= std::abs(a[i]-a[i-1])<=1;
    if(!flag){
        puts("0");
        return;
    }
    flag = 1;
    FOR(i,2,n) flag &= a[i] == a[i-1];
    if(flag){
        printf("%d\n",std::min(u+v,2*v));
        return;
    }
    printf("%d\n",std::min(u,v));
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}
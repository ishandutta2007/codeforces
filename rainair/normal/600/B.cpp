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

const int MAXN = 2e5 + 5;
int n,m,a[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);std::sort(a+1,a+n+1);
    FOR(i,1,m){
        int x;scanf("%d",&x);
        printf("%ld%c",std::upper_bound(a+1,a+n+1,x)-a-1," \n"[i==m]);
    }
    return 0;
}
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
    int n,m,mx = 0;
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        int mn = 1e9;
        FOR(j,1,m){
            int x;scanf("%d",&x);
            mn = std::min(mn,x);
        }
        mx = std::max(mx,mn);
    }
    printf("%d\n",mx);
    return 0;
}
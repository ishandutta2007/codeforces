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
std::vector<P<int,int> > S1,S2;

int main(){
    int n;scanf("%d",&n);
    FOR(i,1,n) FOR(j,1,n){
        if((i+j)&1) S1.pb(i,j);
        else S2.pb(i,j);
    }
    int a;scanf("%d",&a);int b = 1;while(b == a) ++b;
    printf("%d %d %d\n",b,S2.back().fi,S2.back().se);S2.pop_back();
    std::fflush(stdout);
    while(!S1.empty() && !S2.empty()){
        int ban;scanf("%d",&ban);
        if(ban != a){
            printf("%d %d %d\n",a,S1.back().fi,S1.back().se);
            S1.pop_back();
        }
        else{
            printf("%d %d %d\n",b,S2.back().fi,S2.back().se);
            S2.pop_back();
        }
        std::fflush(stdout);
    }
    int c = 1;while(c == a || c == b) ++c;
    for(auto x:S1){
        int ban;scanf("%d",&ban);
        int now = 0;
        if(ban == a) now = c;
        else now = a;
        printf("%d %d %d\n",now,x.fi,x.se);
        std::fflush(stdout);
    }
    for(auto x:S2){
        int ban;scanf("%d",&ban);
        int now = 0;
        if(ban == b) now = c;
        else now = b;
        printf("%d %d %d\n",now,x.fi,x.se);
        std::fflush(stdout);
    }
    return 0;
}
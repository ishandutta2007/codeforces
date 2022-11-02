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

const int MAXN = 100+5;
int n,k,m;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    std::vector<int> S;
    FOR(i,1,k){
        int x;scanf("%d",&x);S.pb(x);
    }
    int ans = 0;
    FOR(i,1,n){
        FOR(j,1,m){
            int x;scanf("%d",&x);
            auto p = std::find(all(S),x);
            ans += p-S.begin()+1;
            S.erase(p);
            S.insert(S.begin(),x);
//            for(auto x:S) DEBUG(x);
        }
    }
    printf("%d\n",ans);
    return 0;
}
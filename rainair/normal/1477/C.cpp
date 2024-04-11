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

const int MAXN = 5000+5;
LL x[MAXN],y[MAXN];
bool vis[MAXN];
int n;
#define pw(x) ((x)*(x))

inline LL dis2(int i,int j){
    return pw(x[i]-x[j])+pw(y[i]-y[j]);
}

int main(){
    scanf("%d",&n);FOR(i,1,n) scanf("%lld%lld",x+i,y+i);
    int las = 1;printf("%d ",las);vis[1] = 1;
    FOR(i,2,n){
        LL mx = 0;int ps = -1;
        FOR(j,1,n){
            if(vis[j]) continue;
            if(mx < dis2(las,j)){
                mx = dis2(las,j);
                ps = j;
            }
        }
        las = ps;printf("%d ",las);vis[las] = 1;
    }
    puts("");
    return 0;
}
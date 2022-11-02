#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100+5;
int n,x[MAXN],y[MAXN],k;

inline void Solve(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d%d",x+i,y+i);
    FOR(i,1,n){
        int mx = 0;
        FOR(j,1,n) mx = std::max(mx,std::abs(x[i]-x[j])+std::abs(y[i]-y[j]));
        if(mx <= k){
            puts("1");
            return;
        }
    }
    puts("-1");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}
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

const int MAXN = 5e6 + 5;
int n,a[MAXN];
P<int,int> G[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    int now = 0,cnt = 0;
    FOR(i,1,n){
        FOR(j,i+1,n){
            if(G[a[i]+a[j]].fi){
                int x = G[a[i]+a[j]].fi,y = G[a[i]+a[j]].se;
                if(x == i || x == j || y == i || y == j) continue;
                puts("YES");
                printf("%d %d %d %d\n",i,j,x,y);
                exit(0);
            }
            else{
                G[a[i]+a[j]] = MP(i,j);
                ++cnt;
            }
            if(cnt > 5000000) break;
        }
        if(cnt > 5000000) break;
    }
    puts("NO");
    return 0;
}
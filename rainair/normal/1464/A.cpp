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

const int MAXN = 1e5 + 5;
int f[MAXN];

inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,m;scanf("%d%d",&n,&m);
        FOR(i,1,n) f[i] = i;
        int ans = 0;
        FOR(i,1,m){
            int x,y;scanf("%d%d",&x,&y);
            if(x == y) continue;
            x = find(x);y = find(y);
            if(x == y) ans++;
            f[x] = y;++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
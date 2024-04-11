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

int n;
char str[50];
int F[50],sz[50];

inline int find(int x){
    return x == F[x] ? x : F[x] = find(F[x]);
}

inline void merge(int x,int y){
    x = find(x);y = find(y);
    if(x == y) return;
    F[y] = x;sz[x] += sz[y];
}

std::vector<int> G[55];
int id[66];
int e[25];
int f[(1<<23)+5],g[(1<<23)+5],coe[(1<<23)+5];

int main(){
    scanf("%d",&n);
    FOR(i,0,n-1) F[i] = i,sz[i] = 1;
    FOR(i,0,n-1){
        scanf("%s",str);
        FOR(j,i+1,n-1){
            if(str[j] == 'A') merge(i,j);
            if(str[j] == 'X') G[i].pb(j),G[j].pb(i);
        }
    }
    int ans = n-1;n = 0;
    FOR(i,0,ans) id[i] = find(i);
    FOR(i,0,ans) for(auto x:G[i]) if(id[i] == id[x]){puts("-1");exit(0);}
    FOR(i,0,ans){
        if(sz[id[i]] == 1){id[i] = -1;continue;}
        if(id[i] != i){id[i] = id[id[i]];continue;}
        id[i] = n++;
    }
    if(n <= 1){
        printf("%d\n",ans+n);
        return 0;
    }
    assert(n <= 23);
    FOR(i,0,ans) for(auto x:G[i]) if(~id[i] && ~id[x]) e[id[i]] |= (1<<id[x]);
    f[0] = coe[0] = 1;
    FOR(S,1,(1<<n)-1){
        int lb = __builtin_ctz(S);
        f[S] = (!(e[lb]&S))&f[S^(1<<lb)];
        coe[S] = -coe[S^(1<<lb)];
    }
    FOR(i,0,n-1){
        FOR(S,0,(1<<n)-1){
            if((S>>i)&1) f[S] += f[S^(1<<i)];
        }
    }
    FOR(i,0,(1<<n)-1) g[i] = f[i];
    FOR(k,1,n){
        auto chk = [&](){
            int ans = 0;
            FOR(S,0,(1<<n)-1) ans += g[S]*coe[S];
            return ans!=0;
        };
        if(chk()){
            printf("%d\n",ans+k);
            return 0;
        }
        FOR(S,0,(1<<n)-1) g[S] *= f[S];
    }
    return 0;
}
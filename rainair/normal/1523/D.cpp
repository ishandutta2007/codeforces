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

const int MAXN = 2e5 + 5;
const int MAXM = 15 + 1;
int n,m;
std::vector<int> G[MAXN];
std::mt19937 g(0);
int id[MAXN];
int f[(1<<MAXM)+1];
int ps[MAXN];
char str[233];

int main(){
    scanf("%d%d%*d",&n,&m);
    FOR(i,1,n){
        scanf("%s",str);
        FOR(j,0,m-1) if(str[j] == '1') G[i].pb(j);
        id[i] = i;
    }
    std::shuffle(id+1,id+n+1,g);
    int mx = 0;LL ans = 0;
    FOR(i,1,std::min(30,n)){
        int sz = SZ(G[id[i]]);
        FOR(i,0,m-1) ps[i] = -1;
        FOR(j,0,sz-1) ps[G[id[i]][j]] = j;
        FOR(j,0,(1<<sz)-1) f[j] = 0;
        FOR(j,1,n){
            int t = 0;
            for(auto x:G[id[j]]){
                if(ps[x] == -1) continue;
                t |= 1<<ps[x];
            }
            ++f[t];
        }
        FOR(i,0,sz-1){
            FOR(S,0,(1<<sz)-1){
                if(!((S>>i)&1)) f[S] += f[S^(1<<i)];
            }
        }
        bool flag = 0;
        FOR(S,1,(1<<sz)-1){
            if(f[S] >= (n+1)/2 && __builtin_popcount(S) > mx){
                mx = __builtin_popcount(S);
                ans = S;
                flag = 1;
            }
        }
        if(flag){
            int tmp = ans;ans = 0;
            FOR(j,0,sz-1) if((tmp>>j)&1) ans |= 1ll<<G[id[i]][j];
        }
    }
    FOR(i,0,m-1) putchar('0'+((ans>>i)&1));puts("");
    return 0;
}
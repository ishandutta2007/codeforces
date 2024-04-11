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

const int MAXN = 3e5 + 5;
const int MAXM = 18;
int f[MAXN][MAXM+1],dep[MAXN];
int a[MAXN],c[MAXN];
int q;

inline int get(int v,int d){
    FOR(i,0,MAXM) if((d>>i)&1) v = f[v][i];
    return v;
}

int main(){
    scanf("%d%d%d",&q,a+1,c+1);
    dep[1] = 1;
    FOR(i,2,q+1){
        int o;scanf("%d",&o);
        if(o == 1){
            scanf("%d%d%d",&f[i][0],a+i,c+i);++f[i][0];
            dep[i] = dep[f[i][0]] + 1;
            FOR(j,1,MAXM) f[i][j] = f[f[i][j-1]][j-1];
        }
        else{
            int v,w;scanf("%d%d",&v,&w);int t = w;++v;
            LL ans = 0;
            int p = v;
            ROF(i,MAXM,0) if(a[f[p][i]]) p = f[p][i];
            while(w){
                if(w <= a[p]){
                    a[p] -= w;
                    ans += 1ll*w*c[p];
                    w = 0;
                    break;
                }
                w -= a[p];
                ans += 1ll*a[p]*c[p];
                a[p] = 0;
                if(p == v) break;
                p = get(v,dep[v]-dep[p]-1);
            }
            printf("%d %lld\n",t-w,ans);
            std::fflush(stdout);
        }
    }
    return 0;
}
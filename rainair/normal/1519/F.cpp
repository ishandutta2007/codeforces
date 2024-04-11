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

const int MAXN = 7 + 1;
const int MAXM = 78125 + 233;
int pw[MAXN];
int f[2][MAXM],now;
int n,m;
int a[MAXN],b[MAXN],c[MAXN][MAXN];

inline int encode(std::vector<int> vec){
    int res = 0;
    FOR(i,0,m-1) res += pw[i]*vec[i];
    return res;
}

inline std::vector<int> decode(int S){
    std::vector<int> res;
    FOR(i,0,m-1) res.pb(S%5),S /= 5;
    return res;
}

std::vector<std::vector<int> > G[MAXN];
std::vector<int> tmp;

inline void dfs(int o,int step,int s){
    if(step == m+1){
        if(!s) G[o].pb(tmp);
        return;
    }
    FOR(i,0,s){
        tmp.pb(i);
        dfs(o,step+1,s-i);
        tmp.pop_back();
    }
}

int main(){
    pw[0] = 1;FOR(i,1,7) pw[i] = 5ll*pw[i-1];
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,m) scanf("%d",b+i);
    FOR(i,1,n) FOR(j,1,m) scanf("%d",&c[i][j]);
    FOR(i,1,4) dfs(i,1,i);
    std::vector<int> tmp;FOR(i,1,m) tmp.pb(b[i]);
    CLR(f,0x7f);
    f[now = 0][encode(tmp)] = 0;
    FOR(i,1,n){
        CLR(f[now^1],0x7f);
        FOR(j,0,pw[m+1]-1){
            int c = f[now][j];
            if(c == 0x7f7f7f7f) continue;
            std::vector<int> vec = decode(j);
            for(auto x:G[a[i]]){
                bool flag = 1;
                FOR(k,0,m-1) flag &= (vec[k] >= x[k]);
                if(!flag) continue;
                std::vector<int> tmp = vec;
                int gx = 0;
                FOR(k,0,m-1){
                    tmp[k] -= x[k];
                    if(x[k]) gx += ::c[i][k+1];
                }
                int nxt = encode(tmp);
                f[now^1][nxt] = std::min(f[now^1][nxt],c+gx);
            }
        }
        now ^= 1;
    }
    int ans = 0x7f7f7f7f;
    FOR(i,0,pw[m+1]-1) ans = std::min(ans,f[now][i]);
    if(ans == 0x7f7f7f7f) ans = -1;
    printf("%d\n",ans);
    return 0;
}
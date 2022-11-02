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
const int MAXM = 1e7 + 5;
int n,k,a[MAXN];
bool p[MAXM];int prime[MAXM],cnt,d[MAXM];

inline void prework(){
    FOR(i,2,MAXM-1){
        if(!p[i]) prime[++cnt] = i,d[i] = i;
        for(int j = 1;j <= cnt && 1ll*i*prime[j] < MAXM;++j){
            p[i*prime[j]] = 1;d[i*prime[j]] = prime[j];
            if(!(i%prime[j])) break;
        }
    }
}

inline int work(int x){
    int las = -1,ans = 1,c = 0;
    while(x != 1){
        int p = d[x];
        if(p != las){
            if(las != -1 && (c&1)) ans *= las;
            las = p;c = 1;
        }
        else ++c;
        x /= p;
    }
    if(las != -1 && (c&1)) ans *= las;
    return ans;
}

int f[21][MAXN],pre[MAXN][21];
std::map<int,int> lst;

int main(){
    prework();
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        FOR(i,1,n) scanf("%d",a+i),a[i] = work(a[i]);
        lst.clear();
        FOR(i,1,n){
            FOR(j,0,k) pre[i][j] = pre[i-1][j];
            int t = lst[a[i]],p = -1;
            FOR(j,0,k) if(pre[i][j] < t){p = j;break;}
            if(p != -1){
                ROF(j,k-1,p) pre[i][j+1] = pre[i][j];
                pre[i][p] = t;
            }
            lst[a[i]] = i;
        }
        FOR(i,0,k) FOR(j,0,n) f[i][j] = 1e9;
        FOR(i,0,k){
            f[i][0] = 0;
            FOR(j,1,n){
                FOR(x,0,i){
                    f[i][j] = std::min(f[i][j],f[i-x][pre[j][x]]+1);
                }
            }
        }
        printf("%d\n",f[k][n]);
    }
    return 0;
}
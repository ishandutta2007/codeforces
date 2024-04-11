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

const int MAXN = 3000+5;
const int ha = 998244353;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int n,c,a[MAXN],ans[MAXN];

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

namespace Subtask1{
    int pw[MAXN],ipw[MAXN];
    int f[MAXN][MAXN];
    int g[MAXN][MAXN];

    int cnt[MAXN],now,c0;

    inline void reset(){
        CLR(cnt,0);now = 1;c0 = c;
    }

    inline void insert(int x){
        if(!cnt[x]) --c0;
        else now = 1ll*now*ipw[cnt[x]]%ha;
        ++cnt[x];
        now = 1ll*now*pw[cnt[x]]%ha;
    }

    inline void Solve(){
        pw[0] = 1;FOR(i,1,MAXN-1) pw[i] = 2ll*pw[i-1]%ha;
        FOR(i,0,MAXN-1) add(pw[i],ha-1),ipw[i] = qpow(pw[i]);
        FOR(l,1,n){
            reset();
            FOR(r,l,n){
                insert(a[r]);
                if(!c0) g[r][l] = 1ll*now*ipw[cnt[a[r]]]%ha;
            }
        }
        f[0][0] = 1;
        FOR(i,1,n){
            FOR(k,0,i-c){
                FOR(j,0,i/c) add(f[i][j],1ll*f[k][j-1]*g[i][k+1]%ha);
            }
            /*
            FOR(j,1,i/c){
                FOR(k,0,i-1) add(f[i][j],1ll*f[k][j-1]*g[i][k+1]%ha);
            }*/
        }
        reset();
        ROF(i,n,1){
            int gx = (pw[n-i]+1)%ha;
            if(!c0) add(gx,ha-now);
            FOR(j,1,i/c){
                add(ans[j],1ll*f[i][j]*gx%ha);
            }
            insert(a[i]);
        }
        ans[0] = pw[n];
        FOR(i,1,n) add(ans[0],ha-ans[i]);
        FOR(i,0,n) printf("%d\n",ans[i]);
    }
}

const int MAXM = 6;

namespace Subtask2{
    int f[2][MAXN][(1<<MAXM)+3],now;
    inline void Solve(){
        now = 0;f[now][0][0] = 1;
        FOR(i,1,n){
            CLR(f[now^1],0);
            FOR(j,0,(i-1)/c){
                FOR(S,0,(1<<c)-2){
                    int t = f[now][j][S];
                    if(!t) continue;
                    add(f[now^1][j][S],t);
                    int nxt = S|(1<<(a[i]-1));
                    if(nxt == (1<<c)-1) add(f[now^1][j+1][0],t);
                    else add(f[now^1][j][nxt],t);
                }
            }
            now ^= 1;
        }
        FOR(i,0,n/c) FOR(S,0,(1<<c)-2) add(ans[i],f[now][i][S]);
        add(ans[0],ha-1);
        FOR(i,0,n) printf("%d\n",ans[i]);
    }
}

int main(){
    scanf("%d%d",&n,&c);
    FOR(i,1,n) scanf("%d",a+i);
    if(c > MAXM) Subtask1::Solve();
    else Subtask2::Solve();
    return 0;
}
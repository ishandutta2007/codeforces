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
const int MAXM = 100 + 5;
const int ha = 1e9 + 7;
int n,m,a[MAXN];
int ans[MAXM][MAXN];
int C[MAXM][MAXM],fac[MAXN],inv[MAXN];

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int tmp[MAXN],res[MAXN];

int main(){
    C[0][0] = 1;
    FOR(i,1,100){
        C[i][0] = 1;
        FOR(j,1,i){
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%ha;
        }
    }
    fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
    inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,m){
        int l,r,k;scanf("%d%d%d",&l,&r,&k);
        int t = 1;
        FOR(i,0,k){
            int coe = 1ll*t*inv[k]%ha*C[k][i]%ha;
            add(ans[k-i][l],coe);add(ans[k-i][r+1],ha-coe);
            t = 1ll*t*(k-l-i+ha)%ha;
        }
    }
    FOR(i,0,100) FOR(j,1,n) add(ans[i][j],ans[i][j-1]);
    FOR(i,1,n) tmp[i] = 1;
    FOR(k,0,100){
        FOR(i,1,n) add(res[i],1ll*tmp[i]*ans[k][i]%ha);
        FOR(i,1,n) tmp[i] = 1ll*tmp[i]*(i-k)%ha;
    }
    FOR(i,1,n) add(res[i],a[i]),printf("%d%c",res[i]," \n"[i==n]);
    return 0;
}
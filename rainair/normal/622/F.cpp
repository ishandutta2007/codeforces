#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
const int ha = 1e9 + 7;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int n,k;
int y[MAXN];
int pre[MAXN],suf[MAXN];
int fac[MAXN],inv[MAXN];

int main(){
    fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
    inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
    scanf("%d%d",&n,&k);
    if(!k){
        printf("%d\n",n%ha);
        return 0;
    }
    FOR(i,1,k+1) y[i] = (y[i-1]+qpow(i,k))%ha;
    if(n <= k+1){
        printf("%d\n",y[n]);
        return 0;
    }
    int up = 1;
    int ans = 0;
    FOR(i,0,k+1) up = 1ll*up*(n-i+ha)%ha;
    FOR(i,0,k+1){
        int t = 1ll*up*qpow(n-i)%ha*y[i]%ha;
        t = 1ll*t*inv[i]%ha*inv[k+1-i]%ha;
        if((k+1-i)&1) t = ha-t;
        (ans += t) %= ha;
    }
    printf("%d\n",ans);
    return 0;
}
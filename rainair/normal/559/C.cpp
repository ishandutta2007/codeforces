#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 3e5 + 5;
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

int fac[MAXN],inv[MAXN];

inline void prework(){
    fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
    inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

inline int C(int n,int m){
    return (n < 0 || m < 0 || n < m) ? 0 : 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

int h,w,n;
P a[MAXN];
int f[MAXN];

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

int main(){
    prework();
    scanf("%d%d%d",&h,&w,&n);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
    std::sort(a+1,a+n+1);
    if(a[n].fi == h && a[n].se == w){
        puts("0");return 0;
    }
    a[++n] = MP(h,w);
    FOR(i,1,n){
        f[i] = C(a[i].fi+a[i].se-2,a[i].fi-1);
        FOR(j,1,i-1){
            if(a[j].se <= a[i].se) add(f[i],ha-1ll*f[j]*C(a[i].fi-a[j].fi+a[i].se-a[j].se,a[i].fi-a[j].fi)%ha);
        }
    }
    printf("%d\n",f[n]);
    return 0;
}
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

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

int fac[MAXN],inv[MAXN];

inline void prework(){
    fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
    inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

inline int C(int n,int m){
    return (n < 0 || m < 0 || n < m) ? 0 : 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

char str[MAXN];
int n,m;

int main(){
    prework();
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    int B1=0,W2=0,p=0;
    FOR(i,1,n){
        B1 += (str[i] == 'b' && (i&1));
        W2 += (str[i] == 'w' && (!(i&1)));
        p += (str[i] == '?');
    }
    int ans = 0;
    FOR(x,0,n){
        int c = C(p,x),d = std::abs(x-(n/2)+B1+W2);
        if(d&1) continue;
        c = 1ll*c*d%ha;
        add(ans,c);
    }
    ans = 1ll*ans*qpow(qpow(2,p))%ha;
    printf("%d\n",ans);
    return 0;
}
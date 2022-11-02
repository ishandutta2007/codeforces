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

const int MAXN = 5000+5;
int vis[MAXN];
// 1: > 
// -1: <
const int ha = 1e9 + 7;
int fac[MAXN],inv[MAXN];

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

inline void prework(){
    fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
    inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
}

inline int C(int n,int m){
    return (n < 0 || m < 0 || n < m) ?0 : 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

int main(){
    prework();
    int n,x,p;scanf("%d%d%d",&n,&x,&p);
    int l = 0,r = n;
    while(l < r){
        int mid = (l + r) >> 1;
        if(p >= mid){
            vis[mid+1] = -1;
            l = mid+1;
        }
        else{
            r = mid;
            vis[mid+1] = 1;
        }
    }
    int c0 = 0,c1 = 0;
    FOR(i,1,n){
        if(i == p+1) continue;
        if(vis[i] == -1) c0++;
        if(vis[i] == 1) c1++;
    }
    int c2 = n-1-c0-c1;
    int ans = 1;
    ans = 1ll*ans*C(x-1,c0)%ha*fac[c0]%ha;
    ans = 1ll*ans*C(n-x,c1)%ha*fac[c1]%ha;
    ans = 1ll*ans*fac[c2]%ha;
    printf("%d\n",ans);
    return 0;
}
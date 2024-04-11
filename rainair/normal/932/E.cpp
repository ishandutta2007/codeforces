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

const int MAXN = 5000+5;
const int ha = 1e9 + 7;
const int inv2 = (ha+1)>>1;
int a[MAXN],n,k;
int S[MAXN][MAXN];

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int main(){
    S[0][0] = 1;
    FOR(i,1,MAXN-1){
        S[i][0] = 0;S[i][1] = 1;
        FOR(j,2,i){
            S[i][j] = (1ll*j*S[i-1][j]%ha+S[i-1][j-1])%ha;
        }
    }
    int n,k;scanf("%d%d",&n,&k);
    int ans = 0,pw = qpow(2,n),nn = 1;
    FOR(i,0,k){
        (ans += 1ll*pw*S[k][i]%ha*nn%ha) %= ha;
        pw = 1ll*pw*inv2%ha;
        nn = 1ll*nn*(n-i)%ha;
    }
    printf("%d\n",ans);
    return 0;
}
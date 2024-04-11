#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

const int MAXN = 4e6 + 5;
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

char str[MAXN];
int fac[MAXN],inv[MAXN];

inline int C(int n,int m){
    if(n < 0 || m < 0 || n < m) return 0;
    if(!m) return 1;
    return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

int sm[MAXN][3];
int ctoi[256];

int main(){
    fac[0] = 1;FOR(i,1,MAXN-1) fac[i] = 1ll*fac[i-1]*i%ha;
    inv[MAXN-1] = qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i] = 1ll*inv[i+1]*(i+1)%ha;
    scanf("%s",str+1);int n = strlen(str+1);
    ctoi['('] = 0;ctoi[')'] = 1;ctoi['?'] = 2;
    FOR(i,1,n){
        FOR(j,0,2) sm[i][j] = sm[i-1][j];
        sm[i][ctoi[str[i]]]++;
    }
    int ans = 0;
    FOR(i,1,n){
        int x = sm[i][ctoi['?']],y = sm[n][ctoi['?']]-x;
        int l = sm[i][ctoi['(']],r = sm[n][ctoi[')']]-sm[i][ctoi[')']];
//        DEBUG(x);DEBUG(y);DEBUG(l);DEBUG(r);
        (ans += 1ll*l*C(x+y,y-l+r)%ha) %= ha;
        (ans += 1ll*x*C(x+y-1,y-l+r-1)%ha) %= ha;
    }
    printf("%d\n",ans);
    return 0;
}
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

const int MAXN = 20 + 5;
const int MAXM = 5e4 + 5;
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

int a[MAXM][MAXN];
int n,m;

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[j][i]);
    FOR(i,1,m) std::sort(a[i]+1,a[i]+n+1);
    int ans = 0,all = 1;FOR(i,1,n) all = 1ll*all*i%ha;
    all = qpow(all);
    FOR(i,1,m){
        int sm = 1;
        FOR(j,1,n){
            if(a[i][j]-j <= 0) sm = 0;
            else sm = 1ll*sm*(a[i][j]-j)%ha;
        }
        (ans += 1ll*all*sm%ha) %= ha;
    }
    ans = (m-ans+ha)%ha;
    printf("%d\n",ans);
    return 0;
}
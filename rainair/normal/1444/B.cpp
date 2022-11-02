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
int a[MAXN],n;

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

int main(){
    scanf("%d",&n);
    FOR(i,1,2*n) scanf("%d",a+i);
    std::sort(a+1,a+2*n+1);
    int ans = 0;
    FOR(i,1,n) add(ans,ha-a[i]);
    FOR(i,n+1,2*n) add(ans,a[i]);
    FOR(i,1,2*n) ans = 1ll*ans*i%ha;
    int t = 1;FOR(i,1,n) t = 1ll*t*i%ha;
    t = qpow(t);ans = 1ll*ans*t%ha*t%ha;
    printf("%d\n",ans);
    return 0;
}
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

int a,b,ha;LL x;

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
    scanf("%d%d%d%lld",&a,&b,&ha,&x);
    int ia = qpow(a),aa = ia;LL ans = 0;
    FOR(i,1,std::min(x,(LL)ha-1)){// n % (ha-1) = i
        int t = 1ll*b*aa%ha;
        LL step = (x-i)/(ha-1);
        LL dis = (i-t+ha)%ha;
        if(step >= dis){
            step -= dis;
            ans++;
            ans += step/ha;
        }
        aa = 1ll*aa*ia%ha;
    }
    printf("%lld\n",ans);
    return 0;
}
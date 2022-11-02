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

inline int qpow(int a,int n){
	int res = 1;
	while(n){
		if(n & 1) res = res*a;
		a = a*a;
		n >>= 1;
	}
	return res;
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;--c;
        printf("%d %d\n",qpow(10,a),qpow(10,b)+qpow(10,c));
    }
    return 0;
}
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

const int MAXN = 6e5 + 5;
const int ha = 998244353;
int n,a[MAXN];

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
    FOR(i,1,n) scanf("%d",a+i);
    std::sort(a+1,a+n+1);std::reverse(a+1,a+n+1);
    FOR(i,1,2*n) (a[i] += a[i-1]) %= ha;
    FOR(i,1,n){
        int ans = 0;
        for(int k = i+1,c=1;k<=n;k+=i,++c) (ans += 1ll*c*(a[k+i-1]-a[k-1]+ha)%ha) %= ha;
//        DEBUG(ans);
        ans = 1ll*ans*qpow(n)%ha;
        printf("%d ",ans);
    }
    puts("");
    return 0;
}
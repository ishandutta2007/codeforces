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
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
inline void Solve(){
	int n,x,y;scanf("%lld%lld%lld",&n,&x,&y);
	printf("%lld %lld\n",n-std::max(1ll,std::min(n,n-x+1+n-y+1-2))+1,std::min(n,x+y-1));
}

signed main(){
	int T;scanf("%lld",&T);
	while(T--) Solve();
	return 0;
}
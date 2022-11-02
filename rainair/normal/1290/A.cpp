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

const int MAXN = 3500+5;

LL a[MAXN],t[MAXN];

inline void Solve(){
	LL ans = 0;
	int n,m,k;scanf("%d%d%d",&n,&m,&k);k = std::min(k,m-1);++k;
	int freep = m-k;
	FOR(i,1,n) t[i] = a[i] = 0;
	FOR(i,1,n) scanf("%lld",a+i);
	FOR(i,1,m) t[i] = std::max(a[i],a[n-m+i]);
	FOR(i,1,k){
		LL t = 1e18;
		FOR(j,i,i+freep) t = std::min(t,::t[j]);
		ans = std::max(ans,t);
	}
	printf("%lld\n",ans);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}
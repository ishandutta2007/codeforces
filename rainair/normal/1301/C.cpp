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
int n,m;
signed main(){
	int T;scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		int ans = n*(n+1)/2;
		n -= m;
		int mid = n/(m+1);
		int ext = n%(m+1);
		ans -= (m-ext+1)*(mid)*(mid+1)/2;
		ans -= 1ll*ext*(mid+1)*(mid+2)/2;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0000
 */
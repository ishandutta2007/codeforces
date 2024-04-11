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

const int MAXN = 1e5 + 5;

int a[MAXN],b[MAXN];
int n,m;
bool in[MAXN];

inline void Solve(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) in[i] = false;
	FOR(i,1,n) scanf("%d",a+i);
	FOR(i,1,m) scanf("%d",b+i);
	int tp = 1;LL ans = 0;
	int sz = 0;
	FOR(i,1,m){
		if(in[b[i]]){
			sz--;
			ans++;continue;
		}
		int cnt = sz;
		while(tp <= n && b[i] != a[tp]){
			in[a[tp]] = true;
			++sz;
			++tp;++cnt;
		}
		++tp;
		ans += cnt*2+1;
	}
	printf("%lld\n",ans);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}
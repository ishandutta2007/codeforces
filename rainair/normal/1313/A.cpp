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
int a[MAXN];bool vis[233][233];
inline bool cmp(int x,int y){
	return x > y;
}

inline void Solve(){
	CLR(vis,0);
	FOR(i,0,2) scanf("%d",a+i);
	int ans = 0;
	FOR(i,0,2) if(a[i]) a[i]--,ans++;
	std::sort(a,a+3,cmp);
	FOR(i,1,3) FOR(j,0,2) FOR(k,j+1,2){
		if(vis[j][k]) continue;
		if(a[j]&&a[k]) --a[j],--a[k],++ans,vis[j][k] = 1;
	}
	if(a[0] && a[1] && a[2]) ++ans;
	printf("%d\n",ans);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}
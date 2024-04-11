#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000+5;
char str[MAXN];
int T,N;

inline void Solve(){
	scanf("%d",&N);scanf("%s",str+1);
	int ans = INT_MAX;
	// >
	int cnt = 0;
	while(str[cnt+1] == '<') cnt++;
	ans = std::min(ans,cnt);
	std::reverse(str+1,str+N+1);
	cnt = 0;
	while(str[cnt+1] == '>') cnt++;
	ans = std::min(ans,cnt);
	printf("%d\n",ans);
}

int main(){
	scanf("%d",&T);
	while(T--) Solve();
	return 0;
}
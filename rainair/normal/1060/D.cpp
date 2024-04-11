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
#define RFOR(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

LL N;
const int MAXN = 100000 + 5;
LL l[MAXN],r[MAXN];
LL ans = 0;
int main(){
	scanf("%I64d",&N);
	FOR(i,1,N){
		scanf("%I64d%I64d",l+i,r+i);
	}
	std::sort(l+1,l+N+1);
	std::sort(r+1,r+N+1);
	FOR(i,1,N){
		ans += std::max(l[i],r[i]);
	}
	printf("%I64d\n",ans+N);
	return 0;
}
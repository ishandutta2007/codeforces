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


int main(){
	LL N;scanf("%I64d",&N);
	LL a=0,b=0;
	while(N >= a){
		a = a * 10 + 9;// DEBUG(a);
	}
	if(a > N) a /= 10;
	b = N - a;
	LL ans = 0ll;
	while(a){
		ans += a%10;
		a /= 10;	
	}
	while(b){
		ans += b%10;
		b /= 10;
	}
	printf("%I64d\n",ans);
	return 0;
}
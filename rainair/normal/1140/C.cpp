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

const int MAXN = 1e6 + 5;
#define int LL
int t[MAXN],b[MAXN],N,K;
LL ans,min;

struct Node{
	int t,b;

	bool operator < (const Node &t) const {
		return b > t.b;
	}
}a[MAXN];

std::priority_queue<int,std::vector<int>,std::greater<int> > q;
int maxlen,sum;

signed main(){
	scanf("%I64d%I64d",&N,&K);
	FOR(i,1,N) scanf("%I64d%I64d",&a[i].t,&a[i].b);
	std::sort(a+1,a+N+1);
	FOR(i,1,K){
		q.push(a[i].t);sum += a[i].t;
		ans = std::max(ans,sum*a[i].b);
	}
	FOR(i,K+1,N){
		int x = q.top();
		if(x < a[i].t){
			q.pop();q.push(a[i].t);
			sum -= x;sum += a[i].t;
			ans = std::max(ans,a[i].b*sum);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
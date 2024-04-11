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

const int MAXN = 100000+5;
int N,K;

struct Node{
	int a,b;

	bool operator < (const Node &other) const {
		if(a == other.a) return b > other.b;
		return a < other.a;
	}
}node[MAXN];
std::priority_queue<int,std::vector<int>,std::greater<int> > q;
bool job[MAXN];
int main(){
	scanf("%d%d",&N,&K);
	FOR(i,1,N) scanf("%d",&node[i].a);
	FOR(i,1,N) scanf("%d",&node[i].b);
	std::sort(node + 1,node + N + 1);
	LL ans = 0,last = node[1].a;
	job[node[1].a] = true;
	FOR(i,2,N){
		if(node[i].a == node[i-1].a) q.push(node[i].b);
		job[node[i].a] = true;
	}
	int cnt = 0;
	FOR(i,1,K) if(!job[i]) cnt++;
	FOR(i,1,cnt) ans += q.top(),q.pop();
	printf("%I64d\n",ans);
	// system("pause");
	return 0;
}
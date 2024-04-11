#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int main(){
	std::priority_queue<LL> q;
	int n;scanf("%d",&n);LL tag = 0;
	FOR(i,1,n){
		LL x;scanf("%lld",&x);x -= i;
		q.push(x);
		if(q.top() > x){
			tag += q.top()-x;
			q.pop();
			q.push(x);
		}
	}
	printf("%lld\n",tag);
	return 0;
}
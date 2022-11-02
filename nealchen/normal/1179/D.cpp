#include <cstdio>
#include <vector>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
#define SQR(x) ((long long)(x)*(x))
struct Point {
	int x;
	long long y;
	Point operator-(const Point &o) const {return {x-o.x, y-o.y};}
	bool operator<(const Point &o) const {return x<o.x||x==o.x&&y<o.y;}
	long long operator&(const Point &o) const {return x*o.y-y*o.x;}
};
const int N=5e5;
int n, size[N];
long long f[N], ans;
std::vector<int> c[N];
std::vector<Point> slist;
Point stack[N], *stacktop;
int F() {
	int a=0;
	unsigned char c;
	while((c=getchar()-'0')>9);
	while(a=a*10+c, (c=getchar()-'0')<10);
	return a;
}
void add(const Point &p) {
	while(stacktop-stack>=2&&(stacktop[-1]-stacktop[-2]&p-stacktop[-1])>=0) --stacktop;
	*stacktop++=p;
}
long long query(long long k) {
	while(stacktop-stack>=2&&stacktop[-1].y-stacktop[-1].x*k>=stacktop[-2].y-stacktop[-2].x*k) --stacktop;
	return stacktop[-1].y-stacktop[-1].x*k;
}
void dfs(int x) {
	auto cmin=[](long long &a, long long b) {if(b<a) a=b;};
	size[x]=1;
	for(int i: c[x]) {
		std::remove(c[i].begin(), c[i].end(), x);
		c[i].pop_back();
		dfs(i);
		size[x]+=size[i];
	}
	f[x]=SQR(size[x]);
	slist.clear();
	for(int i: c[x]) {
		f[x]=std::min(f[x], SQR(size[x]-size[i])+f[i]);
		slist.push_back({size[i], f[i]});
		cmin(ans, SQR(n-size[i])+f[i]);
	}
	std::sort(slist.begin(), slist.end());
	stacktop=stack;
	for(auto p: slist) {
		if(stack!=stacktop) cmin(ans, query(p.x)+SQR(p.x)+p.y);
		add({n-p.x<<1, SQR(n-p.x)+p.y});
	}
}
int main() {
	n=F();
	for(int i=1, j=0; i<n; ++i) {
		int u=F()-1, v=F()-1;
		c[u].push_back(v);
		c[v].push_back(u);
	}
	ans=(long long)n*n;
	dfs(0);
	printf("%I64d\n", (n*(2ll*n-1)-ans)/2);
	return 0;
}
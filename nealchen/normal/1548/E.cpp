#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;
//const int P=;
//inline int &inc(int &a, int b) {return (a+=b)<P?a:(a-=P);}
//inline int &dec(int &a, int b) {return (a-=b)<0?(a+=P):a;}
//inline int add(int a, int b) {return (a+=b)<P?a:a-P;}
//inline int sub(int a, int b) {return (a-=b)<0?a+P:a;}
//u64 power(u64 a, int b) {
//	u64 ans=1;
//	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
//	return ans;
//}

struct Group {
	std::vector<int> x, y, min[18], max[18];
	int query_min(int l, int r) {
		int lv=__builtin_clz(r-l)^31;
		l=min[lv][l];
		r=min[lv][r-(1<<lv)];
		return x[l]<x[r]?l:r;
	}
	int query_max(int l, int r) {
		int lv=__builtin_clz(r-l)^31;
		return std::max(max[lv][l], max[lv][r-(1<<lv)]);
	}
	void dfs(int l, int r) {
		if(l==r) return;
		int mid=query_min(l, r);
		dfs(l, mid);
		dfs(mid+1, r);
		if(l!=0) y[mid]=std::min(y[mid], query_max(l, mid+1));
		if(r<(int)x.size()) y[mid]=std::min(y[mid], query_max(mid, r));
	}
	Group(int n) {
		x.resize(n);
		y.resize(n, 1e9);
		std::generate(x.begin(), x.end(), rd);
		max[0]=x;
		min[0].resize(n);
		for(int i=0; i<n; ++i) min[0][i]=i;
		for(int i=0; (2<<i)<=n; ++i) {
			int m=n-(2<<i)+1;
			min[i+1].resize(m);
			max[i+1].resize(m);
			for(int j=0; j<m; ++j) {
				int u=min[i][j], v=min[i][j+(1<<i)];
				min[i+1][j] = x[u]<x[v]?u:v;
				max[i+1][j] = std::max(max[i][j], max[i][j+(1<<i)]);
			}
		}
		dfs(0, n);
	}
};
struct Point {
	int type, x, y;
	bool operator<(const Point &o) const {
		return x<o.x || (x==o.x && type<o.type);
	}
};

int x;
long long ans;
std::vector<Point> p;
void dc(int l, int r) {
	if(r-l==1) return;
	int mid=(l+r)/2;
	dc(l, mid);
	dc(mid, r);
	std::vector<Point> q;
	q.reserve(r-l);
	int i=l, j=mid, cnt=0;
	while(i<mid && j<r) {
		if(p[i].y<p[j].y || (p[i].y==p[j].y && p[i].type<p[j].type)) {
			if(!p[i].type) ++cnt;
			q.push_back(p[i++]);
		} else {
			if(p[j].type) ans+=cnt;
			q.push_back(p[j++]);
		}
	}
	while(i<mid) q.push_back(p[i++]);
	for(; j<r; q.push_back(p[j++])) {
		if(p[j].type) ans+=cnt;
	}
	std::copy(q.begin(), q.end(), p.begin()+l);
}
int main() {
	int n=rd(), m=rd();
	x=rd();
	Group ver(n), hor(m);
	p.resize(n+m);
	for(int i=0; i<n; ++i) p[i]={0, x-ver.y[i]+1, x-ver.x[i]+1};
	for(int i=0; i<m; ++i) p[n+i]={1, hor.x[i], hor.y[i]};
	std::sort(p.begin(), p.end());
	dc(0, n+m);
	std::sort(ver.x.begin(), ver.x.end());
	std::sort(hor.x.begin(), hor.x.end());
	int j=m;
	for(int i : ver.x) {
		while(j>0 && i+hor.x[j-1]>x) --j;
		ans-=m-j;
	}
	printf("%lld\n", ans);
	return 0;
}
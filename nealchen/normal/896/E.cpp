#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
struct Point {
	unsigned char num, root;
};
const int N=1e5+400, K=254, B=400;
int n, a[N], f[B][N], max[B], tag[B], pre[N], pos[N];
Point v[400][N];
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar(), c-'0'>9&c!='-');
	for(a=(b=c=='-')?0:c-'0'; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
void merge(int p, int a, int b) {
	Point x=v[p][a], y=v[p][b];
	if(x.root==0) return;
	if(y.root) {
		pre[x.root+p*K-1]=y.root+p*K-1;
	} else {
		y.root=x.root;
		pos[y.root+p*K-1]=b;
	}
	y.num+=x.num;
	v[p][a]=(Point){};
	v[p][b]=y;
}
int find(int x) {
	return pre[x]==x?x:(pre[x]=find(pre[x]));
}
void pushdown(int x) {
	int l=x*K, r=std::min(n, (x+1)*K);
	for(int i=l; i<r; ++i) {
		a[i]=pos[find(i)];
		v[x][a[i]]=(Point){};
		a[i]-=tag[x];
	}
	memset(pre+l, 0, (r-l)*sizeof(int));
	tag[x]=0;
}
void build(int x) {
	int l=x*K, r=std::min(n, (x+1)*K);
	max[x]=0;
	for(int i=l; i<r; ++i) {
		cmax(max[x], a[i]);
		if(v[x][a[i]].root==0) {
			pre[i]=i;
			v[x][a[i]].root=i-l+1;
			pos[i]=a[i];
		} else {
			pre[i]=v[x][a[i]].root+l-1;
		}
		++v[x][a[i]].num;
	}
}
int main() {
	int (*rd)()=read<int>, m;
	n=rd(), m=rd();
	std::generate(a, a+n, rd);
	for(int i=0; i*K<n; ++i) build(i);
	while(m--) {
		int op=rd(), l=rd()-1, r=rd(), x=rd(), bl=l/K, br=r/K;
		if(op==1) {
			if(bl==br) {
				pushdown(bl);
				for(int i=l; i<r; ++i) if(a[i]>x) a[i]-=x;
				build(bl);
			} else {
				pushdown(bl);
				pushdown(br);
				for(int i=l, r=std::min(n, (bl+1)*K); i<r; ++i) if(a[i]>x) a[i]-=x;
				for(int i=br*K; i<r; ++i) if(a[i]>x) a[i]-=x;
				build(bl);
				build(br);
				for(int i=bl+1; i<br; ++i) {
					if(2*x<=max[i]-tag[i]) {
						for(int j=tag[i]+1; j<=tag[i]+x; ++j) merge(i, j, j+x);
						tag[i]+=x;
					} else {
						for(int j=max[i]; j>tag[i]+x; --j) merge(i, j, j-x);
						cmin(max[i], tag[i]+x);
					}
				}
			}
		} else {
			int ans=0;
			if(bl==br) {
				for(int i=l; i<r; ++i) ans+=pos[find(i)]-tag[bl]==x;
			} else {
				for(int i=l, r=std::min(n, (bl+1)*K); i<r; ++i) ans+=pos[find(i)]-tag[bl]==x;
				for(int i=br*K; i<r; ++i) ans+=pos[find(i)]-tag[br]==x;
				for(int i=bl+1; i<br; ++i) if(x+tag[i]<=1e5) ans+=v[i][x+tag[i]].num;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
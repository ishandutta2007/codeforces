#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
const int N=1e5;
int n, m, k, p, off, h[N], a[N], heap[1<<18];
long long cur[N], ddl[1<<17];
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
void update(int x) {
	heap[x]=heap[x<<1|ddl[heap[x<<1|1]]<ddl[heap[x<<1]]];
}
bool check(long long x) {
	long long t=0;
	std::fill(cur, cur+n, x);
	for(int i=0; i<n; ++i) ddl[i]=x/a[i];
	std::fill(ddl+n, ddl+off, m);
	for(int i=0; i<off; ++i) heap[off+i]=i;
	for(int i=off; --i; update(i));
	for(int i=1, j; i<=m; ++i) {
		t+=k;
		if(i<m) {
			while(ddl[j=heap[1]]==i) {
				if(t==0) return false;
				--t;
				cur[j]+=p;
				ddl[j]=cur[j]/a[j];
				for(int k=j|off; k>>=1; update(k));
			}
		} else {
			for(int i=0; i<n; ++i) {
				long long lack=(long long)a[i]*m+h[i]-cur[i];
				if(lack>0) t-=(lack+p-1)/p;
			}
			return t>=0;
		}
	}
}
int main() {
	int (*rd)()=read<int>;
	long long l=0, r=0;
	n=rd(), m=rd(), k=rd(), p=rd();
	for(int i=0; i<n; ++i) {
		h[i]=rd();
		a[i]=rd();
		cmax(l, a[i]);
		cmax(r, h[i]+(long long)a[i]*m);
	}
	for(off=1; off<n; off<<=1);
	while(l<r) {
		long long mid=(l+r)/2;
		if(check(mid)) r=mid; else l=mid+1;
	}
	std::cout<<l<<std::endl;
	return 0;
}
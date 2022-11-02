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
const int N=305;
int n, m, a[N], l[N], r[N], real[N], id[N], min[N][N], left[N][N], f[N];
int jump(int x, int y) {
	int l=min[x+1][y];
	return l<x?left[l][x-1]:x;
}
int main() {
	n=rd();
	for(int i=0; i<n; ++i) {
		a[i]=rd(), l[i]=rd();
		real[m++]=a[i];
		real[m++]=r[i]=a[i]+l[i];
		real[m++]=l[i]=a[i]-l[i];
	}
	std::sort(real, real+m);
	m=std::unique(real, real+m)-real;
	memset(id, -1, m*sizeof(int));
	for(int i=0; i<m; ++i) memset(min[i], 63, m*sizeof(int));
	for(int i=0; i<n; ++i) {
		l[i]=std::lower_bound(real, real+m, l[i])-real;
		a[i]=std::lower_bound(real, real+m, a[i])-real;
		r[i]=std::lower_bound(real, real+m, r[i])-real;
		id[a[i]]=i;
		min[a[i]][a[i]]=l[i];
	}
	for(int i=0; i<m; ++i)
		for(int j=i+1; j<m; ++j) min[i][j]=std::min(min[i][j-1], min[j][j]);
	for(int i=0; i<m; ++i)
		for(int j=i; j<m; ++j)
			left[i][j]=min[i][j]>=i?i:left[min[i][j]][j];
	for(int i=0; i<m; ++i) {
		for(int j=0; j<i; ++j) {
			int x=id[j];
			if(x==-1) continue;
			int rr=std::min(r[x], i), ll=jump(j, rr-1);
			cmax(f[i], real[rr]-real[ll]+f[ll]);
			ll=left[l[x]][j-1];
			cmax(f[i], real[j]-real[ll]+f[ll]);
		}
	}
	printf("%d\n", f[m-1]);
	return 0;
}
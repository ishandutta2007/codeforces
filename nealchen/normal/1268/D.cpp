#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
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
auto rd=read<int>;
const int N=2000;
int n, deg[N], d[N], cnt, min=1e9, mincnt;
char s[N+1], e[N][N];
bool strong() {
	memcpy(d, deg, n*sizeof(int));
	std::sort(d, d+n);
	for(int k=1, sum=0; k<n; ++k) {
		sum+=d[k-1];
		if(sum==k*(k-1)/2) return false;
	}
	return true;
}
void rev(int u) {
	deg[u]=n-1-deg[u];
	for(int v=0; v<n; ++v)
		if(u!=v) {
			deg[v]-=e[v][u];
			e[u][v]^=1, e[v][u]^=1;
			deg[v]+=e[v][u];
		}
}
void search(int i, int r) {
	if(i==n) {
		if(strong()) if(r<min) min=r, mincnt=1; else if(r==min) ++mincnt;
	} else {
		search(i+1, r);
		rev(i);
		search(i+1, r+1);
		rev(i);
	}
}
int main() {
	assert(scanf("%d", &n)==1);
	for(int i=0; i<n; ++i) {
		assert(scanf("%s", s)==1);
		for(int j=0; j<n; ++j) deg[i]+=e[i][j]=s[j]-48;
	}
	if(strong()) {
		puts("0 1");
		return 0;
	}
	for(int i=0; i<n; ++i) {
		rev(i);
		mincnt+=strong();
		rev(i);
	}
	if(mincnt) {
		printf("1 %d\n", mincnt);
		return 0;
	}
	search(0, 0);
	if(mincnt==0) puts("-1"); else {
		for(int i=1; i<=min; ++i) mincnt=(long long)mincnt*i%998244353;
		printf("%d %d\n", min, mincnt);
	}
	return 0;
}
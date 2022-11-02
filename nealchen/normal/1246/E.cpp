#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
int a[16];
std::bitset<2001> f[1<<16];
std::vector<int> stage[16];
int main() {
	int n=rd(), k=rd();
	for(int i=0; i<n; ++i) a[i]=rd();
	f[0][0]=1;
	int fs=(1<<n)-1;
	for(int i=1; i<=fs; ++i) {
		for(int j=0; j<n; ++j)
			if(i>>j&1) f[i]|=f[i^1<<j]<<a[j];
		for(int j=2000/k; j>=1; --j)
			if(f[i].test(j*k)) f[i].set(j);
	}
	/*
	for(int i=0; i<=fs; ++i) {
		meow("set { ");
		for(int j=0; j<n; ++j) if(i>>j&1) meow("%d ", j+1);
		meow("} gets { ");
		for(int j=0; j<=2000; ++j) if(f[i].test(j)) meow("%d ", j);
		meow("}\n");
	}
	*/
	if(!f[fs].test(1)) {
		puts("NO");
		return 0;
	}
	int x=fs, y=1, nb=0;
	while(x) {
		if(y*k<=2000 && f[x].test(y*k)) {
			++nb;
			y*=k;
		} else {
			for(int i=0; i<n; ++i)
				if((x>>i&1) && y>=a[i] && f[x^1<<i].test(y-a[i])) {
					x^=1<<i;
					y-=a[i];
					stage[nb].push_back(a[i]);
					break;
				}
		}
	}
	puts("YES");
	while(nb) {
		int x, y;
		x=stage[nb].back(), stage[nb].pop_back();
		y=stage[nb].back(), stage[nb].pop_back();
		printf("%d %d\n", x, y);
		x+=y, y=0;
		while(x%k==0) x/=k, ++y;
		stage[nb-y].push_back(x);
		while(nb&&stage[nb].empty()) --nb;
	}
	return 0;
}
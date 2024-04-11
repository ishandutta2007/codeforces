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

const int N=1e5;
int a[N], b[N], from[N];
s64 f[N+1];
bool vis[N];
std::vector<int> pos[N], space;
int main() {
	int n, m, lis=0, last;
	n=rd();
	std::generate(a, a+n, rd);
	m=rd();
	std::generate(b, b+m, rd);
	std::sort(b, b+m, std::greater<int>());
	f[0]=-1;
	for(int i=0; i<n; ++i) {
		if(a[i]!=-1) {
			s64 x=(s64)a[i]<<32;
			int p=std::lower_bound(f+1, f+lis+1, x)-f;
			if(p>lis) last=i, ++lis;
			f[p]=x+i;
			from[i]=f[p-1];
			if(pos[p].empty()||a[pos[p].back()]>a[i]) pos[p].push_back(i);
		} else {
			int p=lis+1;
			space.push_back(i);
			for(int j=0; j<m; ++j) {
				s64 x=(s64)b[j]<<32;
				while(f[p-1]>=x) --p;
				if(p>lis) last=i, ++lis;
				f[p]=x+i;
			}
		}
	}
	for(int j=0; last!=-1; --lis)
		if(a[last]!=-1) {
			while(j<m&&b[j]>=a[last]) ++j;
			last=from[last];
		} else {
			vis[j]=true;
			a[last]=b[j];
			while(j<m&&b[j]>=a[last]) ++j;
			if(lis>1) {
				while(!pos[lis-1].empty()&&pos[lis-1].back()>=last) pos[lis-1].pop_back();
				if(pos[lis-1].empty()||a[pos[lis-1].back()]>=a[last]) {
					while(space.back()>=last) space.pop_back();
					last=space.back();
				} else
					last=pos[lis-1].back();
			} else last=-1;
		}
	for(int i=0, j=0; i<n; ++i)
		if(a[i]==-1) {
			while(vis[j]) ++j;
			printf("%d ", b[j++]);
		} else
			printf("%d ", a[i]);
	puts("");
	return 0;
}
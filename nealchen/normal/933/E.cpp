#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
const int N=3e5+5;
int n, p[N], cho[N];
long long f[N];
std::vector<int> ans;
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
void dec(int x) {
	int d=std::min(p[x], p[x+1]);
	if(d==0) return;
	ans.push_back(x);
	p[x]-=d;
	p[x+1]-=d;
}
int main() {
	int (*rd)()=read<int>;
	n=rd();
	for(int i=1; i<=n; ++i) {
		p[i]=rd();
		long long f2=f[std::max(i-2, 0)]+p[i], f3=f[std::max(i-3, 0)]+std::max(p[i-1], p[i]);
		f[i]=std::min(f2, f3);
		cho[i]=f2<f3?2:3;
	}
	std::vector<int> pos;
	for(int i=n-(f[n]>f[n-1]); i>0; i-=cho[i]) pos.push_back(i);
	std::reverse(pos.begin(), pos.end());
	int last=0;
	for(int cur: pos) {
		if(cho[cur]) dec(cur-1);
		dec(last+1);
		dec(cur);
		last=cur;
	}
	printf("%d\n", (int)ans.size());
	for(int e: ans) printf("%d\n", e);
	return 0;
}
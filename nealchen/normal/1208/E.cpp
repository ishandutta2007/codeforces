#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
typedef std::pair<int, int> Pair;
struct Array {
	int n, *a;
	bool operator<(const Array &o) const {return n<o.n;}
};
struct SlideWindow {
	int head;
	std::vector<Pair> v;
	void push(int pos, int val) {
		while(head<v.size()&&v.back().second<=val) v.pop_back();
		v.push_back(Pair(pos, val));
	}
	void pop(int pos) {while(head<v.size()&&v[head].first<pos) ++head;}
	int collect() {return head<v.size()?v[head].second:0;}
};
const int N=1e6;
int n, w, len[N];
Array a[N];
SlideWindow sw[N];
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
int read() {
	int a=0;
	bool b;
	unsigned char c;
	while((c=getchar()-'0')>9&c!=253);
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
void write(long long x) {
	char s[30], *p=s;
	if(x<0) putchar('-'), x=-x;
	while(*p++=x%10+'0', x/=10);
	while(putchar(*--p), p!=s);
}
int main() {
	n=read(), w=read();
	for(int i=0; i<n; ++i) {
		int l=read();
		a[i].n=l;
		a[i].a=new int[l];
		for(int j=0; j<l; ++j) a[i].a[j]=read();
	}
	std::sort(a, a+n);
	for(int i=0; i<n; ++i) len[i]=a[i].n;
	long long ans=0;
	for(int i=0; i<n; ++i) sw[i].push(0, 0);
	for(int i=1; i<=w; ++i) {
		int p=std::lower_bound(len, len+n, i-1)-len, q=std::lower_bound(len, len+n, w-i+1)-len;
		for(int j=p; j<n; ++j) {
			ans-=sw[j].collect();
			if(i<=len[j]) sw[j].push(i, a[j].a[i-1]); else sw[j].push(i, 0);
			ans+=sw[j].collect();
		}
		for(int j=q; j<n; ++j) {
			ans-=sw[j].collect();
			sw[j].pop(len[j]-w+i);
			ans+=sw[j].collect();
		}
		write(ans);
		putchar(' ');
	}
	putchar('\n');
	for(int i=0; i<n; ++i) delete[] a[i].a;
	return 0;
}
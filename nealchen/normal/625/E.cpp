#include <set>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
struct Frog {
	int p, a, n;
	bool operator<(const Frog &o) const {return p<o.p;}
};
const int N=1e5;
int n, m, inv[N], next[N], prev[N], when[N];
bool gg[N];
Frog a[N];
long long add[N];
std::set< std::pair<int, int> > event;
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
int solve(int x, int y) {
	if(x==y) return 0;
	long long l=a[y].p-a[x].p;
	if(l<0) l+=m;
	l+=add[y]-add[x];
	int t=0;
	if(a[x].n<a[y].n) l-=a[x].a, t=1;
	if(l<=0) return 1;
	if(a[y].a<a[x].a) return (l-1)/(a[x].a-a[y].a)+t+1;
	return 0;
}
int main() {
	int (*rd)()=read<int>;
	n=rd(), m=rd();
	for(int i=0; i<n; ++i) a[i]=(Frog){rd(), rd(), i};
	std::sort(a, a+n);
	for(int i=0; i<n; ++i) inv[a[i].n]=i;
	for(int i=0; i<n; ++i) {
		int x=inv[i], y=(x+1)%n;
		next[x]=y, prev[y]=x;
		if(when[x]=solve(x, y)) event.emplace(when[x], i);
	}
	while(!event.empty()) {
		auto it=event.begin();
		int x=inv[it->second], t=it->first, tt=t, cnt=0;
		event.erase(it);
		if(gg[x]||when[x]!=t) continue;
		do {
			gg[next[x]]=true;
			next[x]=next[next[x]];
			++cnt;
			tt=solve(x, next[x]);
		} while(t==tt);
		a[x].a=std::max(a[x].a-cnt, 0);
		prev[next[x]]=x;
		add[x]+=(long long)cnt*t;
		if(when[x]=solve(x, next[x])) event.emplace(when[x], a[x].n);
		x=prev[x];
		if(when[x]=solve(x, next[x])) event.emplace(when[x], a[x].n);
	}
	int cnt=0;
	for(int i=0; i<n; ++i) cnt+=!gg[i];
	printf("%d\n", cnt);
	for(int i=0; i<n; ++i) if(!gg[i]) printf("%d ", a[i].n+1);
	puts("");
	return 0;
}
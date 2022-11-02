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
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

const int N=2e5+1;
int n, t, q, p[N], l[N], x[N], offset, addcho[1<<19], subcho[1<<19];
double add[1<<18], sub[1<<18], ans;
void pushup(int o) {
	addcho[o]=add[addcho[2*o]]>add[addcho[2*o+1]]?addcho[2*o]:addcho[2*o+1];
	subcho[o]=sub[subcho[2*o]]>sub[subcho[2*o+1]]?subcho[2*o]:subcho[2*o+1];
}
void modify(int o) {for(o+=offset; o/=2; ) pushup(o);}
double calc(int id) {return 1.0*p[id]*x[id]/(x[id]+l[id]);}
void update(int id) {
	add[id]=p[id]*(x[id]+1.0)/(l[id]+x[id]+1)-calc(id);
	sub[id]=p[id]*(x[id]-1.0)/(l[id]+x[id]-1)-calc(id);
	if(x[id]==0) sub[id]=-1e12;
	if(x[id]>=l[id]) add[id]=-1e12;
	if(x[id]>l[id]) sub[id]=1e12;
}
void upd(int id) {update(id), modify(id);}
int main() {
	n=rd(), t=rd(), q=rd();
	std::generate(p+1, p+n+1, rd);
	l[0]=t;
	std::generate(l+1, l+n+1, rd);
	for(offset=1; offset<=n; offset*=2);
	for(int i=0; i<=n; ++i) update(i);
	for(int i=n+1; i<offset; ++i) add[i]=sub[i]=-1e18;
	for(int i=0; i<offset; ++i) addcho[offset+i]=subcho[offset+i]=i;
	for(int o=offset; --o; ) pushup(o);
	while(t--) {
		int a=addcho[1];
		ans-=calc(a);
		++x[a];
		ans+=calc(a);
		upd(a);
	}
	while(q--) {
		int t=rd(), r=rd();
		ans-=calc(r);
		l[r]+=(t==1)?1:-1;
		ans+=calc(r);
		upd(r);
		while(add[addcho[1]]+sub[subcho[1]]>0) {
			int a=addcho[1], b=subcho[1];
			ans-=calc(a)+calc(b);
			++x[a], --x[b];
			ans+=calc(a)+calc(b);
			upd(a), upd(b);
		}
		printf("%.12lf\n", ans);
	}
	return 0;
}
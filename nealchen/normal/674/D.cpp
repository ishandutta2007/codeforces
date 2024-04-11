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
const int N=1e5+1;
int n, q, f[N], d[N], off;
long long t[N], s[N], tag[N], min[1<<18], max[1<<18];
std::multiset<long long> set[N];
long long per(int u) {return t[u]/(d[u]+2);}
long long me(int u) {return t[u]-(d[u]+1)*per(u)+s[u];}
long long eval(int u) {return me(u)+per(f[u]);}
long long qmin(int u) {return set[u].empty()?6e18:*set[u].begin();}
long long qmax(int u) {return set[u].empty()?0:*set[u].rbegin();}
void update(int u) {
	min[off+u]=qmin(u)+per(u);
	max[off+u]=qmax(u)+per(u);
	for(int x=off+u; x>>=1; ) {
		min[x]=std::min(min[2*x], min[2*x+1]);
		max[x]=std::max(max[2*x], max[2*x+1]);
	}
}
// u
void erase(int u) {
	//meow("erase %d with me=%lld\n", u, me(u));
	set[f[u]].erase(set[f[u]].find(me(u)));
	update(f[u]);
}
// u
void insert(int u) {
	//meow("insert %d with me=%lld\n", u, me(u));
	set[f[u]].insert(me(u));
	update(f[u]);
}
// u 
void deginc(int u, int delta) {
	erase(f[u]);
	s[f[u]]-=per(u);
	d[u]+=delta;
	s[f[u]]+=per(u);
	insert(f[u]);
	update(u);
}
int main() {
	n=rd(), q=rd();
	for(int i=1; i<=n; ++i) t[i]=read<long long>();
	for(int i=1; i<=n; ++i) ++d[f[i]=rd()];
	for(int i=1; i<=n; ++i) s[f[i]]+=per(i);
	for(int i=1; i<=n; ++i) set[f[i]].insert(me(i));
	for(off=1; off<=n; off<<=1);
	for(int i=off; i<2*off; ++i) min[i]=6e18, max[i]=0;
	for(int i=1; i<=n; ++i) {
		min[off+i]=qmin(i)+per(i);
		max[off+i]=qmax(i)+per(i);
	}
	for(int i=off; i--; ) {
		min[i]=std::min(min[2*i], min[2*i+1]);
		max[i]=std::max(max[2*i], max[2*i+1]);
	}
	while(q--) {
		int o=rd();
		if(o==1) {
			int i=rd();
			erase(i);
			erase(f[i]);
			s[f[i]]-=per(i);
			deginc(f[i], -1);
			insert(f[i]);
			f[i]=rd();
			erase(f[i]);
			s[f[i]]+=per(i);
			deginc(f[i], 1);
			insert(f[i]);
			insert(i);
		}
		if(o==2) printf("%lld\n", eval(rd()));
		if(o==3) printf("%lld %lld\n", min[1], max[1]);
	}
	return 0;
}
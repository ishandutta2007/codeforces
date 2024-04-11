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
int (*rd)()=read<int>;

typedef std::vector<std::pair<int, int>> Jar;
const int S=1<<19;
int l[S], r[S], set[S], cap, ql, qr, qv;
Jar top[S], ans;
void add_tag(int i, int v) {
	set[i]=v;
	top[i]={{v, r[i]-l[i]+1}};
}
void pushdown(int i) {
	if(set[i]) {
		add_tag(i<<1, set[i]);
		add_tag(i<<1|1, set[i]);
		set[i]=0;
	}
}
Jar merge(const Jar &a, const Jar &b) {
	Jar c;
	for(auto i=a.begin(), j=b.begin(); i!=a.end()||j!=b.end(); ) {
		int va=(i==a.end()?1e9:i->first), vb=(j==b.end()?1e9:j->first);
		if(va<vb) c.push_back(*i++);
		if(va>vb) c.push_back(*j++);
		if(va==vb) c.emplace_back(va, i->second+j->second), ++i, ++j;
	}
	if(c.size()>cap) {
		std::sort(c.begin(), c.end(), [](auto p, auto q) {return p.second>q.second;});
		while(c.size()>cap) {
			int dup=c.back().second;
			c.pop_back();
			for(auto &p: c) p.second-=dup;
		}
		std::sort(c.begin(), c.end());
	}
	return c;
}
void build(int i, int ll, int rr) {
	l[i]=ll, r[i]=rr;
	if(ll==rr) {
		top[i]={{rd(), 1}};
	} else {
		int mid=(ll+rr)/2;
		build(i<<1, ll, mid);
		build(i<<1|1, mid+1, rr);
		top[i]=merge(top[i<<1], top[i<<1|1]);
	}
}
void query(int i) {
	if(l[i]>qr||r[i]<ql) return;
	if(ql<=l[i]&&r[i]<=qr) {
		ans=merge(ans, top[i]);
		return;
	}
	pushdown(i);
	query(i<<1);
	query(i<<1|1);
}
void modify(int i) {
	if(l[i]>qr||r[i]<ql) return;
	if(ql<=l[i]&&r[i]<=qr) return add_tag(i, qv);
	pushdown(i);
	modify(i<<1);
	modify(i<<1|1);
	top[i]=merge(top[i<<1], top[i<<1|1]);
}
int main() {
	int n=rd(), m=rd(), p=rd();
	cap=100/p;
	build(1, 1, n);
	while(m--) {
		if(rd()==1) {
			ql=rd(), qr=rd(), qv=rd();
			modify(1);
		} else {
			ql=rd(), qr=rd();
			ans.clear();
			query(1);
			printf("%d", (int)ans.size());
			for(auto p: ans) printf(" %d", p.first);
			puts("");
		}
	}
	return 0;
}
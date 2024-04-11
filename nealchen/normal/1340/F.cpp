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
struct Treap {
	int size;
	u32 val, hash;
	bool vis;
	Treap *lc, *rc;
};
struct Info {
	bool broken;
	Treap *c, *o;
};
const int N=100003, M=2e6;
const u32 P=998244353;
int n, k, s[N], pos, ql, qr;
u32 power[N];
Info node[1<<18], res;
Treap nil[1], pool[M], *mem=pool, *split_l, *split_r;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
Treap *visit() {
	while(mem->vis) ++mem;
	mem->vis=true;
	return mem;
}
void collect(Treap *tr) {
	if(tr==nil||tr->vis) return;
	tr->vis=true;
	collect(tr->lc);
	collect(tr->rc);
}
Treap *make(u32 val) {
	Treap *res=visit();
	res->size=1;
	res->val=res->hash=val;
	res->lc=res->rc=nil;
	return res;
}
Treap *pushup(Treap *lc, u32 val, Treap *rc) {
	Treap *res=visit();
	res->size=lc->size+rc->size+1;
	res->val=val;
	res->hash=(lc->hash+(val+1llu*N*rc->hash)%P*power[lc->size])%P;
	res->lc=lc;
	res->rc=rc;
	return res;
}
void split(Treap *u, int x) {
	if(x==0) {
		split_l=nil;
		split_r=u;
		return;
	}
	if(x==u->size) {
		split_l=u;
		split_r=nil;
		return;
	}
	if(x<=u->lc->size) {
		split(u->lc, x);
		split_r=pushup(split_r, u->val, u->rc);
	} else {
		split(u->rc, x - u->lc->size - 1);
		split_l=pushup(u->lc, u->val, split_l);
	}
}
Treap *merge(Treap *u, Treap *v) {
	if(u==nil) return v;
	if(v==nil) return u;
	if(std::uniform_int_distribution<>(1, u->size+v->size)(rng) <= u->size)
		return pushup(u->lc, u->val, merge(u->rc, v));
	else
		return pushup(merge(u, v->lc), v->val, v->rc);
}
Info init(int x) {
	Info res={false, nil, nil};
	if(x<0)
		res.c=make(-x);
	else
		res.o=make(x);
	return res;
}
Info cat(Info l, Info r) {
	Info res;
	if(l.broken||r.broken) return {true, nil, nil};
	int d = l.o->size - r.c->size;
	if(d>0) {
		split(l.o, d);
		if(split_r->hash != r.c->hash) {
			res={true, nil, nil};
		} else {
			res={false, l.c, merge(split_l, r.o)};
		}
	} else {
		split(r.c, -d);
		if(split_r->hash != l.o->hash) {
			res={true, nil, nil};
		} else {
			res={false, merge(split_l, l.c), r.o};
		}
	}
	return res;
}
void build(int o, int l, int r) {
	if(l==r)
		node[o]=init(rd());
	else {
		int mid=(l+r)/2;
		build(2*o, l, mid);
		build(2*o+1, mid+1, r);
		node[o]=cat(node[2*o], node[2*o+1]);
	}
}
void update(int o, int l, int r) {
	if(l==r) {
		node[o]=init(rd());
	} else {
		int mid=(l+r)/2;
		if(pos<=mid)
			update(2*o, l, mid);
		else
			update(2*o+1, mid+1, r);
		node[o]=cat(node[2*o], node[2*o+1]);
	}
}
void query(int o, int l, int r) {
	if(qr<l||ql>r) return;
	if(ql<=l&&r<=qr)
		res=cat(res, node[o]);
	else {
		int mid=(l+r)/2;
		query(2*o, l, mid);
		query(2*o+1, mid+1, r);
	}
}
void segcol(int o, int l, int r) {
	collect(node[o].c);
	collect(node[o].o);
	if(l==r) return;
	int mid=(l+r)/2;
	segcol(2*o, l, mid);
	segcol(2*o+1, mid+1, r);
}
int main() {
	nil->lc=nil->rc=nil;
	n=rd();
	k=rd();
	power[0]=1;
	for(int i=1; i<=n; ++i) power[i]=1llu*power[i-1]*N%P;
	build(1, 1, n);
	int q=rd();
	while(q--) {
		if(rd()==1) {
			pos=rd();
			update(1, 1, n);
		} else {
			res={false, nil, nil};
			ql=rd();
			qr=rd();
			query(1, 1, n);
			puts(!res.broken&&res.c==nil&&res.o==nil?"Yes":"No");
		}
		if(mem-pool>=M-1e4) {
			for(Treap *i=pool; i<=mem; ++i) i->vis=false;
			segcol(1, 1, n);
			mem=pool;
		}
	}
	return 0;
}
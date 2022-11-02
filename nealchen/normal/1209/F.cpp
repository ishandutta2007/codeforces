#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef unsigned long long u64;
struct Node {
	u32 cnt, val;
	u64 hash;
	Node *l, *r;
};
const int N=1e5+5, M=5e5, S=1<<18;
const u32 P1=1e9+7;
const u64 long long P2=12345678987654373llu;
int n, len, off, head[N], next[N<<1], to[N<<1], zkw[S];
Node mem[M*40], *null=mem, *tot=mem+1, *dist[N], *val[S>>1];
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
bool less(Node *x, Node *y) {
	int l=0, r=len;
	if(!x) return 0;
	if(!y) return 1;
	if(x->cnt!=y->cnt) return x->cnt<y->cnt;
	if(x->val==y->val&&x->hash==y->hash) return 0;
	while(l<r) {
		int mid=(l+r)/2;
		if(x->l->val==y->l->val&&x->l->hash==y->l->hash) {
			x=x->r;
			y=y->r;
			l=mid+1;
		} else {
			x=x->l;
			y=y->l;
			r=mid;
		}
	}
	return x->val<y->val;
}
void add(Node *&o, int l, int r, int val) {
	*tot=*o;
	o=tot++;
	++o->cnt;
	o->val=(o->val*10ll+val)%P1;
	o->hash=(o->hash*17ll+val)%P2;
	if(l<r) {
		int mid=(l+r)/2;
		if(o->l->cnt<=mid-l) add(o->l, l, mid, val); else add(o->r, mid+1, r, val);
	}
}
Node *append(Node *o, int v) {
	static char str[15];
	sprintf(str, "%d", v);
	for(int i=0; str[i]; ++i) add(o, 0, len, str[i]-'0');
	return o;
}
void modify(register int x, register Node *v) {
	for(val[x]=v, x|=off; x>>=1; ) zkw[x]=less(val[zkw[x<<1]], val[zkw[x<<1|1]])?zkw[x<<1]:zkw[x<<1|1];
}
int main() {
	int (*rd)()=read<int>, m;
	n=rd(), m=rd();
	len=m*5;
	for(int i=1, j=2; i<=m; ++i) {
		to[j^1]=rd(), to[j]=rd();
		next[j]=head[to[j^1]], head[to[j^1]]=j, ++j;
		next[j]=head[to[j^1]], head[to[j^1]]=j, ++j;
	}
	null->l=null->r=null;
	for(off=1; off<=n; off<<=1);
	for(int i=0; i<off; ++i) zkw[i|off]=i;
	for(int i=off; --i; zkw[i]=zkw[i<<1]);
	modify(1, dist[1]=null);
	for(int i=1; i<=n; ++i) {
		int u=zkw[1];
		modify(u, NULL);
		for(int j=head[u]; j; j=next[j]) {
			int v=to[j];
			Node *test=append(dist[u], j>>1);
			if(less(test, dist[v])) modify(v, dist[v]=test);
		}
	}
	for(int i=2; i<=n; ++i) printf("%d\n", dist[i]->val);
	return 0;
}
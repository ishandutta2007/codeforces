#include <stdio.h>
#include <string.h>
bool cmax(auto &x, const auto &y) {return x<y?(x=y, true):false;}
struct Seg {
	int sum;
	Seg *l, *r;
};
const int N=1<<18, M=N<<1;
char s[N];
int tot, last[M], next[M][26], max[M];
Seg pool[20<<19], *mem=pool, *right[M];
Seg *make(register int x, register int l, register int r) {
	register Seg *ans=mem++;
	ans->sum=1;
	if(l!=r) {
		register int m=(l+r)>>1;
		x<=m ? (ans->l=make(x, l, m)) : (ans->r=make(x, m+1, r));
	}
	return ans;
}
Seg *merge(register Seg *a, register Seg *b) {
	if(!a) return b;
	if(!b) return a;
	register Seg *ans=mem++;
	ans->sum=a->sum+b->sum;
	ans->l=merge(a->l, b->l);
	ans->r=merge(a->r, b->r);
	return ans;
}
int query(register Seg *o, register int ql, register int qr, register int l, register int r) {
	if(!o || ql>r || qr<l) return 0;
	if(ql<=l && r<=qr) return o->sum;
	register int m=(l+r)>>1;
	return query(o->l, ql, qr, l, m)+query(o->r, ql, qr, m+1, r);
}
int n, any[M], ans[M], son[M], bro[M];
void dfsdown(register int x) {
	if(x>=1 && x<=n) right[x]=make(x, 1, n);
	for(register int i=son[x]; i; i=bro[i]) {
		dfsdown(i);
		right[x]=merge(right[x], right[i]);
	}
}
void dfsup(register int x, register int pre) {
	if(x) {
		ans[x]=ans[pre];
		if(!pre || query(right[pre], any[x]+max[pre]-max[x], any[x]-1, 1, n)) {
			++ans[x];
			pre=x;
		}
	}
	for(register int i=son[x]; i; i=bro[i]) dfsup(i, pre);
}
int main() {
	scanf("%d%s", &n, s+1);
	tot=n;
	last[0]=-1;
	for(register int i=1; i<=n; ++i) {
		register int c=s[i]-'a', p, q;
		any[i]=i;
		max[i]=i;
		for(p=i-1; ~p && !next[p][c]; p=last[p]) next[p][c]=i;
		if(p==-1) {
			last[i]=0;
			continue;
		}
		q=next[p][c];
		if(max[q]==max[p]+1) {
			last[i]=q;
			continue;
		}
		++tot;
		any[tot]=any[i];
		max[tot]=max[p]+1;
		last[tot]=last[q];
		memcpy(next[tot], next[q], 26*sizeof(int));
		last[i]=last[q]=tot;
		for(; ~p && next[p][c]==q; p=last[p]) next[p][c]=tot;
	}
	for(register int i=1; i<=tot; ++i) {
		bro[i]=son[last[i]];
		son[last[i]]=i;
	}
	dfsdown(0);
	dfsup(0, 0);
	int answer=0;
	for(register int i=1; i<=tot; ++i) cmax(answer, ans[i]);
	printf("%d\n", answer);
	return 0;
}
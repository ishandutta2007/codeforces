#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 3003
#define M 3000
#define Q 400000
#define LV 13
#ifdef DEBUG
	#define meow(args...) fprintf(stderr, args)
#else
	#define meow(args...) 0
#endif
int F() {
	register int a=0, c;
	while(c=getchar(), !isdigit(c));
	for(; isdigit(c); c=getchar()) a=a*10+c-'0';
	return a;
}
struct Edge {
	int x, y;
	Edge *rnext;
	bool operator<(const Edge &o) const {return x<o.x || x==o.x&&y<o.y;}
};
struct queue {
	int arr[N], head, tail;
	bool empty() const {return head==tail;}
	int front() const {return arr[head];}
	void clear() {head=tail=0;}
	void push(register int x) {arr[tail++]=x;}
	void pop() {++head;}
};
char vis[N];
int n, outdeg[N], qs[Q], qk[Q], qhead[N], qnext[Q], ans[Q], adv[LV][N], *nxt=adv[0];
struct Edge e[M], *beg[N], **end=beg+1, *rhead[N];
struct queue q;
void run(register int dst) {
	register int i, j, k;
	register struct Edge *it;
	memset(vis+1, 0, n);
	q.clear();
	vis[dst]=1;
	q.push(dst);
	while(!q.empty()) {
		for(it=rhead[q.front()]; it; it=it->rnext) {
			if(!vis[it->x]) {
				vis[it->x]=1;
				q.push(it->x);
			}
		}
		q.pop();
	}
	nxt[dst]=-1;
	for(i=1; i<=n; ++i) {
		if(vis[i] && i!=dst) {
			for(it=beg[i]; !vis[it->y]; ++it);
			nxt[i]=it->y;
		}
	}
	for(i=1; i<LV; ++i) {
		for(j=1; j<=n; ++j) adv[i][j]=~adv[i-1][j]?adv[i-1][adv[i-1][j]]:-1;
	}
	for(i=1; i<=n; ++i) if(~adv[LV-1][i]) vis[i]=2;
	for(i=qhead[dst]; ~i; i=qnext[i]) {
		if(vis[qs[i]]!=1) {
			ans[i]=-1;
			continue;
		}
		for(j=qs[i], k=qk[i]-1; k; k&=k-1) {
			j=adv[__builtin_ctz(k)][j];
			if(j==-1) break;
		}
		ans[i]=j;
	}
}
int main() {
	register int m, q, i, j;
	register struct Edge *it;
	n=F(), m=F(), q=F();
	memset(qhead+1, -1, n*sizeof(int));
	for(i=0; i<m; ++i) ++outdeg[e[i].x=F()], e[i].y=F();
	std::sort(e, e+m);
	for(i=1, it=e; i<=n; ++i) {
		beg[i]=it;
		for(j=0; j<outdeg[i]; ++j, ++it) {
			it->rnext=rhead[it->y];
			rhead[it->y]=it;
		}
	}
	end[n]=it;
	for(i=0; i<q; ++i) {
		qs[i]=F(), j=F(), qk[i]=F();
		qnext[i]=qhead[j], qhead[j]=i;
	}
	for(i=1; i<=n; ++i) run(i);
	for(i=0; i<q; ++i) printf("%d\n", ans[i]);
	return 0;
}
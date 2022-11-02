#include <bits/stdc++.h>
typedef unsigned u32;
typedef unsigned long long u64;
const int N=1e5+1, M=1<<18;
const u32 P=1e9+7;
int n, m, a[N], lb[M], rb[M], tag[M], ql, qr, qx;
u32 com[6][6], powsum[N][6], sum[M][6], res[6];
void cover(int i, int v) {
	tag[i]=v;
	for(int j=0; j<=5; ++j) sum[i][j]=(u64)(P+powsum[rb[i]][j]-powsum[lb[i]-1][j])*v%P;
}
void pushup(int i) {
	for(int j=0; j<=5; ++j) sum[i][j]=(sum[2*i][j]+sum[2*i+1][j])%P;
}
void pushdown(int i) {
	if(tag[i]==-1) return;
	cover(2*i, tag[i]);
	cover(2*i+1, tag[i]);
	tag[i]=-1;
}
void build(int i, int l, int r) {
	lb[i]=l;
	rb[i]=r;
	if(l==r) return cover(i, a[l]);
	tag[i]=-1;
	int mid=(l+r)/2;
	build(2*i, l, mid);
	build(2*i+1, mid+1, r);
	pushup(i);
}
void modify(int i) {
	if(ql>rb[i]||qr<lb[i]) return;
	if(ql<=lb[i]&&rb[i]<=qr) return cover(i, qx);
	pushdown(i);
	modify(2*i);
	modify(2*i+1);
	pushup(i);
}
void query(int i) {
	if(ql>rb[i]||qr<lb[i]) return;
	if(ql<=lb[i]&&rb[i]<=qr) {
		for(int j=0; j<=5; ++j) res[j]=(res[j]+sum[i][j])%P;
		return;
	}
	pushdown(i);
	query(2*i);
	query(2*i+1);
}
int main() {
	for(int i=0; i<=5; ++i) {
		com[i][0]=com[i][i]=1;
		for(int j=1; j<i; ++j) com[i][j]=com[i-1][j-1]+com[i-1][j];
	}
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i) {
		u32 p=1;
		for(int j=0; j<=5; ++j) {
			powsum[i][j]=(powsum[i-1][j]+p)%P;
			p=1llu*p*i%P;
		}
	}
	build(1, 1, n);
	while(m--) {
		char op;
		scanf(" %c%d%d%d", &op, &ql, &qr, &qx);
		if(op=='=') {
			modify(1);
		} else {
			u32 ans=0, p=1;
			memset(res, 0, sizeof res);
			query(1);
			for(int j=0; j<=qx; ++j) {
				ans=(ans+(u64)res[qx-j]*p%P*com[qx][j])%P;
				p=p*(P+1llu-ql)%P;
			}
			printf("%u\n", ans);
		}
	}
	return 0;
}
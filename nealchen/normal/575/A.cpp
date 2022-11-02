#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32, Vector[2], Matrix[2][2];
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
const int N=50010;
int n;
u32 P, s[N];
Matrix tr[N], pre[16][N], suf[16][N], all[64];
std::pair<s64, u32> where[N];
void mul(const Matrix a, const Matrix b, Matrix dst) {
	Matrix res;
	res[0][0]=((s64)a[0][0]*b[0][0]+(s64)a[0][1]*b[1][0])%P;
	res[0][1]=((s64)a[0][0]*b[0][1]+(s64)a[0][1]*b[1][1])%P;
	res[1][0]=((s64)a[1][0]*b[0][0]+(s64)a[1][1]*b[1][0])%P;
	res[1][1]=((s64)a[1][0]*b[0][1]+(s64)a[1][1]*b[1][1])%P;
	memcpy(dst, res, sizeof(Matrix));
}
void mul(const Matrix a, const Vector b, Vector dst) {
	Vector res;
	res[0]=((s64)a[0][0]*b[0]+(s64)a[0][1]*b[1])%P;
	res[1]=((s64)a[1][0]*b[0]+(s64)a[1][1]*b[1])%P;
	memcpy(dst, res, sizeof(Vector));
}
void range(int l, int r, Vector cur) {
	if(l==r) return mul(tr[l], cur, cur);
	int lv=31-__builtin_clz(l^r);
	mul(suf[lv][l], cur, cur);
	mul(pre[lv][r], cur, cur);
}
void solve(s64 l, s64 r, Vector cur) {
	if(l>r) return;
	if(l/n==r/n) {
		range(l%n, r%n, cur);
	} else {
		range(l%n, n-1, cur);
		for(s64 p=r/n-l/n-1; p; p&=p-1) mul(all[__builtin_ctzll(p)], cur, cur);
		range(0, r%n, cur);
	}
}
int main() {
	s64 k=read<s64>();
	P=rd(), n=rd();
	for(int i=0; i<n; ++i) s[i]=rd();
	int m=rd();
	for(int i=0; i<m; ++i) where[i]={read<s64>(), rd()};
	all[0][0][0]=all[0][1][1]=1;
	for(int i=0; i<n; ++i) {
		tr[i][0][1]=1;
		tr[i][1][0]=s[i];
		tr[i][1][1]=s[(i+1)%n];
		mul(tr[i], all[0], all[0]);
	}
	for(int i=1; i<64; ++i) mul(all[i-1], all[i-1], all[i]);
	for(int i=0; (1<<i)<n; ++i) {
		for(int j=0; j<n; ++j)
			if(j%(1<<i)==0)
				memcpy(pre[i][j], tr[j], sizeof(Matrix));
			else
				mul(tr[j], pre[i][j-1], pre[i][j]);
		for(int j=n; j--; )
			if((j+1)%(1<<i)==0)
				memcpy(suf[i][j], tr[j], sizeof(Matrix));
			else
				mul(suf[i][j+1], tr[j], suf[i][j]);
	}
	Vector cur={0, 1};
	if(k<=n) {
		solve(0, k-1, cur);
	} else {
		std::sort(where, where+m);
		while(m>0&&where[m-1].first>k) --m;
		if(m==0||where[m-1].first<k) where[m++]={k, s[k%n]};
		s64 lj=0, cj;
		u32 lv=s[0], cv;
		for(int i=0; i<m; ++i) {
			std::tie(cj, cv)=where[i];
			if(lj==cj-1) {
				u32 next=((u64)lv*cur[0]+(u64)cv*cur[1])%P;
				cur[0]=cur[1], cur[1]=next;
			} else {
				u32 next=((u64)lv*cur[0]+(u64)s[(lj+1)%n]*cur[1])%P;
				cur[0]=cur[1], cur[1]=next;
				solve(lj+1, cj-2, cur);
				next=((u64)s[(cj-1)%n]*cur[0]+(u64)cv*cur[1])%P;
				cur[0]=cur[1], cur[1]=next;
			}
			lj=cj, lv=cv;
		}
	}
	printf("%u\n", cur[0]);
	return 0;
}
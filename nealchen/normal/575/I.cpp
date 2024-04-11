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
int (*rd)()=read<int>;
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

struct Point {
	int x, y, val, *ans;
};
const int Q=1e5;
int n, op[Q], dir[Q], x[Q], y[Q], len[Q], ans[Q], bit[5001];
Point p[3*Q], save[3*Q];
int bit_par_sum(int x) {
	int res=0;
	for(; x; x&=x-1) res+=bit[x];
	return res;
}
void bit_inc(int x, int v) {
	for(; x<=n; x+=x&-x) bit[x]+=v;
}
void bit_reset(int x) {
	for(; x<=n; x+=x&-x) bit[x]=0;
}
void solve(int l, int r) {
	if(r-l==1) return;
	int mid=(l+r)/2;
	solve(l, mid);
	solve(mid, r);
	int i=l, j=mid, k=l;
	while(i<mid&&j<r)
		if(p[i].x<=p[j].x) {
			if(p[i].val) bit_inc(p[i].y, p[i].val);
			save[k++]=p[i++];
		} else {
			if(p[j].ans) *p[j].ans+=bit_par_sum(p[j].y);
			save[k++]=p[j++];
		}
	while(i<mid) save[k++]=p[i++];
	while(j<r) {
		if(p[j].ans) *p[j].ans+=bit_par_sum(p[j].y);
		save[k++]=p[j++];
	}
	for(i=l; i<mid; ++i) if(p[i].val) bit_reset(p[i].y);
	for(i=l; i<r; ++i) p[i]=save[i];
}
int main() {
	int q, p_cnt;
	n=rd(), q=rd();
	for(int i=0; i<q; ++i) {
		op[i]=rd();
		if(op[i]==1) {
			dir[i]=rd(), x[i]=rd(), y[i]=rd(), len[i]=rd();
		} else {
			x[i]=rd(), y[i]=rd();
		}
	}
	//x+y, x
	p_cnt=0;
	for(int i=0; i<q; ++i) {
		if(op[i]==2) {
			p[p_cnt++]={x[i]+y[i], x[i], 0, ans+i};
		} else if(dir[i]==1) {
			p[p_cnt++]={x[i]+y[i], x[i], 1, NULL};
			p[p_cnt++]={x[i]+y[i]+len[i]+1, x[i], -1, NULL};
		} else if(dir[i]==4) {
			p[p_cnt++]={x[i]+y[i]-len[i], x[i]+1, -1, NULL};
			p[p_cnt++]={x[i]+y[i]+1, x[i]+1, 1, NULL};
		}
	}
	solve(0, p_cnt);
	//x+y, y
	p_cnt=0;
	for(int i=0; i<q; ++i) {
		if(op[i]==2) {
			p[p_cnt++]={x[i]+y[i], n+1-y[i], 0, ans+i};
		} else if(dir[i]==1) {
			p[p_cnt++]={x[i]+y[i], n+2-y[i], -1, NULL};
			p[p_cnt++]={x[i]+y[i]+len[i]+1, n+2-y[i], 1, NULL};
		} else if(dir[i]==4) {
			p[p_cnt++]={x[i]+y[i]-len[i], n+1-y[i], 1, NULL};
			p[p_cnt++]={x[i]+y[i]+1, n+1-y[i], -1, NULL};
		}
	}
	solve(0, p_cnt);
	//x-y, x
	p_cnt=0;
	for(int i=0; i<q; ++i) {
		if(op[i]==2) {
			p[p_cnt++]={x[i]-y[i], x[i], 0, ans+i};
		} else if(dir[i]==2) {
			p[p_cnt++]={x[i]-y[i], x[i], 1, NULL};
			p[p_cnt++]={x[i]-y[i]+len[i]+1, x[i], -1, NULL};
		} else if(dir[i]==3) {
			p[p_cnt++]={x[i]-y[i]-len[i], x[i]+1, -1, NULL};
			p[p_cnt++]={x[i]-y[i]+1, x[i]+1, 1, NULL};
		}
	}
	solve(0, p_cnt);
	//x-y, y
	p_cnt=0;
	for(int i=0; i<q; ++i) {
		if(op[i]==2) {
			p[p_cnt++]={x[i]-y[i], y[i], 0, ans+i};
		} else if(dir[i]==2) {
			p[p_cnt++]={x[i]-y[i], y[i]+1, -1, NULL};
			p[p_cnt++]={x[i]-y[i]+len[i]+1, y[i]+1, 1, NULL};
		} else if(dir[i]==3) {
			p[p_cnt++]={x[i]-y[i]-len[i], y[i], 1, NULL};
			p[p_cnt++]={x[i]-y[i]+1, y[i], -1, NULL};
		}
	}
	solve(0, p_cnt);
	for(int i=0; i<q; ++i) if(op[i]==2) printf("%d\n", ans[i]);
	return 0;
}
#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
const int N=50000;
const long double PI=acosl(-1);
int n, size, l[N], r[N], bit[2*N], prev[2*N], next[2*N];
long double a[N], b[N];
std::pair<long double, int> event[2*N];
void extract(long double d) {
	size=0;
	for(int i=0; i<n; ++i) {
		long double A=a[i]*a[i]+1, B=-a[i]*b[i], Delta=B*B-A*(b[i]*b[i]-d*d);
		if(Delta<0) continue;
		long double x1=(-a[i]*b[i]-sqrtl(Delta))/A, x2=(-a[i]*b[i]+sqrtl(Delta))/A;
		event[size++]={atan2l(a[i]*x1+b[i], x1), i};
		event[size++]={atan2l(a[i]*x2+b[i], x2), i};
	}
	std::sort(event, event+size);
	memset(l, -1, n*sizeof(int));
	memset(r, -1, n*sizeof(int));
	for(int i=0; i<size; ++i) {
		int id=event[i].second;
		id[l[id]==-1?l:r]=i;
	}
}
long long query(int x) {
	long long s=0;
	for(; x; x&=x-1) s+=bit[x];
	return s;
}
void increase(int x) {
	for(; x<size; x+=x&-x) ++bit[x];
}
long long solve() {
	long long tot=0;
	memset(bit, 0, size*sizeof(int));
	for(int id=0; id<size; ++id) {
		int i=event[id].second;
		if(r[i]==id) continue;
		tot+=query(r[i])-query(l[i]);
		increase(r[i]);
	}
	return tot;
}
int main() {
	int m;
	long long tot;
	long double p, q, ans=0;
	std::set<int> cur;
	std::cin>>n>>p>>q>>m;
	for(int i=0; i<n; ++i) {
		std::cin>>a[i]>>b[i];
		a[i]/=1000;
		b[i]=(b[i]+p*a[i]-q)/1000;
	}
	for(p=0, q=1e10; q-p>1e-10; ) {
		int cnt=0;
		long double d=(p+q)/2;
		extract(d);
		long long tot=solve();
		(tot<=m?p:q)=d;
		if(tot==m) break;
	}
	extract(p);
	if(solve()>m) {
		puts("0");
		return 0;
	}
	for(int i=1; i<size; ++i) prev[i]=i-1, next[i-1]=i;
	prev[0]=size-1, next[size-1]=0;
	for(int id=size; id--; ) {
		int i=event[id].second, L=l[i], R=r[i];
		if(id==R) continue;
		for(int it=L; (it=next[it])!=R; ) {
			int j=event[it].second;
			long double x=(b[i]-b[j])/(a[j]-a[i]), y=a[i]*x+b[i];
			ans+=sqrtl(x*x+y*y);
			--m;
		}
		prev[next[L]]=prev[L], next[prev[L]]=next[L];
		prev[next[R]]=prev[R], next[prev[R]]=next[R];
	}
	std::cout<<std::fixed<<std::setprecision(9)<<(ans+m*p)<<std::endl;
	return 0;
}
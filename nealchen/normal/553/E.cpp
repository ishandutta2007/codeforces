#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class S, class T> inline bool cmin(S &a, const T &b) {return b<a?(a=b, 1):0;}
template<class S, class T> inline bool cmax(S &a, const T &b) {return a<b?(a=b, 1):0;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;

typedef double Real;
struct Complex {
	Real re, im;
	Complex &operator+=(const Complex &o) {re+=o.re; im+=o.im; return *this;}
	Complex &operator/=(Real k) {re/=k; im/=k; return *this;}
};

const int V=51, E=200, T=32777;
const Real PI=acos(-1);
const Complex U={1, 0}, I={0, 1};

int n, m, len, a[E], b[E], c[E], dis[V];
Real p[E][T], f[V][T], ans[E][T], cur[T];
Complex w[T], half[T], p_dft[E][T*2], f_dft[V][T], cur_dft[T];

Complex operator~(const Complex &a) {return {a.re, -a.im};}
Complex operator+(const Complex &a, const Complex &b) {return {a.re+b.re, a.im+b.im};}
Complex operator-(const Complex &a, const Complex &b) {return {a.re-b.re, a.im-b.im};}
Complex operator*(const Complex &a, const Complex &b) {return {a.re*b.re-a.im*b.im, a.im*b.re+b.im*a.re};}
Complex operator/(const Complex &a, Real k) {return {a.re/k, a.im/k};}
void init(int len) {
	for(int i=0; i<len/2; ++i) w[len/2+i]={cos(2*PI/len*i), sin(2*PI/len*i)};
	for(int i=len/2; --i; w[i]=w[i*2]);
}
void dft_core(Complex *x) {
	for(int i=1, j=0, k; i<len; ++i) {
		for(k=__builtin_ctz(len); j>>--k&1; ) j^=1<<k;
		j^=1<<k;
		if(i<j) std::swap(x[i], x[j]);
	}
	for(int i=1; i<len; i*=2)
		for(int j=0; j<len; j+=i+i)
			for(int k=0; k<i; ++k) {
				Complex z=w[i+k]*x[i+j+k];
				x[i+j+k]=x[j+k]-z;
				x[j+k]+=z;
			}
}
void dft(const Real *x, Complex *f) {
	assert(len!=1);
	assert((len&(len-1))==0);
	len/=2;
	for(int i=0; i<len; ++i) half[i]={x[2*i], x[2*i+1]};
	dft_core(half);
	f[0]={half[0].re+half[0].im, 0};
	f[len]={half[0].re-half[0].im, 0};
	for(int i=1; i<len; ++i) {
		Complex z=I*w[len+i];
		f[i]=((U-z)*half[i]+(U+z)*~half[len-i])/2;
		f[len+i]=((U+z)*half[i]+(U-z)*~half[len-i])/2;
	}
	len*=2;
}
void idft(const Complex *f, Real *x) {
	assert(len!=1);
	assert((len&(len-1))==0);
	len/=2;
	half[0]=((U+I)*f[0]+(U-I)*f[len])/2;
	for(int i=1; i<len; ++i) {
		Complex z=I*w[2*len-i];
		half[len-i]=((U-z)*f[i]+(U+z)*f[len+i])/2;
	}
	dft_core(half);
	for(int i=0; i<len; ++i) x[2*i]=half[i].re/len, x[2*i+1]=half[i].im/len;
	len*=2;
}
void solve(int l, int lv) {
	if(lv==0) {
		for(int i=0; i<m; ++i) cmin(f[a[i]][l], ans[i][l]);
	} else {
		solve(l, lv-1);
		len=1<<lv;
		if(len<=32) {
			for(int i=0; i<m; ++i)
				for(int j=0; j<len/2; ++j)
					for(int k=len/2-j; k<len-j; ++k)
						ans[i][l+j+k]+=f[b[i]][l+j]*p[i][k];
		} else {
			memset(cur+len/2, 0, len/2*sizeof(Real));
			for(int i=1; i<=n; ++i) {
				memcpy(cur, f[i]+l, len/2*sizeof(Real));
				dft(cur, f_dft[i]);
			}
			for(int i=0; i<m; ++i) {
				for(int j=0; j<len; ++j) cur_dft[j]=f_dft[b[i]][j]*p_dft[i][len+j];
				idft(cur_dft, cur);
				for(int j=len/2; j<len; ++j) ans[i][l+j]+=cur[j];
			}
		}
		solve(l+len/2, lv-1);
	}
}
int main() {
	int t, lv_t;
	n=rd(), m=rd(), t=rd(), dis[n]=rd();
	lv_t=32-__builtin_clz(t);
	init(1<<lv_t);
	for(int i=0; i<m; ++i) {
		a[i]=rd(), b[i]=rd(), c[i]=rd();
		for(int j=1; j<=t; ++j) p[i][j]=rd()/1e5;
	}
	for(int i=0; i<m; ++i)
		for(int j=1; j<=lv_t; ++j) {
			len=1<<j;
			dft(p[i], p_dft[i]+len);
		}
	memset(dis+1, 63, (n-1)*sizeof(int));
	for(int k=n; k--; ) for(int i=0; i<m; ++i) cmin(dis[a[i]], dis[b[i]]+c[i]);
	std::fill(f[n], f[n]+t+1, -dis[n]);
	for(int i=0; i<m; ++i) std::fill(ans[i], ans[i]+t+1, dis[b[i]]+c[i]-dis[a[i]]);
	solve(0, lv_t);
	std::cout<<std::fixed<<std::setprecision(15)<<f[1][t]+dis[1]<<std::endl;
	return 0;
}
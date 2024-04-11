#include<bits/stdc++.h>
#define N 200007
#define M 524600
#define VAL 3000007
#define mod 998244353
#define G 3
#define iG 332748118
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}
priority_queue< pair<int, int> > q;
struct Poly {
	vector<int> a; 
} f[N];
int n, m, pp[M], tot;
int qpow(int x, int y) {
	if(x == 0) return 0;
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
void fft(int *f, int len, int flag) {
	for(int i = 0; i < len; ++i) if(pp[i] < i) swap(f[pp[i]], f[i]); 
	for(int i = 2; i <= len; i <<= 1) {
		int FL = (i >> 1), ch = qpow(flag + 1 ? G : iG, (mod - 1) / i);
		for(int j = 0; j < len; j += i) {
			int now = 1;
			for(int k = j; k < j + FL; ++k) {
				int ga = f[k], gb = 1ll * f[k + FL] * now % mod;
				f[k] = (ga + gb) % mod;
				f[k + FL] = (ga - gb + mod) % mod;
				now = 1ll * now * ch % mod;
			}
		}
	}
	if(flag == -1) {
		int nny = qpow(len, mod - 2);
		for(int i = 0; i < len; ++i) f[i] = 1ll * f[i] * nny % mod;
	}
}
int a[M], b[M];
void merge (Poly &x, Poly y) {
	int la = 0, lb = 0;
	while(!x.a.empty()) a[la++] = x.a.back(), x.a.pop_back();
	reverse(a, a + la); 
	while(!y.a.empty()) b[lb++] = y.a.back(), y.a.pop_back();
	reverse(b, b + lb);
	int lc = la + lb - 1;
	for(; lc != (lc & -lc); lc += (lc & -lc));
	for(int i = 0; i < lc; ++i) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lc >> 1)));
	fft(a, lc, 1), fft(b, lc, 1);
	for(int i = 0; i < lc; ++i) a[i] = 1ll * a[i] * b[i] % mod;
	fft(a, lc, -1); 
	for(int i = 0; i < la + lb - 1; ++i) x.a.push_back(a[i]);
	for(int i = 0; i < lc; ++i) a[i] = b[i] = 0;
}
int cnt[VAL], p[N];
int main() {
	n = read();
	for(int i = 1; i <= n; ++i) p[i] = read(), cnt[p[i]]++;
	for(int i = 1; i <= n; ++i)
		if(cnt[p[i]]) {
			++tot;
			for(int j = 0; j <= cnt[p[i]]; ++j) f[tot].a.push_back(1);
			q.push(make_pair(-cnt[p[i]], tot));
			cnt[p[i]] = 0;
		}
	while(q.size() != 1) {
		int sa = q.top().second;
		q.pop();
		int sb = q.top().second;
		q.pop();
		merge(f[sa], f[sb]);
		q.push(make_pair(-f[sa].a.size(), sa));
	}
	int pp = q.top().second, mm = 0;
	for(auto i : f[pp].a) {
		++mm;
		if(mm == n / 2 + 1) return printf("%d\n", i), 0;
	}
	return 0;
}
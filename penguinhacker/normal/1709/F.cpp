#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=998244353; // 119*2^23+1
const int pr=5; // primitive root of both 10^9+7 and 998244353, use https://www.wolframalpha.com/widgets/view.jsp?id=ef51422db7db201ebc03c8800f41ba99 to find primitive roots

int add(int a, int b) { if ((a+=b)>=M) a-=M; return a; }
int sub(int a, int b) { if ((a-=b)<0) a+=M; return a; }
int mul(int a, int b) { return (ll)a*b%M; }

int bp(int b, int p=M-2) { // binary power
	int r=1;
	for (; p; p>>=1, b=mul(b, b))
		if (p&1)
			r=mul(r, b);
	return r;
}

int rt[24];

void pc() {
	rt[23]=bp(pr, 119);
	for (int i=22; i; --i)
		rt[i]=mul(rt[i+1], rt[i+1]);
}

template<class T> void ntt(vector<T>& p, bool inverse) {
	int n=p.size();
	for (int i=1, j=0; i<n; ++i) {
		int bit=n>>1;
		for (; j>=bit; bit>>=1)
			j-=bit;
		j+=bit;
		if (i<j)
			swap(p[i], p[j]);
	}

	for (int len=2; len<=n; len<<=1) {
		int w=rt[__builtin_ctz(len)];
		if (inverse)
			w=bp(w);
		for (int i=0; i<n; i+=len) {
			int cw=1;
			for (int j=0; j<len/2; ++j) {
				int a=p[i+j], b=mul(p[i+j+len/2], cw);
				p[i+j]=add(a, b);
				p[i+j+len/2]=sub(a, b);
				cw=mul(cw, w);
			}
		}
	}
}

template<class T> vector<T> mul(vector<T> a, vector<T> b) {
	assert(a.size()&&b.size());

	int max_deg=a.size()-1+b.size()-1;
	int n=1;
	while(n<max_deg+1)
		n*=2;
	a.resize(n);
	b.resize(n);

	int ninv=bp(n);
	ntt(a, 0);
	ntt(b, 0);
	for (int i=0; i<n; ++i)
		a[i]=mul(mul(a[i], b[i]), ninv);
	ntt(a, 1);

	a.resize(max_deg+1);
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	pc();
	int n, k, f;
	cin >> n >> k >> f;
	vector<int> a(k+1, 1);
	for (int rep=1; rep<n; ++rep) {
		a=mul(a, a);
		assert(a.size()>=2&&a.size()-1>=k);
		vector<int> pref=a;
		for (int i=a.size()-2; ~i; --i)
			pref[i]=add(pref[i], pref[i+1]);
		a.resize(k+1);
		for (int i=0; i<=k; ++i)
			a[i]=add(pref[i], mul(a[i], k-i));
	}
	//for (int i : a)
	//	cout << i << endl;
	int ans=0;
	for (int i=0; i<=f; ++i)
		if (a.size()>i&&a.size()>f-i)
			ans=add(ans, mul(a[i], a[f-i]));
	cout << ans;
	return 0;
}
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define Mod 998244353
#define ll long long
#define uint unsigned int
using namespace std;
namespace IO {
	char _buf[1 << 21], *_p1 = _buf, *_p2 = _buf;
#define ch()                                                                 \
  (_p1 == _p2 &&                                                             \
           (_p2 = (_p1 = _buf) + fread(_buf, 1, 1 << 21, stdin), _p1 == _p2) \
       ? EOF                                                                 \
       : *_p1++)
	inline int Read() {
  		int s = 0, f = 1;
  		char x = ch();
  		while (x < '0' || x > '9') {
    		if (x == '-') f = -1;
    		x = ch();
  		}
  		while (x >= '0' && x <= '9') {
    		s = (s * 10) + (x & 15);
    		x = ch();
  		}
  		return f == 1 ? s : -s;
  		/*int x;
  		cin>>x;
  		return x;*/
	}
	char _buf_[1 << 21];
	int _p1_ = -1;
	inline void flush() {
  		fwrite(_buf_, 1, _p1_ + 1, stdout);
  		_p1_ = -1;
  		return;
	}
	inline void pc(char x) {
  		if (_p1_ == (1 << 21) - 1) flush();
  		_buf_[++_p1_] = x;
  		return;
	}
	inline void Write(int x) {
  		if (!x) pc('0');
  		char k[20];
  		int tot = 0;
		if (x < 0) {
    		pc('-');
    		x = -x;
  		}
  		while (x) {
    		k[++tot] = (x % 10) | 48;
    		x /= 10;
  		}
  		for (int i = tot; i; i--) pc(k[i]);
  		return;
	}
	inline void out(string x) {
  		int len = x.size();
  		for (int i = 0; i < len; i++) pc(x[i]);
  		return;
	}
}  // namespace IO
using namespace IO;
uint Add(uint a, uint b) {return (a + b >= Mod) ? a + b - Mod : a + b;}
uint Dec(uint a, uint b) {return (a - b < 0) ? a - b + Mod : a - b;}
uint Mul(uint a, uint b) {return 1ll * a * b % Mod;}
uint qpow(uint a, int b) {uint res = 1; for(; b; b >>= 1, a = Mul(a, a))  if(b & 1)  res = Mul(res, a); return res;}
namespace NTT {
	int sz;
	uint w[12500005], w_mf[12500005];
	uint mf(int x) {return ((1ll * x) << 32) / Mod;}
	void init(int n) {
		for(sz = 2; sz < n; sz <<= 1);
		uint pr = qpow(3, (Mod - 1) / sz);
		w[sz / 2] = 1; w_mf[sz / 2] = mf(w[sz / 2]);
		for(int i = 1; i < sz / 2; i++)  w[sz / 2 + i] = Mul(w[sz / 2 + i - 1], pr), w_mf[sz / 2 + i] = mf(w[sz / 2 + i]);
		for(int i = sz / 2 - 1; i; i--)  w[i] = w[i << 1], w_mf[i] = w_mf[i << 1];
	}
	void NTT(vector<uint>& A, const int L) {
		for(int d = L >> 1; d; d >>= 1)
			for(int i = 0; i != L; i += d << 1)
				for(int j = 0; j != d; j++) {
					uint x = A[i + j] + A[i + d + j];
					if(x >= Mod * 2)  x -= Mod * 2;
					ll t = A[i + j] + Mod * 2 - A[i + d + j];
					ll q = t * w_mf[d + j] >> 32;
					uint y = t * w[d + j] - q * Mod;
					A[i + j] = x; A[i + d + j] = y;
				}
	}
	void INTT(vector<uint>& A, const int L) {
		for(int d = 1; d != L; d <<= 1)
			for(int i = 0; i != L; i += (d << 1))
				for(int j = 0; j != d; j++) {
					uint x = A[i + j];
					if(x >= Mod * 2)  x -= Mod * 2;
					ll y = A[i + d + j], q = y * w_mf[d + j] >> 32, t = y * w[d + j] - q * Mod;
					A[i + j] = x + t; A[i + d + j] = x + Mod * 2 - t;
				}
		reverse(A.begin() + 1, A.end());
		int k = __builtin_ctz(L);
		for(int i = 0; i != L; i++) {
			ll m = -A[i] & (L - 1);
			A[i] = (A[i] + m * Mod) >> k;
		}
	}
} // namespace NTT
int N;
vector<int>v[2500005];
int tong[2500005],q[2500005];
struct poly {
	vector<uint> a;
	int deg() {return a.size() - 1;}
	uint& operator [] (const int &x) {return a[x];}
	poly(int d = 0, int t = 0) {a.resize(d + 1); a[d] = t;}
	poly extend(int len) {
		poly c = *this;
		c.a.resize(len + 1);
		return c;
	}
	void Get(int len) {a.resize(len + 1);int x;for(int i = 1; i <= N; i++)
	{
	x=Read();
	a[x]=1;
	tong[x]++,q[i]=x,v[x].push_back(i);}
	}
	void Print(int len) {for(int i = 0; i <= len; i++)  Write(a[i]), pc(' '); pc('\n');}
	friend poly operator * (poly A, poly B) {
		int len = A.deg() + B.deg() + 2, lim = 2;
		for(; lim <= len; lim <<= 1); NTT::init(lim);
		A.a.resize(lim); B.a.resize(lim);
		NTT::NTT(A.a, lim); NTT::NTT(B.a, lim);
		//A.Print(lim - 1);  B.Print(lim - 1); 
		for(int i = 0; i < lim; i++)  A[i] = Mul(A[i], B[i]);
		NTT::INTT(A.a, lim); A.a.resize(len);
		for(int i = 0; i < len; i++){
			if(A[i] >= Mod)  A[i] -= Mod;
		}
		return A;
	}
};
 
int main() {
//	freopen("ss.in","r",stdin);
	poly A, B;
	int n = Read();
	N=n;
	A.Get(2500000);
	B.a.resize(2500000);
	int qz=0;
	for(int i=1;i<=2500000;i++){
		if(qz and tong[i]>=2){
			cout<<"YES"<<endl<<v[qz][0]<<" "<<v[i][0]<<" "<<v[qz][1]<<" "<<v[i][1];
			return 0;
		}
		if(tong[i]>=4){
			cout<<"YES"<<endl;
			cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<" "<<v[i][3]<<endl;
			return 0;
		}
		if(tong[i]>=2){
			qz=i;
		}
		B.a[i]=A.a[i];
	}
	A = A * B;
	sort(q+1,q+n+1);
	for(int i=1;i<=5000000;i++){
		if(A.a[i]>=4)
		{
		//	cout<<A.a[i]<<" "<<i<<endl;
			int bj=0;
			for(int k=1;k<=n;k++){
				if(q[k]>=i)break;
				if(i-q[k]>2500000)continue;
				if(bj and tong[i-q[k]] and q[bj]!=q[k]){
					cout<<"YES"<<endl;
					int x=v[i-q[k]][0];int y=v[q[k]][0];
					int z=v[i-q[bj]][0];int hh=v[q[bj]][0];
					//if(x==y || y==z || z==hh || x==z || x==hh || y==hh){
					//	while(1);
					//}
					cout<<v[i-q[k]][0]<<" "<<v[q[k]][0]<<" "<<v[i-q[bj]][0]<<" "<<v[q[bj]][0]<<endl;
				//	cout<<q[k]<<" "<<i-q[k]<<" "<<i-q[bj]<<" "<<q[bj];
					break;
				}
				if(tong[i-q[k]]){
					bj=k;
				}
			}
			return 0;
		}
	}
	for(int i=1;i<=2500000;i++){
		if(tong[i]>=2){
			for(int k=1;k<=n;k++){
				if(q[k]!=i and tong[2*i-q[k]]){
					cout<<"YES"<<endl;
					cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[q[k]][0]<<" "<<v[2*i-q[k]][0];
					return 0;
				}
			}
		}
	}
	cout<<"NO";
	return 0;
}
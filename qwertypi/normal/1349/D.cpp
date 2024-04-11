#include <bits/stdc++.h>

#define modular modular
using namespace std;

template<typename T>
T bpow(T x, size_t n) {
	return n ? n % 2 ? x * bpow(x, n - 1) : bpow(x * x, n / 2) : T(1);
}
	
template<int m>
struct modular {
	int64_t r;
	modular() : r(0) {}
	modular(int64_t rr) : r(rr) {if(abs(r) >= m) r %= m; if(r < 0) r += m;}
	modular inv() const {return bpow(*this, m - 2);}
	modular operator * (const modular &t) const {return (r * t.r) % m;}
	modular operator / (const modular &t) const {return *this * t.inv();}
	modular operator += (const modular &t) {r += t.r; if(r >= m) r -= m; return *this;}
	modular operator -= (const modular &t) {r -= t.r; if(r < 0) r += m; return *this;}
	modular operator + (const modular &t) const {return modular(*this) += t;}
	modular operator - (const modular &t) const {return modular(*this) -= t;}
	modular operator *= (const modular &t) {return *this = *this * t;}
	modular operator /= (const modular &t) {return *this = *this / t;}
	
	bool operator == (const modular &t) const {return r == t.r;}
	bool operator != (const modular &t) const {return r != t.r;}
	
	operator int64_t() const {return r;}
};
	
const int m = 998244353;
modular<m> f[300001];
modular<m> g[300001];
int n;

int A[100000];
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	int s = accumulate(A, A + n, 0);
	f[0] = n - 1;
	for(int i = 1; i < s; i++){
		modular<m> neg = modular<m>(i) / modular<m>(s);
		modular<m> pos = modular<m>(s - i) / modular<m>(s) / modular<m>(n - 1);
		f[i] = (modular<m>(1) + neg * f[i - 1]) / pos;
	}
	for(int i = s - 2; i >= 0; i--){
		f[i] += f[i + 1];
	}
	
	modular<m> ans = modular<m>(1 - n) * f[0];
	for(int i = 0; i < n; i++){
		ans += f[A[i]];
	}
	
	ans /= modular<m>(n);
	cout << ans << endl;
}
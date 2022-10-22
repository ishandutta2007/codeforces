#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct frac {
	ll a, b;
	frac() : a(0), b(0) {}
	frac(ll _a, ll _b) : a(_a), b(_b) {
		if (b==0) assert(0);
		if (a==0) a=0, b=-1;
		else reduce(a, b);
	}
	void reduce(ll& a, ll& b) {
		int sign=((a<0)^(b<0))?-1:1;
		ll x=__gcd(abs(a), abs(b));
		a=sign*abs(a)/x, b=abs(b)/x;
	}
	friend ostream& operator<< (ostream& out, const frac& f) {
		return out << "[" << f.a << ", " << f.b << "]";
	}
	friend bool operator==(const frac& f1, const frac& f2) { 
		return f1.a==f2.a&&f1.b==f2.b; }
	friend bool operator!=(const frac& f1, const frac& f2) { 
		return !(f1==f2); }
	friend bool operator<(const frac& f1, const frac& f2) { 
		return f1.a==f2.a?f1.b<f2.b:f1.a<f2.a; }
};

int n;
set<frac> oc;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; ++i) {
		int m, b; cin >> m >> b;
		if (m==0) continue;
		//0=mx+b --> -b/m
		oc.insert(frac(-b, m));
	}
	cout << oc.size();
	return 0;
}
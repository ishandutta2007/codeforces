#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7;
struct bint { // x >= 0
	vi a;
	bint (ll x = 0) { 
		while (x) a.push_back(x % 10), x /= 10; 
	}
	bint (string s) {
		int l = sz(s);
		a.resize (l);
		L(i, 0, l - 1) a[l - i - 1] = s[i] - '0';
	}
	bint (vi o) { 
		a = o;
	}
	bint size () {
		return sz(a);
	}
	inline int & operator [] (int x) {
		return a[x];
	}
	bool operator < (const bint &b) const {
		if(sz(a) != sz(b.a)) return sz(a) < sz(b.a);
		R(i, sz(a) - 1, 0) if(a[i] != b.a[i]) return a[i] < b.a[i];
		return false ;
	}
	bool operator == (const bint &b) const {
		if(sz(a) != sz(b.a)) return false;
		L(i, 0, sz(a) - 1) if(a[i] != b.a[i]) return false;
		return true ;
	}
	void mul2 () {
		a.push_back(0);
		L(i, 0, sz(a) - 1) a[i] *= 2;
		L(i, 0, sz(a) - 1) if(a[i] >= 10) a[i] -= 10, a[i + 1] += 1;
		while (sz(a) > 1 && a[sz(a) - 1] == 0) a.pop_back();
	}
	void div2 () {
		int ret = 0;
		R(i, sz(a) - 1, 0) ret += a[i], a[i] = ret / 2, ret = (ret & 1) * 10;
		while (sz(a) > 1 && a[sz(a) - 1] == 0) a.pop_back();
	}
	bint operator - (const bint &b) {
		if((*this) < b) 
			assert (false);
		bint ret = a;
		L(i, 0, sz(b.a) - 1) ret[i] -= b.a[i];
		L(i, 0, sz(ret.a) - 1) if(ret[i] < 0) ret[i + 1] -= 1, ret[i] += 10;
		while (sz(ret.a) > 1 && ret[sz(ret.a) - 1] == 0) ret.a.pop_back();
		return ret;
	}
	bint operator + (const bint &b) {
		bint ret = a;
		ret.a.resize(max(sz(a), sz(b.a)) + 1);
		L(i, 0, sz(b.a) - 1) ret[i] += b.a[i];
		L(i, 0, sz(ret.a) - 1) if(ret[i] >= 10) ret[i + 1] += 1, ret[i] -= 10;
		while (sz(ret.a) > 1 && ret[sz(ret.a) - 1] == 0) ret.a.pop_back();
		return ret;
	}
	void print (char c = '@') {
		R(i, sz(a) - 1, 0) cout << a[i];
		if(c != '@') cout << c;
	}
	friend bint mod (bint a, bint b) {
		int p = 0;
		while (!(a < b)) p += 1, b.mul2 ();
		while (p--) {
			b.div2 ();
			if (!(a < b)) a = a - b;
		}
		return a;
	} 
	friend bint div (bint a, bint b) {
		bint w = 0;
		int p = 0;
		while (!(a < b)) p += 1, b.mul2 ();
		while (p--) {
			b.div2 (), w.mul2();
			if (!(a < b)) a = a - b, w = w + ((bint) 1);
		}
		return w;
	} 
	friend bint gcd (bint a, bint b) {
		int cnt = 0;
		if(a < b) swap (a, b);
//		a.print(' '), b.print('\n');
		while (sz(b.a) > 1 || b[0] != 0) {
			if((a[0] & 1) && (b[0] & 1)) a = a - b;
			else if(b[0] & 1) a.div2();
			else if(a[0] & 1) b.div2();
			else a.div2 (), b.div2 (), cnt += 1;
			if(a < b) swap (a, b);
//			a.print(','), b.print('\n');
		}
		while (cnt --) a.mul2();
		return a;
	}
};
mt19937_64 orz(time(0) ^ clock());
string pn;
int tp;
ll mx;
bint n, f[30];
bint SQRT (bint w) {
	cout << "sqrt ";
	w.print();
	cout << endl;

//	if(!(w < n)) assert (false); 
//	
//	ll z = 1;
//	while (!((bint) z == n)) 
//		z += 1; 
//	
//	L(i, 0, z - 1) if((bint) (i * i % z) == w) {
//		return i;
//	}
//	return assert (false), -1;
	
	string x;
	cin >> x;
	if(x[0] == '-') assert (false);
	return (bint) x;
}
void solve (bint t) {
//	t.print();
//	cout << endl;
	for (int i = tp; i >= 1; --i) {
		bint x = gcd (f[i], t);
//		cout << "x = " ;
//		x.print();
//		cout << '\n';
		if(!(x == f[i]) && !(x == (bint) 1)) 
			f[++tp] = div (f[i], x), f[i] = x; 
	}
}
bint Div2 (bint x) {
	if (x[0] & 1) x = x + n;
	x.div2();
	return x;
}
bint Mul2 (bint x) {
	x.mul2();
	if(!(x < n)) x = x - n; 
	return x;
}
int main() {
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> pn, n = f[1] = pn, tp = 1;
	mx = 1LL << 30;
	while (n < (bint) mx) mx >>= 1;
	L(i, 1, 40) {
//		bint u = 9;
		ll R = orz() % mx + 1;
		while (!(gcd(n, (bint) R) == (bint) 1)) R = orz() % mx + 1;
		bint u = mod (R * R, n), w = R;
		u = Div2 (u), u = Div2 (u);
		bint h = SQRT (u);
		h = Mul2 (h);
		if(w == h) continue ;
		solve (w + h);
		solve (w < h ? h - w : w - h);
//		if (tp != 1) break ;
	}
	cout << "! " << tp << ' ';
	L(i, 1, tp) f[i].print(' ');
	cout << endl;
	return 0;
}
#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define il inline

using namespace std;

void GG() {
	cout << -1 << endl , exit(0);
}

typedef long long ll;

const int N = 110 , P = 1000000007;
ll mul(ll x , ll y) {return 1ll * x * y % P;}
void upd(ll &x , ll y) {x = mul(x , y);}
ll Pow(ll x , ll y) {ll ret = 1; while(y){if(y & 1) upd(ret , x); upd(x , x) , y >>= 1;} return ret;}
ll gcd(ll a , ll b) {return b == 0 ? a : gcd(b , a % b);}

struct Num {
	vector<pair<int, ll>> p;
	il void read() {
		int x; cin >> x;
		for (int i = 2; i * i <= x; i++)
			if (!(x % i)) {
				p.pb(mp(i , 0ll));
				while (!(x % i))
					++p.back().se , x /= i;
			}
		if (x != 1) p.pb(mp( x, 1ll));
	}
	il void out() {
		ll ans = 1;
		for (auto o : p) if(o.se < 0) GG();
		for (auto o : p) upd(ans , Pow(o.fi , o.se));
		cout << ans << endl;
	}
	#define s(o) o.p.size()
	#define x(o) x.p[o]
	#define y(o) y.p[o]
	#define z(o) z.p.pb(o)
	il friend bool operator == (Num x , Num y) {
		if(s(x) != s(y)) return false;
		for(int i = 0; i < s(x); i++)
			if(x(i).fi != y(i).fi || x(i).se != y(i).se)
				return false;
		return true; 
	}
	il friend Num operator * (Num x , Num y) {
		Num z;
		int i = 0 , j = 0;
		while (i < s(x) && j < s(y))
			if (x(i).fi == y(j).fi)
				z(mp(x(i).fi , x(i).se + y(j).se)) , ++i , ++j;
			else if (x(i).fi < y(j).fi) z(x.p[i++]);
			else z(y.p[j++]);
		while (i < s(x)) z(x.p[i++]);
		while (j < s(y)) z(y.p[j++]);
		return z;
	}
	il friend bool operator % (Num x , Num y) {
		for (int i = 0, j = 0; j < s(y); i++ , j++) {
			while (i < s(x) && x(i).fi != y(j).fi) ++i;
			if (i == s(x) || x(i).se < y(j).se) return 1;
		}
		return 0;
	}
	il friend Num operator / (Num x , Num y) {
		Num z;
		for (int i = 0 , j = 0; i < s(x); i++)
			if (j < s(y) && x(i).fi == y(j).fi) {
				z(mp(x(i).fi , x(i).se - y(j++).se));
				if (!z.p.back().se) z.p.pop_back();
			} else z(x(i));
		return z;
	}
	il friend Num operator & (Num x , Num y) {
		Num z;
		for (int i = 0, j = 0; i < s(x); i++)
			if (j < s(y) && x(i).fi == y(j).fi)
				z(mp(x(i).fi , x(i).se - y(j++).se));
			else z(x(i));
		return z;
	}
	il friend bool operator | (Num x , Num y) {
		if (!s(x)) return 0; ll k;
		for (int i = 0 , j = 0; i <= s(x); i++ , j++) {
			while (j < s(y) && !y(j).se) ++j;
			if (i == s(x)) {
				if (j == s(y)) return 0;
				return 1;
			}
			if (j == s(y)) return 1;
			if (x(i).fi != y(j).fi || x(i).se % y(j).se) return 1;
			if (!i) k = x(i).se / y(j).se;
			else if ((x(i).se / y(j).se) != k) return 1;
		}
		return 0;
	}
	il friend Num operator ^ (Num x , ll y) {
		for (auto &o : x.p) o.se *= y;
		return x;
	}
	il friend Num operator + (Num x , Num y) {
		Num z;
		for (int i = 0; i < s(x); i++)
			z(mp(x(i).fi, x(i).se * y(i).se / gcd(x(i).se , y(i).se)));
		return z;
	}
}	a[N], b[N], c[N], A, B;

int n;

bool check(Num x) {
	for(int i = 1; i <= n; i++)
		if((x % a[i]) || ((x / a[i]) | b[i]))
			return false;
	return true; 
}

struct Pro {
	ll k , b , p;
	inline Pro(ll k = 0 , ll b = 0 , ll p = 0) : k(k) , b(b) , p(p) {}
	bool operator == (const Pro t) const {
		return k == t.k && b == t.b && p == t.p;
	}
};

void exgcd(ll a , ll b , ll &x , ll &y) {
	if(b == 0) return x = 1 , y = 0 , void();
	exgcd(b , a % b , y , x);
	return y -= a / b * x , void();
}

ll solve(Pro x , Pro y) {
	ll a = x.b * y.p - y.b * x.p , b = x.k * y.p - y.k * x.p;
	if (!b || a % b) GG();
	return a / b;
}
bool merge(int o) {
	vector <Pro> pro;
	for(int i = 0; i < A.p.size(); i++) {
		ll k1 = B.p[i].se , b1 = A.p[i].se;
		ll k2 = b[o].p[i].se , b2 = a[o].p[i].se;
		if(!k1 && !k2) {
			if(b1 ^ b2) GG();
			continue;
		}
		if(!k1) {
			if(b1 < b2 || (b1 - b2) % k2) GG();
			return A = a[o] * (b[o] ^ ((b1 - b2) / k2)) , 0;
		}
		if(!k2) {
			if(b2 < b1 || (b2 - b1) % k1) GG();
			return A = A * (B ^ ((b2 - b1) / k1)) , 0;
		}
		ll d = gcd(k1 , k2) , g = b2 - b1;
		if(g % d) GG();
		g /= d , k1 /= d , k2 /= d;
		if(pro.size()) {
			if(pro[0] == Pro(k1 , g , k2)) continue;
			return A = A * (B ^ solve(pro[0] , Pro(k1 , g , k2))) , 0;
		}
		pro.pb(Pro(k1 , g , k2));
	}
	if(pro.size()) {
		ll k1 = pro[0].k , p1 = pro[0].p , b1 = pro[0].b , x , y;
		exgcd(k1 , p1 , x , y);
		b1 = (b1 % p1 + p1) % p1;
		x = (x % p1 * b1 % p1 + p1) % p1;
		A = A * (B ^ x) , B = B + b[o];
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false); 
	cin >> n;
	for(int i = 1; i <= n; i++)
		a[i].read() , b[i].read() , c[i] = a[i] * b[i];
	int flag = 1;
	for(int i = 2; i <= n; i++)
		if(!(a[i] == a[1])) {
			flag = false; break;
		}
	if(flag == 1) return a[1].out() , 0;
	for(int i = 1; i <= n; i++) if(check(a[i])) return a[i].out() , 0;
	for(int i = 1; i <= n; i++) {
		if(c[i].p.size() != c[1].p.size()) GG();
		for(int j = 0; j < c[1].p.size(); j++)
			if(c[i].p[j].fi ^ c[1].p[j].fi) GG();
		a[i] = c[i] & b[i] , b[i] = c[i] & a[i];
	}
	A = a[1] , B = b[1];
	for(int i = 2; i <= n; i++) {
		if(!merge(i)) {
			if(check(A)) return A.out(), 0; GG();
		}
	}
	return A.out() , 0;
	return 0;
}
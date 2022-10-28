#include <bits/stdc++.h>

using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(char s) { return string(1, s);}
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (auto it = v.begin(); it != v.end(); ++it) {if (!f)r += ", "; f = 0; r += to_string(*it);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int extended_euclid(int a, int b, int &x, int &y) {
	int xx = y = 0;
	int yy = x = 1;
	while (b) {
		int q = a / b;
		int t = b; b = a % b; a = t;
		t = xx; xx = x - q * xx; x = t;
		t = yy; yy = y - q * yy; y = t;
	}
	return a;
}


  ll extended_euclidean(ll a, ll b, ll &x, ll &y) {
    ll xx, yy, q, t; x = yy = 1, xx = y = 0;
    while( b != 0 ) {
      q = a / b, t = b, b = a % b, a = t;
      t = xx, xx = x - q * xx, x = t;
      t = yy, yy = y - q * yy, y = t;
    }
    return a;
  }

  /* Linear Diophantine equation solver. */
  bool lde_solver(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
    g = extended_euclidean(a, b, x, y);
    if( c % g != 0 ) return false;
    x *= c / g, y *= c / g;
    return true;
  }

  bool non_negative_lde(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
    if( not lde_solver(a, b, c, x, y, g) ) return false;
    if( x < 0 or y < 0 ) {
      ll dx = b / g, dy = a / g, steps;
      if( x < 0 ) steps = (-x + dx - 1) / dx;
      if( y < 0 ) steps = - (-y + dy - 1) / dy;
      x += steps * dx, y -= steps * dy;
      if( x < 0 or y < 0 ) return false;
    }
    return true;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ll n; cin >> n;
	FOR (i, 2, min(n-1, 100000LL)) if (n % i == 0) {
		ll a = 1, b = n;
		while (b % i == 0) b /= i, a *= i;
		if (b == 1) {
			cout << "NO\n";
			return 0;
		}
		ll x, y, g;
		assert(non_negative_lde(a, b, n-1, x, y, g));
		cout << "YES\n";
		cout << "2\n";
		assert(x < b and y < a);
		cout << x << " " << b << "\n";
		cout << y << " " << a << "\n";
		return 0;
	}
	cout << "NO\n";

	return 0;
}
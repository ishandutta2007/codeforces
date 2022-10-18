#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

vl manacher_odd(const string &str) {
	ll n = sz(str), j = 0; // j = center of palindrome that extends the most to the right
	vl rad(n);
	
	FOR(i,0,n) {
		if (i <= j+rad[j]) rad[i] = min(rad[2*j-i], j+rad[j]-i);
		ll L = i-rad[i], R = i+rad[i];
		while (L-1 >= 0 && R+1 < n && str[L-1] == str[R+1]) L--, R++, rad[i]++;
		if (i+rad[i] > j+rad[j]) j = i;
	}
	return rad;
}

vl manacher(const string &str) {
	ll n = sz(str);
	string pad(2*n-1,' ');
	FOR(i,0,n) pad[2*i] = str[i];
	vl res = manacher_odd(pad);
	FOR(i,0,2*n-1) res[i] += i%2 == res[i]%2;
	return res;
}

string prefix_palindrome(string s) {
	ll n = sz(s), k = 0;
	if (n == 0) return "";
	vl v = manacher(s);
	
	FOR(i,1,n+1) if (v[i-1] == i) k = max(k,i);
	return s.substr(0,k);
}

string solve() {
	string s; cin >> s;

	ll n = sz(s);
	ll i = 0;
	while (i < n-i-1 && s[i] == s[n-i-1]) i++;
	
	string t = s.substr(i,n-2*i);
	
	string u = "";
	FOR(dir,0,2) {
		string v = prefix_palindrome(t);
		if (sz(v) > sz(u)) u = v;
		reverse(all(t));
	}
	return s.substr(0,i) + u + s.substr(n-i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	prefix_palindrome("ababb");


	ll tc; cin >> tc;
	while (tc--) {
		cout << solve() << endl;
	}
}
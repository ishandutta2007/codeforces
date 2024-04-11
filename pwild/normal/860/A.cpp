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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

bool is_vowel(char c) {
	if (c == 'a') return true;
	if (c == 'e') return true;
	if (c == 'i') return true;
	if (c == 'o') return true;
	if (c == 'u') return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s; cin >> s;

	ll n = sz(s);
	vb space(n);
	for (ll i = 0; i < n;) {
		if (is_vowel(s[i])) { i++; continue; }
		ll j = i;
		while (j < n && !is_vowel(s[j])) j++;
		
		if (j > i+1) {
			if (s[i+1] == s[i]) {
				j = i+1;
				while (j < n && s[j] == s[i]) j++;
			} else {
				j = i+2;
			}
			if (j < n && !is_vowel(s[j])) space[j-1] = true;
		}
		i = j;
	}
	
	FOR(i,0,n) {
		cout << s[i];
		if (i < n-1 && space[i]) cout << " ";
	}
	cout << endl;

}
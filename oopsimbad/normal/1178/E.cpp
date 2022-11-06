#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	string s; cin >> s;
	int n = s.length()-1;
	vector<char> v;
	for(int i = 0; i < s.length()/2-1; i += 2) {
		if(s[i] == s[n-i]) v.pb(s[i]);
		else if(s[i+1] == s[n-i]) v.pb(s[i+1]);
		else if(s[i] == s[n-i-1]) v.pb(s[i]);
		else if(s[i+1] == s[n-i-1]) v.pb(s[i+1]);
	}
	for(auto x : v) cout << x;
	if(s.length()/2%2 == 1) cout << s[s.length()/2];
	for(auto x = v.rbegin(); x != v.rend(); x++) cout << *x;
	cout << endl;
///
	return 0;
}
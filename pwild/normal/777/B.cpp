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

ll n;

ll minimize_mine(deque<char> a, deque<char> b) {
	FOR(k,0,n) {
		auto ita = begin(a), itb = begin(b);
		bool ok = true;
		for (; ita != end(a); ita++, itb++) {
			if (*ita > *itb) ok = false;
		}
		if (ok) return k;
		a.pop_back();
		b.pop_front();
	}
	return n;
}

ll maximize_his(deque<char> a, deque<char> b) {
	FOR(k,0,n) {
		auto ita = begin(a), itb = begin(b);
		bool ok = true;
		for (; ita != end(a); ita++, itb++) {
			if (*ita >= *itb) ok = false;
		}
		if (ok) return n-k;
		a.pop_back();
		b.pop_front();
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	string a, b; cin >> a >> b;
	sort(all(a)), sort(all(b));
	
	deque<char> qa(all(a)), qb(all(b));

	cout << minimize_mine(qa,qb) << endl;
	cout << maximize_his(qa,qb) << endl;

}
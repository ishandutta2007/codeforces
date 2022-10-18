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

ll a[500000], b[500000];

void srta(ll i, ll j) {
	if (i+1 == j) return;
	ll k = (i+j)/2;
	srta(i,k), srta(k,j);
	if (lexicographical_compare(a+i,a+k,a+k,a+j)) {
		FOR(h,0,k-i) swap(a[i+h],a[k+h]);
	}
}

void srtb(ll i, ll j) {
	if (i+1 == j) return;
	ll k = (i+j)/2;
	srtb(i,k), srtb(k,j);
	if (lexicographical_compare(b+i,b+k,b+k,b+j)) {
		FOR(h,0,k-i) swap(b[i+h],b[k+h]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string as, bs;

	cin >> as >> bs;
	ll ns = sz(as);

	ll n = 1;
	while (ns % 2 == 0) ns /= 2, n *= 2;
	map<string,ll> id;
	
	ll k = 0;
	FOR(i,0,n) {
		string t = as.substr(i*ns,ns);
		if (!has(id,t)) id[t] = k++;
		a[i] = id[t];
		t = bs.substr(i*ns,ns);
		if (!has(id,t)) id[t] = k++;
		b[i] = id[t];
	}
	
	srta(0,n), srtb(0,n);
		
	FOR(i,0,n) if (a[i] != b[i]) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;

}
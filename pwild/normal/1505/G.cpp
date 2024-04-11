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

vector<string> braille = {
	"#.#.#####.#####..#.#",
	"..#....#.##.#####.##"
};

vvl code(ll k) {
	if (k == 22) return {{0,1},{1,1},{0,1}};
	if (k > 22) k--;
	
	vvl res(3, vl(2));
	FOR(i,0,2) FOR(j,0,2) res[i][j] = braille[i][2*(k%10)+j] == '#';
	res[2][0] = k >= 10;
	res[2][1] = k >= 20;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vvl codes(26);
//	FOR(k,0,26) {
//		vvl a = code(k);
//		FOR(i,0,3) {
//			FOR(j,0,2) cout << ".#"[a[i][j]];
//			cout << endl;
//		}
//		cout << endl;
//	}
	
	ll n; cin >> n;
	while (n--) {
		vl a(3), b(2);
		FOR(i,0,3) cin >> a[i];
		FOR(j,0,2) cin >> b[j];

		bool found = false;
		FOR(k,0,26) {
			vvl c = code(k);
			vl s(3), t(2);
			FOR(i,0,3) FOR(j,0,2) s[i] += c[i][j], t[j] += c[i][j];
			
			if (s == a && t == b) {
				cout << char('a'+k);
				found = true;
				break;
			}
		}
		assert(found);
	}
	cout << endl;
}
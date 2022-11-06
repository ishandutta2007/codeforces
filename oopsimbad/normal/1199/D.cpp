#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
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

const int MAXN = 200005;

int a[MAXN];
bool b[MAXN];
///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	F0R(i, n) cin >> a[i];
	memset(b, 0, sizeof(b));
	int q; cin >> q;
	vector<piii> v;
	F0R(i, q) {
		int A; cin >> A;
		if(A == 1) {
			int B, C; cin >> B >> C;
			v.pb(mp(A, mp(B-1,C)));
		} else {
			int B; cin >> B;
			v.pb(mp(A, mp(B,0)));
		}
	}
	int Max = 0;
	F0Rd(i,q) {
		if(v[i].f == 2) Max = max(v[i].s.f,Max);
		else if(b[v[i].s.f]) continue;
		else {
			a[v[i].s.f] = max(Max,v[i].s.s);
			b[v[i].s.f] = true;
		}
	}
	F0R(i, n) {
		if(!b[i]) a[i] = max(a[i], Max);
		cout << a[i] << " ";
	}
	cout << endl;


///
	int qwertyuiop;
	cin >> qwertyuiop;
	return 0;
}
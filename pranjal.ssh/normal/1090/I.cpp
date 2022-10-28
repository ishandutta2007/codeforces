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
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int N = 1e7 + 1;

int A[N];
ll ans = 5e18;
int main() {
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t-- ){
		int n; cin >> n;
		ll l, r, x, y, z, b1, b2;
		cin >> l >> r >> x >>y >> z >> b1 >> b2;
		r = r - l + 1;
		
		A[0] = b1 % r + l;
		A[1] = b2 % r + l;

		ll SAB = (1LL << 32) - 1;
		ll ans = 5e18;
		FOR (i, 2, n - 1) {
			ll B = (b1 * x + b2 * y + z);
			B &= SAB;
			A[i] = B % r + l;
			b1 = b2, b2 = B;
		}
		int mn = A[0];
		FOR (i, 1, n - 1) {
			if (mn < A[i]) ans = min(ans, A[i]*1LL*mn);
			mn = min(A[i], mn);
		}
		mn = A[n-1];
		NFOR (i, n-2, 0) {
			if (mn > A[i]) ans = min(ans, A[i]*1LL*mn);
			mn = max(A[i], mn);
		}
		if (ans == 5e18) cout << "IMPOSSIBLE\n";
		else cout << ans << '\n';
	}
}
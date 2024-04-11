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

int n, a;
vi c, d;

ll ans;

void solve(int l, int r) {
	if (l > r) return;
	if (l == r) {
		ans = max(ans, c[l] + 0LL);
		return;
	}
	int mid = (l + r) >> 1;

	int j = mid + 1, rmax = 0, lmax = 0;
	ll lsum = 0, rsum = 0;
	ll tot = 0;
	NFOR (i, mid - 1, l) {
		lsum += c[i];
		lmax = max(lmax, d[i + 1] - d[i]);

		while (j <= r and max(rmax, d[j] - d[j - 1]) <= lmax) {
			rmax = max(rmax, d[j] - d[j - 1]);
			tot += c[j];
			rsum = max(rsum, tot);
			++j;
		}
		ans = max(ans, c[mid] + lsum + rsum - lmax * 1LL * lmax);
	}
	tot = rmax = lmax = lsum = rsum = 0;
	j = mid - 1;
	FOR (i, mid + 1, r) {
		rsum += c[i];
		rmax = max(rmax, d[i] - d[i - 1]);

		while (j >= l and max(lmax, d[j + 1] - d[j]) <= rmax) {
			lmax = max(lmax, d[j + 1] - d[j]);
			tot += c[j];
			lsum = max(lsum, tot);
			--j;
		}
		ans = max(ans, c[mid] + lsum + rsum - rmax * 1LL * rmax);
	}

	solve(l, mid);
	solve(mid + 1, r);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> a;
	d.resize(n), c.resize(n);
	FOR (i, 0, n - 1) cin >> d[i] >> c[i], c[i] = a - c[i];
	solve(0, n - 1);
	cout << ans;

	return 0;
}
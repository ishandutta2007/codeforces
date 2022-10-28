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

ll dp[501][501];
int n;
vector<tuple<int, int, int>> A;
ll f(int i, int id) {
	if (i == n) return 0;
	ll &ans = dp[i][id];
	if (~ans) return ans;
	ans = f(i+1, id);
	int a, b, k;
	tie(b, a, k) = A[i];
	ans = max(ans, a - b*1LL*k + f(i+1, id));
	ans = max(ans, a - b*1LL*min(k,id) + f(i+1, id+1));
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	FOR (i, 0, n - 1) {
		int x, y, z; cin >> x >> y >> z;
		A.emplace_back(y, x, z);
	}
	sort(all(A)); reverse(all(A));
	memset(dp, -1, sizeof dp);
	cout << f(0,0) << "\n";

	return 0;
}
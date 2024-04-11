#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e6 + 3;
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


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int c, w, h; cin >> c >> w >> h;
	vi H(w + 1);
	H[0] = 1;
	FOR (i, 1, w) H[i] = (H[i-1]*1LL*h) % inf;
	deque<int> dp;
	dp.push_back(1);
	FOR (i, 1, w) {
		int b = 0;
		FOR (it, 0, i) {
			b = (b + dp[max(0,i-it-1)] * 1LL * H[it])%inf;
		}
		dp.push_back(b);
	}

	if (c <= w) {
		cout << dp[c] << "\n";
		return 0;
	}

	int sum = 0;
	FOR (i, 0, w) sum = (sum + H[w-i]*1LL*dp[i]) % inf;
	
	FOR (i, w+1, c) {
		dp.push_back(sum);
		sum = (sum - dp[0] * 1LL * H[w]) % inf;
		if (sum < 0) sum += inf;
		dp.pop_front();
		sum = (sum * h + dp.back()) % inf;
	}
	cout << dp.back();

	return 0;
}
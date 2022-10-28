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
struct SuffixArray {
  const int L;
  string s;
  vector<vector<int> > P;
  vector<pair<pair<int, int>, int> > M;

  SuffixArray(const string &s) : L(s.length()), s(s), P(1, vector<int>(L, 0)), M(L) {
    for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
      P.push_back(vector<int>(L, 0));
      for (int i = 0; i < L; i++)
        M[i] = make_pair(make_pair(P[level - 1][i], i + skip < L ? P[level - 1][i + skip] : -1000), i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++)
        P[level][M[i].second] = (i > 0 && M[i].first == M[i - 1].first) ? P[level][M[i - 1].second] : i;
    }
  }
  // rank of each suffix
  vector<int> GetSuffixArray() { return P.back(); }
  // sorted order of suffixes
  vector<int> GetInvSuffixArray() { 
    vector<int> ans(sz(P.back()));
    for (int i = 0; i < sz(P.back()); ++i) ans[P.back()[i]] = i;
    return ans;
  }

  // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
  int LongestCommonPrefix(int i, int j) {
    int len = 0;
    if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
      if (P[k][i] == P[k][j]) {
        i += 1 << k;
        j += 1 << k;
        len += 1 << k;
      }
    }
    return len;
  }
};
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t; while (t--) {
		string s; cin >> s;
		SuffixArray SA(s);
		int n = sz(s);
		ll ans = n*(n+1LL)/2;
		vi P(n - 1);
		auto bc = SA.GetInvSuffixArray();
		FOR (i, 1, sz(bc)-1) {
			P[i-1] = SA.LongestCommonPrefix(bc[i-1], bc[i]);
		}

		vi L(n-1, -1), R(n-1, n-1);
		stack<int> st;
		FOR (i, 0, sz(P)-1) {
			while (!st.empty() and P[st.top()] > P[i]) st.pop();
			if (!st.empty()) L[i] = st.top();
			st.push(i);
		}
		while (!st.empty()) st.pop();

		NFOR (i, sz(P)-1, 0) {
			while (!st.empty() and P[st.top()] >= P[i]) st.pop();
			if (!st.empty()) R[i] = st.top();
			st.push(i);
		}
		FOR (i, 0, sz(P) - 1) {
			ans += 2 * P[i] * (R[i] - i) * 1LL * (i - L[i]);
		}
		cout << ans << "\n";
	}	
	
	return 0;
}
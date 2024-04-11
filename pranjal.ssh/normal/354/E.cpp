#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	vi A[43];
	vi ch = {0, 4, 7};
	for (int a : ch) {
		for (int b : ch) {
			for (int c : ch) {
				for (int d : ch) {
					for (int e : ch) {
						for (int f : ch) {
							if (A[a+b+c+d+e+f].empty()) {
								A[a+b+c+d+e+f] = {a, b, c, d, e, f}; 
							}
						}
					}
				}
			}
		}
	}
	vector<pair<int,vi>> B;
	FOR (i, 0, 42) if (!A[i].empty()) B.emplace_back(i, A[i]);

	int t; cin >> t; while (t--) {
		ll n; cin >> n;
		int d[19];
		FOR (i, 0, 18) {
			d[i] = n % 10;
			n /= 10;
		}
		int dp[20][10]; memset(dp, 0, sizeof dp);
		dp[19][0] = 1;
		NFOR (i, 18, 0) {
			for (auto &it : B) {
				int j = (d[i] - it.F + 100) % 10;
				int carry = (j + it.F) / 10;
				dp[i][j] |= dp[i + 1][carry];
			}
		}
		
		if (dp[0][0]) {
			vector<ll> ans(6);
			ll p = 1;
			int j = 0;
			FOR (i, 0, 18) {
				for (auto &it : B) {
					if ((d[i] - it.F + 100) % 10 != j) continue;
					int carry = (j + it.F) / 10;
					if (dp[i + 1][carry]) {
						FOR (k, 0, 5) {
							ans[k] += it.S[k] * p;
						}
						j = carry;
						break;
					}
				}
				p = p * 10;
			}
			FOR (i, 0, 5) cout << ans[i] << " ";
			cout << "\n";
		} else {
			cout << "-1\n";
		}

	}

	return 0;
}
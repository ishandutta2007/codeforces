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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, y1; cin >> n >> y1;
	vi a(n); FOR (i, 0, n - 1) cin >> a[i];

	int m, y2; cin >> m >> y2;
	vi b(m); FOR (i, 0, m - 1) cin >> b[i];

	vector<ll> A(n), B(m);
	int ans = 2;
	FOR (i, 1, 31) {
		FOR (j, 0, m - 1) B[j] = (b[j] + (1LL << (i - 1))) & ((1LL << i) - 1);
		FOR (j, 0, n - 1) A[j] = a[j] & ((1LL << i) - 1);
		sort(all(A)), sort(all(B));
		int j = 0;
		FOR (i, 0, n - 1) {
			int I = i;
			while (I + 1 < n and A[I + 1] == A[i]) ++I;
			while (j < m and B[j] < A[i]) ++j;
			if (j < m and B[j] == A[i]) {
				int J = j;
				while (J + 1 < m and B[J+1] == B[j]) ++J;
				ans = max(ans, I - i + 1 + J - j + 1);
				j = J;
			}
			ans = max(ans, I - i + 1);
			i = I;
		}
		FOR (i, 0, m - 1) {
			int I = i;
			while (I + 1 < m and B[I+1] == B[i]) ++I;
			ans = max(ans, I - i + 1);
			i = I;
		}
	}
	cout << ans;


	return 0;
}
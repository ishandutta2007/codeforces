#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
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
const int N = 4e5;
int sv[N + 1];
int n;

int yo(int x) {
	if (x == 2) return n;
	if (x == n) return 2;
	return x;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	FOR(i, 1, N)sv[i] = i;

	FOR(i, 2, 1000)if (sv[i] == i)for (int j = i * i; j <= N; j += i)sv[j] = i;

	int m; cin >> n >> m;

	vi a(n + 1);
	a[2] = 2;
	FOR (i, 3, n) a[i] = a[i - 1] + 1;

	int sum = n;
	while (sv[sum] != sum) a.back()++, sum++;

	vector<vector<ii>> g(n+1);
	FOR (i, 1, n - 1) g[i].emplace_back(i + 1, a[i + 1] - a[i]);

	m -= n - 1;

	FOR (i, 1, n) {
		FOR (j, i + 2, n) {
			if (!m) break;
			g[i].emplace_back(j, a[j] - a[i] + 1);
			--m;
		}
	}

	cout << 2 << " " << sum << "\n";
	FOR (i, 1, n) {
		for (auto x : g[i]) cout << yo(i) << " " << yo(x.F) << " " << x.S << "\n";
	}

	return 0;
}
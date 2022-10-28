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

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vi(m));
	FOR (i, 0, n - 1) {
		string s; cin >> s;
		FOR (j, 0, m - 1) a[i][j] = s[j] - 'a';
	}
	sort(all(a));
	int inv[5] = {0, 1, 3, 2, 4};
	FOR (i, 1, n - 1) {
		FOR (j, 0, i-1) {
			int first = 0;
			while (first < m && a[j][first] == 0) ++first;
			if (first == m) continue;
			int count = (((5-a[i][first])%5)*inv[a[j][first]])%5;
			FOR (k, 0, m - 1) (a[i][k] += count*a[j][k]) %= 5;
		}
	}
	int ans = 1;
	FOR (i, 0, n - 1) {
		int cnt = 0;
		FOR (j, 0, m - 1) cnt += !a[i][j];
		if (cnt == m) ans = (ans*5LL) % inf;
	}

	int q; cin >> q;

	while (q--) {
		string s;cin>>s;
		vector<int> b(m);
		FOR (j, 0, m - 1) b[j] = s[j] - 'a';
		FOR (j, 0, n-1) {
			int first = 0;
			while (first < m && a[j][first] == 0) ++first;
			if (first == m) continue;
			int count = (((5-b[first])%5)*inv[a[j][first]])%5;
			FOR (k, 0, m - 1) (b[k] += count*a[j][k]) %= 5;
		}
		int count = 0;
		FOR (i, 0, m - 1) count += !b[i];
		cout << (count == m ? ans : 0) << "\n";
	}

	return 0;
}
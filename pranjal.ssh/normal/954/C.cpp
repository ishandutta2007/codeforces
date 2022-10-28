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

	int n; cin >> n;
	vi a(n); FOR (i, 0, n - 1) cin >> a[i];
	set<int> s;
	FOR (i, 1, n - 1) {
		s.insert(abs(a[i] - a[i - 1]));
	}
	if (s.count(0)) {
		cout << "NO\n";
	} else if (sz(s) == 0) {
		cout << "YES\n1000000000 1000000000\n";
	} else if (sz(s) == 1) {
		cout << "YES\n";
		cout << "1000000000 " << *s.begin() << "\n";
	} else if (s.count(1) and sz(s) == 2) {
		s.erase(s.find(1));
		bool can = true;
		int y = *s.begin();
		FOR (i, 1, n - 1) {
			if (a[i - 1] + 1 == a[i]) {
				can &= (a[i] % y != 1);
			}
			if (a[i - 1] == a[i] + 1) {
				can &= (a[i - 1] % y != 1);
			}
		}
		if (can) cout << "YES\n1000000000 " << y << "\n";
		else cout << "NO\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}
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

#define NO return cout << "NO\n", 0

int main()
{
   ios::sync_with_stdio(0); cin.tie(0);

 	int n; cin >> n;
 	vi f(n + 1);
 	FOR (i, 1, n - 1) {
 		int x, y; cin >> x >> y;
 		if (x > y) swap(x, y);
 		if (y != n) NO;
 		f[x]++;
 	}
 	if (f[n]) NO;
 	set<int> st;
 	FOR (i, 1, n - 1) if (!f[i]) st.insert(i);
 	vector<ii> ans;
 	NFOR (i, n - 1, 1) {
 		if (!f[i]) {
 			if (st.count(i)) NO;
 			continue;
 		}
 		f[i] -= 1;
 		int cur = n;
 		while (f[i]--) {
 			if (st.empty()) NO;
 			ans.emplace_back(cur, *st.rbegin());
 			cur = *st.rbegin();
 			st.erase(*st.rbegin());
 		}
 		ans.emplace_back(cur, i);
 	}
 	cout << "YES\n";
 	for (ii i : ans) {
 		cout << i.F << " " << i.S << "\n";
 	}

   return 0;
}
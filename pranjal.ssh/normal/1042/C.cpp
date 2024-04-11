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


void solve(vi f) {
	int cur = 0, n = sz(f);
	FOR (i, 0, n - 1) if (!f[i]) cur = i;
	FOR (i, 0, n - 1) if (!f[i] and i != cur) {
		cout << "1 " << i + 1 << " " << cur + 1 << "\n";
	}
}

int main()
{
   ios::sync_with_stdio(0); cin.tie(0);

 	vi pos, neg, z;
 	int n; cin >> n;
 	vi a(n);
 	FOR (i, 0, n - 1) {
 		cin >> a[i];
 		if (a[i] > 0) pos.push_back(i);
 		else if (a[i] < 0) neg.push_back(i);
 		else z.push_back(i);
 	}
 	vi f(n);
 	if (sz(z) >= 1) {
 		int bc = 0;
 		FOR (i, 1, sz(z) - 1) {
 			f[z[i]] = 1;
 			cout << "1 " << z[i] + 1 << " " << z[0] + 1 << "\n";
 			++bc;
 		}
 		if (sz(neg) % 2 == 1) {
 			int pos = neg[0];
 			FOR (i, 0, sz(neg) - 1) {
 				if (a[neg[i]] > a[pos]) pos = neg[i];
 			}
 			f[pos] = 1;
 			cout << "1 " << pos + 1 << " " << z[0] + 1 << "\n";
 			++bc;
 		}
 		if (bc != n - 1) {
 			f[z[0]] = 1;
 			cout << "2 " << z[0] + 1 << "\n";
 		}
 		solve(f);
 	} else {
 		if (sz(neg) % 2 == 1) {
 			int pos = neg[0];
 			FOR (i, 0, sz(neg) - 1) {
 				if (a[neg[i]] > a[pos]) pos = neg[i];
 			}
 			f[pos] = 1;
 			cout << "2 " << pos + 1 << "\n";
 		}
 		solve(f);
 	}

   return 0;
}
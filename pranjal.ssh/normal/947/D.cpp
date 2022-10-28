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

	vi s, t;
	string S, T; cin >> S >> T;
	s.push_back(0), t.push_back(0);
	for (char ch: S) {
		s.push_back(ch != 'A');
	}
	for (char ch: T) {
		t.push_back(ch != 'A');
	}
	int n = sz(S), m = sz(T);

	vi ps(s), pt(t);
	FOR (i, 1, n) ps[i] += ps[i - 1];
	FOR (i, 1, m) pt[i] += pt[i - 1];
	vi ls(n+1), lt(m+1);

	FOR (i, 1, n) {
		ls[i] = s[i] ? 0 : (1 + ls[i - 1]);
	}

	FOR (i, 1, m) {
		lt[i] = t[i] ? 0 : (1 + lt[i - 1]);
	}

	int q; cin >> q; while (q--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int os = ps[b] - ps[a - 1];
		int ot = pt[d] - pt[c - 1];
		int zs = min(b-a+1, ls[b]), zt = min(d-c+1, lt[d]);
		bool c1 = true;
		c1 &= (ot >= os and (ot - os) % 2 == 0);
		c1 &= zs >= zt;
		zs -= zt;
		if (os == 0) {
			if (ot == 0) {
				c1 &= (zs % 3 == 0);
			} else {
				if (zs == 0) c1 = false;
				else {
					os += 2, zs -= 1;
					c1 &= (ot >= os and (ot - os) % 2 == 0);
				}
			}
		} else {
			os += min(1, zs % 3) * 2;
			c1 &= (ot >= os and (ot - os) % 2 == 0);
		}
		cout << c1;
	}

	return 0;
}
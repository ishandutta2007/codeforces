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


int common(ii it1, ii it2) {
	int poss = 0;
	if ((it1.F == it2.S) + (it1.F == it2.F) + (it1.S == it2.F) + (it1.S == it2.S) == 1) {
		vi x = {it1.F, it1.S, it2.F, it2.S}; sort(all(x));
		FOR (i, 1, 3) if (x[i] == x[i - 1]) poss = x[i];
	}
	return poss;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	set<ii> s1, s2;
	FOR (i, 0, n - 1) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		s1.insert(ii(a, b));
	}

	FOR (i, 0, m - 1) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		s2.insert(ii(a, b));
	}

	set<int> yo;
	for (auto it1 : s1) {
		int poss = 0;
		for (auto it2 : s2) {
			poss = common(it1, it2);
			if (poss) yo.insert(poss);
		}
		
	}
	if (sz(yo) == 1) {
		cout << *yo.begin() << "\n";
	} else {
		bool ok = 1;
		for (auto it1 : s1) {
			for (auto it2 : s2) {
				int c = common(it1, it2);
				if (c) {

					set<int> S1, S2;
					for (auto it : s2) {
						int C = common(it1, it);
						if (C) S1.insert(C);
					}

					for (auto it : s1) {
						int C = common(it, it2);
						if (C) S2.insert(C);
					}
					ok &= (sz(S1) == 1 and sz(S2) == 1);
				}
			}
		}
		cout << (ok ? "0" : "-1");
	}

	return 0;
}
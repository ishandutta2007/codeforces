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
typedef long double DT;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, T; cin >> n >> T;
	vi a(n), t(n);
	FOR (i, 0, n - 1) cin >> a[i];
	vi pos, neg;
	DT POS = 0, NEG = 0, ZER = 0;
	FOR (i, 0, n - 1) {
		cin >> t[i];
		if (t[i] - T == 0) {
			ZER += a[i];
		} else if (t[i] - T > 0) {
			pos.push_back(i);
			POS += a[i] * (t[i] - T + .0L);
		} else {
			neg.push_back(i);
			NEG += a[i] * (T - t[i] + .0L);
		}
		t[i] -= T;
	}
	if ((pos.empty() ^ neg.empty()) and ZER == 0) {
		cout << "0\n";
		return 0;
	}
	if (POS > NEG) {
		swap(POS, NEG), swap(pos, neg);
	}
	for (int i : pos) ZER += a[i];
	sort(all(neg), [&](int x, int y) {
		return abs(t[x]) > abs(t[y]);
	});
	POS = NEG - POS;
	for (int i : neg) {
		DT can = min(POS, a[i] * 1.0L * abs(t[i]));
		POS -= can;
		ZER += a[i] - can / abs(t[i]);
	}
	cout << fixed << setprecision(10) << ZER << "\n";
	

	return 0;
}
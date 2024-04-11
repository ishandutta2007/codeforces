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

ii intersect(ii a, ii b) {
	if (a > b) swap(a, b);
	if (b.F > a.S) return {inf, inf};
	return {ii(b.F, min(a.S, b.S))};
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<pair<ii, ii>> a(n);
	FOR (i, 0, n - 1) {
		cin >> a[i].F.F >> a[i].F.S >> a[i].S.F >> a[i].S.S;
	}
	vector<ii> X(n), Y(n);
	X[n-1] = ii(a[n-1].F.F, a[n-1].S.F);
	Y[n-1] = ii(a[n-1].F.S, a[n-1].S.S);
	NFOR (i, n-2, 0) {
		X[i] = intersect(X[i + 1], ii(a[i].F.F, a[i].S.F));
		Y[i] = intersect(Y[i + 1], ii(a[i].F.S, a[i].S.S));
	}

	vector<ii> XX(n), YY(n);
	XX[0] = ii(a[0].F.F, a[0].S.F);
	YY[0] = ii(a[0].F.S, a[0].S.S);
	FOR (i, 1, n-1) {
		XX[i] = intersect(XX[i - 1], ii(a[i].F.F, a[i].S.F));
		YY[i] = intersect(YY[i - 1], ii(a[i].F.S, a[i].S.S));
	}
	if (X[1].F != inf and Y[1].F != inf) {
		cout << X[1].F << " " << Y[1].F << "\n";
		return 0;
	}
	if (XX[n-2].F != inf and YY[n-2].F != inf) {
		cout << XX[n-2].F << " " << YY[n-2].F << "\n";
		return 0;
	}
	FOR (i, 1, n - 2) {
		ii XXX = intersect(XX[i-1], X[i+1]);
		ii YYY = intersect(YY[i-1],Y[i+1]);
		if (XXX.F != inf and YYY.F != inf) {
			cout << XXX.F << " " << YYY.F << "\n";
			return 0;
		}
	}
	

	return 0;
}
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

	vi A{1}, B{0};

	int n; cin >> n;
	while (n--) {
		vi NA=A, NB=A;
		NA.emplace_back();
		NFOR (i, sz(NA)-1, 1) NA[i] = NA[i-1];
		NA[0] = 0;
		int sign = 1;
		FOR (i, 0, sz(B)-1) {
			if (abs(NA[i]+B[i]) == 2) sign = -1;
		}
		FOR (i, 0, sz(B)-1) {
			NA[i] += B[i]*sign;
			assert(abs(NA[i]) <= 1);
		}
		A.swap(NA), B.swap(NB);
	}
	for (auto it : {A, B}) {
		cout << sz(it) - 1 << "\n";
		for (int x : it) cout << x << " ";
		cout << "\n";
	}

	return 0;
}
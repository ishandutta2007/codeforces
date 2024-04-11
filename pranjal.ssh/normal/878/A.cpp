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

	vi a(10), f(10);
	int n; cin >> n; while (n--) {
		char ch; int y; cin >> ch >> y;
		if (ch == '^') {
			FOR (i, 0, 9) if (y&(1<<i)) a[i] *= -1, f[i] ^= 1;
		} else if (ch == '&') {
			FOR (i, 0, 9) if (!(y&(1<<i))) a[i] = -1;
		} else {
			FOR (i, 0, 9) if (y&(1<<i)) a[i] = 1;
		}
	}
	cout << "3\n";
	int x = 0; FOR (i, 0, 9) if (a[i] != -1) x |= (1 << i);
	cout << "& " << x << "\n";
	x = 0; FOR (i, 0, 9) if (a[i] == 1) x |= (1 << i);
	cout << "| " << x << "\n";
	x = 0; FOR (i, 0, 9) if (a[i] == 0 and f[i]) x ^= (1 << i);
	cout << "^ " << x << "\n";

	return 0;
}
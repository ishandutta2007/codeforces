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

const int mod = 998244353;

int C[5001][5001];

ll f(int a, int b) {
	if (a > b) swap(a, b);
	ll ans = 0;
	ll fac = 1;
	FOR (i, 0, a) {
		ans += ((C[a][i] * 1LL * C[b][i]) % mod) * 1LL * fac;
		ans %= mod;
		fac = (fac * (i + 1)) % mod;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	FOR (i, 0, 5000) {
		C[i][0] = 1;
		FOR (j, 1, i) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			if (C[i][j] >= mod) C[i][j] -= mod;
		}
	}

	int a, b, c; cin >> a >> b >> c;
	ll ans = 1;
	ans *= f(a, b), ans %= mod;
	ans *= f(c, b), ans %= mod;
	ans *= f(a, c), ans %= mod;
	cout << ans;

	return 0;
}
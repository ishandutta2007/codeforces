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
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

const int N = 1e7;
int f[N + 1];
int sv[N + 1];
int no[N + 1];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, l, r; cin >> n >> l >> r;
	if (n == 1) {
		cout << r-l+1 << "\n";
		return 0;
	}
	if (n == 2) {
		cout << (r-l+1LL)*(r-l) << "\n";
		return 0;	
	}
	--n;

	FOR (i, 2, 10000) if (sv[i] == 0)
		for (int j = i*i; j <= N; j += i)
			sv[j] = i;

	no[1] = 1;
	FOR (i, 2, N) {
		int x = sv[i];
		if (x == 0) {
			no[i] = i;
			continue;
		}
		int j = i; int pw = 0;
		while (j % x == 0) j /= x, pw++;
		pw %= n;
		no[i] = no[j];
		FOR (it, 1, pw) no[i] *= x;
	}
	FOR (i, l, r) f[no[i]]++;
	ll ans = 0;
	FOR (i, 1, N) {
		ans += f[i] * (f[i] - 1LL);
	}
	cout << ans << "\n";

	return 0;
}
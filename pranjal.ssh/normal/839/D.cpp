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

const int N = 1e6;
int sum[N+1], p2[N+1];
int f[N+1], m[N+1];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vi a(n); FOR (i, 0, n-1) cin >> a[i], f[a[i]]++;

	NFOR (i, N, 1) {
		for (int j = i; j <= N; j += i) {
			m[i] += f[j];
		}
	}
	p2[0] = 1;
	FOR (i, 1, N) {p2[i] = p2[i-1] + p2[i-1]; if (p2[i] >= inf) p2[i] -= inf;}
	int ans = 0;
	NFOR (g, N, 2) {
		sum[g] = (p2[m[g]-1]*1LL*m[g])%inf;
		for (int i = g+g; i <= N; i += g) {
			sum[g] -= sum[i];
			if (sum[g] < 0) sum[g] += inf;
		}
		
		ans += (sum[g]*1LL*g) % inf;
		if (ans >= inf) ans -= inf;
	}
	cout << ans;

	return 0;
}
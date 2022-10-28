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
int p[10][N+1];
int g[N+1], f[N+1];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	FOR (i, 1, 9) f[i] = g[i] = i;
	FOR (i, 10, N) {
		f[i] = f[i/10];
		if (i % 10) f[i] *= (i % 10);
		g[i] = g[f[i]];
	}

	FOR (i, 1, N) {
		p[g[i]][i]++;
	}
	FOR (i, 1, 9) FOR (j, 1, N) p[i][j] += p[i][j-1];

	int q; cin >> q; while (q--) {
		int l, r, k; cin >> l >>r >> k;
		cout << p[k][r]-p[k][l-1] << "\n";
	}
	return 0;
}
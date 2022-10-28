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


int a[111][111];
int p[15][111][111];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q, c; cin >> n >> q >> c;
	vi x(n), y(n), s(n);
	FOR (i, 0, n - 1) cin >> x[i] >> y[i] >> s[i], a[x[i]][y[i]] += s[i];


	FOR (i, 0, 12) {
		if (i) {
			FOR (it, 0, n-1) {
				if (s[it] == c) {
					a[x[it]][y[it]] -= c;
					s[it] = 0;
				} else {
					a[x[it]][y[it]]++;
					s[it]++;
				}
			}
		}
		FOR (j, 1, 100) {
			FOR (k, 1, 100) {
				p[i][j][k] = a[j][k] + p[i][j-1][k] + p[i][j][k-1] - p[i][j-1][k-1];
			}
		}
		
	}

	while (q--) {
		int t, x1, y1, x2, y2; cin >> t >> x1 >> y1 >> x2 >> y2;
		t %= c+1;
		cout << p[t][x2][y2] - p[t][x2][y1-1] - p[t][x1-1][y2] + p[t][x1-1][y1-1] << "\n";
	}


	return 0;
}
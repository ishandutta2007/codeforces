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



int f[26][5000][26];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;
	int n = s.length();
	FOR (i, 0, n - 1) {
		FOR (j, 1, n - 1) {
			f[s[i] - 'a'][j][s[(i + j) % n ] - 'a']++;
		}
	}

	double p = 0;
	FOR (i, 0, 25) {
		double yo = 0;
		int cnt = count(all(s), i + 'a');
		if (!cnt) continue;
		FOR (j, 1, n - 1) {
			double mx = 0;
			int sum = accumulate(f[i][j], f[i][j]+26, 0);
			FOR (k, 0, 25) if (f[i][j][k] == 1) mx += 1.0/sum;
			yo = max(yo, mx);
		}
		p += (yo * cnt) / n;
	}
	cout << fixed << setprecision(10) << p << "\n";

	return 0;
}
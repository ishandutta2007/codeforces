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

const int N = 1e5;
bitset<4096> pre[N + 20];
int a[N][12];
int t[N], x[N], y[N];
vector<ii> qry;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k, q; cin >> n >> k >> q;
	FOR (i, 0, k - 1) {
		FOR (j, 0, n - 1) {
			cin >> a[j][i];
		}
	}
	FOR (i, 0, q - 1) {
		cin >> t[i] >> x[i] >> y[i];
		--x[i], --y[i];
	}
	FOR (i, 0, (1 << k) - 1) {
		FOR (j, 0, k - 1) pre[j][i] = ((i >> j) & 1);
	}
	int no = k;
	FOR (j, 0, q - 1) {
		if (t[j] == 1) {
			pre[no++] = (pre[x[j]] | pre[y[j]]);
		} else if (t[j] == 2) {
			pre[no++] = (pre[x[j]] & pre[y[j]]);
		}
	}
	
	
	FOR (i, 0, q - 1) {
		if (t[i] == 3) {
			vector<ii> val(k);
			FOR (j, 0, k - 1) val[j] = {a[y[i]][j], j};
			sort(all(val)); reverse(all(val));
			int mask = 0;
			FOR (j, 0, k - 1) {
				mask |= (1 << (val[j].S));
				if (pre[x[i]][mask]) {
					cout << val[j].F << "\n";
					break;
				}
			}
		}
	}

	return 0;
}
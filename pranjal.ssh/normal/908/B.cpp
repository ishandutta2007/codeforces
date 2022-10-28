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


char a[55][55];
vi p;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n,m; cin >> n >> m;
	FOR (i,0,n+1) FOR(j,0,m+1) a[i][j]='#';
	FOR(i,1,n) FOR(j,1,m) cin >> a[i][j];

	p=vi(4); iota(all(p), 0);
	int ans=0;
	string s; cin >> s;

	do {
		FOR (i,1,n) FOR(j,1,m) if(a[i][j]=='S'){
			int x = i, y = j;
			int ok = 1;
			for (char t : s) {
				x += dx[p[t-'0']];
				y += dy[p[t-'0']];
				if (a[x][y] == '#') {ok=0;break;}
				if (a[x][y] == 'E') break;
			}
			ans += ok and (a[x][y] == 'E');
		}
	}while (next_permutation(all(p)));
	cout << ans << "\n";

	return 0;
}
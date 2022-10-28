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
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]\n";}

const int N = 2e5+10;
vi g[N];
ll fdwn[5][N];
ll dwn[5][N];
ll up[5][N];
ll fup[5][N];
int n, k;
void dfs(int i, int p) {
	for (int it : g[i]) {
		if (it == p) continue;
		dfs(it, i);
		FOR (j, 0, k-1) {
			dwn[(j+1)%k][i] += dwn[j][it] + fdwn[j][it];
			fdwn[(j+1)%k][i] += fdwn[j][it];
		}
		dwn[1%k][i]++;
		fdwn[1%k][i]++;
	}
}
void ddfs(int i, int p) {
	if (p != -1) {
		FOR (j, 0, k-1){
			up[(j+1)%k][i] += dwn[j][p] + fdwn[j][p] + up[j][p] + fup[j][p];
			up[(j+2)%k][i] -= dwn[j][i] + 2*fdwn[j][i];
			fup[(j+1)%k][i] += fdwn[j][p] + fup[j][p];
			fup[(j+2)%k][i] -= fdwn[j][i];
		}
		up[1%k][i]++;
		fup[1%k][i]++;
		up[2%k][i]-=2;
		fup[2%k][i]--;
	}
	for (int it : g[i]) {
		if (it == p) continue;
		ddfs(it, i);
	}	
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	FOR (i, 1, n-1) {
		int x, y; cin >> x >> y;
		--x, --y;
		g[x].push_back(y), g[y].push_back(x);
	}

	dfs(0,-1);
	ddfs(0,-1);
	// FOR (i, 0, k-1) {
	// 	FOR (j, 0, n - 1) 
	// 	cout << fdwn[i][j] <<" ";
	// 	cout<<"\n";
	// }
	// FOR (i, 0, k-1) {
	// 	FOR (j, 0, n - 1) 
	// 	cout << fup[i][j] <<" ";
	// 	cout<<"\n";
	// }
	ll ans = 0;
	FOR (i, 0, k-1) {
		ll now = 0;
		FOR(j,0,n-1) now += dwn[i][j]+up[i][j]+(i?k-i:0)*(fdwn[i][j]+fup[i][j]);
		now /= k;

		ans += now;
	}
	cout << ans/2 << "\n";


	return 0;
}
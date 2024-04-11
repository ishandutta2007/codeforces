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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}

int n, m;
int x[55], y[55];
int fx[55], fy[55];
int fr[55];
int at[55][55];
vector<pair<ii, ii>> ans;

int vis[55][55];
ii par[55][55];

ii reach(int i, int j, ii dest = ii(0, 0)) {
	queue<ii> q;
	q.push(ii(i, j));
	ii lmao;
	par[i][j] = ii(i, j);
	vis[i][j] = 1;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		int i = t.F, j = t.S;
		if ((dest.F == 0 and at[i][j]) or ii(i, j) == dest) {
			lmao = ii(i, j);
			break;
		}
		FOR (di, -1, 1) {
			FOR (dj, -1, 1) {
				if (abs(di) + abs(dj) == 1 and i + di >= 1 and i + di <= n and j + dj >= 1 and j + dj <= n and !vis[i + di][j + dj]) {
					q.push(ii(i+di, j+dj));
					vis[i+di][j+dj] = 1;
					par[i+di][j+dj] = ii(i, j);
				}
			}
		}
	}
	ii ret = lmao;
	assert(lmao.F > 0);
	while (par[lmao.F][lmao.S] != lmao) {
		ans.emplace_back(lmao, par[lmao.F][lmao.S]);
		lmao = par[lmao.F][lmao.S];
	}
	return ret;
}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	FOR (i, 1, m) cin >> x[i] >> y[i], at[x[i]][y[i]] = i;
	FOR (i, 1, m) cin >> fx[i] >> fy[i], fr[fx[i]]++;

	int r = min_element(fr+1, fr+1+n) - fr;

	FOR (i, 1, m) {
		if (at[r][i]) continue;
		memset(vis, 0, sizeof vis);
		FOR (it, 1, i - 1) vis[r][it] = 1;
		memset(par, 0, sizeof par);
		ii yo = reach(r, i);
		int ind = at[yo.F][yo.S];
		x[ind] = r, y[ind] = i;
		at[yo.F][yo.S] = 0;
		at[r][i] = ind;
	}

	vi ind(m); iota(all(ind), 1);
	sort(all(ind), [&](int i, int j) {
		return fx[i] == fx[j] ? fy[i] < fy[j] : abs(r - fx[i]) > abs(r - fx[j]);
	});
	

	FOR (it, 1, m) {
		int i = ind[it - 1];
		memset(vis, 0, sizeof vis);
		memset(par, 0, sizeof par);
		FOR (j, 1, m) if (i != j) vis[x[j]][y[j]] = 1;
		
		ii yo = reach(fx[i], fy[i], ii(x[i], y[i]));
		assert(yo == ii(x[i], y[i]));
		int index = at[yo.F][yo.S];
		at[yo.F][yo.S] = 0;
		x[i] = fx[i], y[i] = fy[i];
		at[fx[i]][fy[i]] = index;
	}
	
	assert(sz(ans) <= 10800);
	cout << sz(ans) << "\n";
	for (auto it : ans) {
		cout << it.F.F << " " << it.F.S << " " << it.S.F << " " << it.S.S << "\n";
	}


	return 0;
}
//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 55;
int com[maxn][maxn],
	comcnt,
	n, m, k;
string s[maxn];
int dx[4] = {-1, -0, +0, +1},
	dy[4] = {-0, -1, +1, +0};
vector<pair<int, pii> > vec;
bool fil[maxn * maxn];

bool cango(int i, int j){
	return i >= 0 and i < n
		and j >= 0 and j < m
		and s[i][j] != '*'
		and com[i][j] == -1;
}

int dfs(int ui, int uj){
	com[ui][uj] = comcnt;
	int ret = 1;
	for(int i = 0; i < 4; i++){
		int vi = ui + dx[i],
			vj = uj + dy[i];
		if(cango(vi, vj))
			ret += dfs(vi, vj);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(com, -1, sizeof com);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < n; i++){
		if(cango(i, 0))
			dfs(i, 0);
		if(cango(i, m - 1))
			dfs(i, m - 1);
	}
	for(int j = 0; j < m; j++){
		if(cango(0, j))
			dfs(0, j);
		if(cango(n - 1, j))
			dfs(n - 1, j);
	}
	comcnt = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(cango(i, j))
				vec.PB(MP(dfs(i, j), MP(i, j))), comcnt++;
	sort(all(vec));
	int ans = 0;
	for(int i = 0; i < sz(vec) - k; i++)
		fil[com[vec[i].R.L][vec[i].R.R]] = true, ans += vec[i].L;
	cout << ans << '\n';
	for(int i = 0; i < n; i++, cout << '\n')
		for(int j = 0; j < m; j++)
			if(~com[i][j] and fil[com[i][j]])
				cout << '*';
			else
				cout << s[i][j];
	return 0;
}
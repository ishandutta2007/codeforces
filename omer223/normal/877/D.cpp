#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <unordered_set>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef long double ld;
typedef pair <ld, ld> pld;

const int sz = 1e3 + 1, inf = 1e9;
int n, m, k, xs, ys, xf, yf;
char board[sz][sz];
bool vis[sz][sz];
int dist[sz][sz], dirs[][2]{ {0,1},{0,-1},{1,0},{-1,0} };
int nxtDir[sz][sz][4], cnts[sz][sz];//RULD
ll iters = 0;


void nextUpdate(int a, int b) {
	if (nxtDir[a][b][0] != -1) nxtDir[a][nxtDir[a][b][0]][2] = nxtDir[a][b][2];
	if (nxtDir[a][b][2] != -1) nxtDir[a][nxtDir[a][b][2]][0] = nxtDir[a][b][0];
	if (nxtDir[a][b][1] != -1) nxtDir[nxtDir[a][b][1]][b][3] = nxtDir[a][b][3];
	if (nxtDir[a][b][3] != -1) nxtDir[nxtDir[a][b][3]][b][1] = nxtDir[a][b][1];
}

void bfs() {
	queue<pii> q, toUpdate;
	q.push({ xs,ys });
	vis[xs][ys] = 1;
	vector<int> roww, coll;
	while (!q.empty()) {
		pii p = q.front(); q.pop();
		int myRow = p.first, myCol = p.second, cr;
		cnts[myRow][myCol]++;
		cr = nxtDir[myRow][myCol][0];
		roww.clear();
		coll.clear();
		roww.pb(myCol);
		coll.pb(myRow);
		while (abs(cr - myCol) <= k && cr >= 0 && cr < m) {
			if (board[myRow][cr] == '#')break;
			if (!vis[myRow][cr]) {
				dist[myRow][cr] = dist[myRow][myCol] + 1;
				q.push({ myRow,cr });
				vis[myRow][cr] = 1;
				toUpdate.push({ myRow, cr });
				roww.pb(cr);
			}
			cr = nxtDir[myRow][cr][0];
		}
		cr = nxtDir[myRow][myCol][2];
		while (abs(cr - myCol) <= k && cr >= 0 && cr < m) {
			if (board[myRow][cr] == '#')break;
			if (!vis[myRow][cr]) {
				dist[myRow][cr] = dist[myRow][myCol] + 1;
				q.push({ myRow,cr });
				vis[myRow][cr] = 1;
				toUpdate.push({ myRow, cr });
				roww.pb(cr);
			}
			cr = nxtDir[myRow][cr][2];
		}
		cr = nxtDir[myRow][myCol][1];
		while (abs(cr - myRow) <= k && cr >= 0 && cr < n) {
			if (board[cr][myCol] == '#')break;
			if (!vis[cr][myCol]) {
				dist[cr][myCol] = dist[myRow][myCol] + 1;
				q.push({ cr,myCol });
				vis[cr][myCol] = 1;
				toUpdate.push({ cr,myCol });
				coll.pb(cr);
			}
			cr = nxtDir[cr][myCol][1];
		}
		cr = nxtDir[myRow][myCol][3];
		while (abs(cr - myRow) <= k && cr >= 0 && cr < n) {
			if (board[cr][myCol] == '#')break;
			if (!vis[cr][myCol]) {
				dist[cr][myCol] = dist[myRow][myCol] + 1;
				q.push({ cr,myCol });
				vis[cr][myCol] = 1;
				toUpdate.push({ cr,myCol });
				coll.pb(cr);
			}
			cr = nxtDir[cr][myCol][3];
		}
		int mxr = *max_element(roww.begin(),roww.end()), mnr = *min_element(roww.begin(),roww.end()),
			mxc = *max_element(coll.begin(),coll.end()), mnc = *min_element(coll.begin(),coll.end());
		for (int ty : roww) {
			nxtDir[myRow][ty][0] = nxtDir[myRow][mxr][0];
			nxtDir[myRow][ty][2] = nxtDir[myRow][mnr][2];
		}
		for (int tx : coll) {
			nxtDir[tx][myCol][1] = nxtDir[mnc][myCol][1];
			nxtDir[tx][myCol][3] = nxtDir[mxc][myCol][3];
		}
		while (!toUpdate.empty()) {
			pii tx = toUpdate.front(); toUpdate.pop();
			nextUpdate(tx.first, tx.second);
		}
	}
}

int main() {
	fast;
	//freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	foru(i, 0, n) {
		string s;
		cin >> s;
		foru(j, 0, m) {
			board[i][j] = s[j]; dist[i][j] = inf;
			nxtDir[i][j][0] = (j != m - 1 ? j + 1 : -1);
			nxtDir[i][j][1] = (i != 0 ? i - 1 : -1);
			nxtDir[i][j][2] = (j != 0 ? j - 1 : -1);
			nxtDir[i][j][3] = (i != n - 1 ? i + 1 : -1);
		}
	}
	cin >> xs >> ys >> xf >> yf; xs--; ys--; xf--; yf--;
	k = min(k, max(n, m));
	dist[xs][ys] = 0;
	bfs();
	if (dist[xf][yf] >= inf)cout << -1 << '\n';
	else cout << dist[xf][yf] << '\n';
	return 0;
}
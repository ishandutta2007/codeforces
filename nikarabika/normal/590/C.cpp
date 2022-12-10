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

const int maxn = 1000;
int dx[4] = {-1, 0, 0, +1};
int dy[4] = {0, -1, +1, 0};
LL dis[3][maxn][maxn];
char a[maxn][maxn];
int n, m;
bool mark[maxn][maxn];
deque<pii> Q;

bool isvalid(pii v){
	return v.L >= 0 and v.L < n and v.R >= 0 and v.R < m and a[v.L][v.R] != '#';
}

void bfs(pii sc, int id){
	memset(mark, false, sizeof mark);
	Q.push_back(sc);
	dis[id][sc.L][sc.R] = 0;
	while(sz(Q)){
		pii v = Q.front();
		Q.pop_front();
		for(int i = 0; i < 4; i++){
			pii u = MP(v.L + dx[i], v.R + dy[i]);
			if(isvalid(u) and !mark[u.L][u.R]){
				dis[id][u.L][u.R] = dis[id][v.L][v.R];
				mark[u.L][u.R] = true;
				if(a[u.L][u.R] == '.')
					Q.push_back(u), dis[id][u.L][u.R]++;
				else
					Q.push_front(u);
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	pii yek, dow, seh;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			switch(a[i][j]){
				case '1':
					yek = MP(i, j);
					break;
				case '2':
					dow = MP(i, j);
					break;
				case '3':
					seh = MP(i, j);
					break;
			}
		}
	}
	memset(dis, 1, sizeof dis);
	bfs(yek, 0);
	bfs(dow, 1);
	bfs(seh, 2);
	LL ans = 10000000;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			smin(ans, dis[0][i][j] + dis[1][i][j] + dis[2][i][j] - 2LL * (a[i][j] == '.'));
	cout << (ans == 10000000 ? -1 : ans) << endl;
	return 0;
}
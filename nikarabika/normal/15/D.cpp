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

const int maxn = 1000 + 10;
LL grd[maxn][maxn], minrow[maxn][maxn], minall[maxn][maxn], sum[maxn][maxn], cost[maxn][maxn];
bool mark[maxn][maxn];
LL n, m, a, b;
vector<pii> cells;
vector<int> ans;

inline LL SUM(int i, int j, int ii, int jj){return sum[ii][jj] - sum[ii][j] - sum[i][jj] + sum[i][j];};

bool cmp(pii i, pii j){
	int x = i.L, y = i.R;
	int xx = j.L, yy = j.R;
	if(cost[x][y] != cost[xx][yy])
		return cost[x][y] < cost[xx][yy];
	if(x != xx)
		return x < xx;
	return y < yy;
}

int main(){
	scanf("%I64d%I64d%I64d%I64d", &n, &m, &a, &b);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			scanf("%I64d", grd[i] + j);
			sum[i + 1][j + 1] = grd[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
		}
	for(int i = 0; i < n; i++){
		deque<int> deq;
		for(int j = 0; j < m; j++){
			while(sz(deq) and grd[i][deq.front()] > grd[i][j])
				deq.pop_front();
			deq.push_front(j);
			if(deq.back() <= j - b)
				deq.pop_back();
			if(j - b + 1 >= 0) minrow[i][j - b + 1] = grd[i][deq.back()];
		}
	}
	for(int j = 0; j <= m - b; j++){
		deque<int> deq;
		for(int i = 0; i < n; i++){
			while(sz(deq) and minrow[deq.front()][j] > minrow[i][j])
				deq.pop_front();
			deq.push_front(i);
			if(deq.back() <= i - a)
				deq.pop_back();
			if(i - a + 1 >= 0) minall[i - a + 1][j] = minrow[deq.back()][j];
		}
	}
	for(int i = 0; i <= n - a; i++)
		for(int j = 0; j <= m - b; j++)
			cost[i][j] = SUM(i, j, i + a, j + b) - minall[i][j] * a * b;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			mark[i][j] = (i > n - a) or (j > m - b);
			cells.PB(MP(i, j));
		}
	sort(all(cells), cmp);
	for(int i = 0; i < sz(cells); i++){
		pii cll = cells[i];
		if(mark[cll.L][cll.R])
			continue;
		ans.PB(i);
		for(int ii = max(0LL, cll.L - a + 1); ii < min(n, cll.L + a); ii++)
			for(int jj = max(0LL, cll.R - b + 1); jj < min(m, cll.R + b); jj++)
				mark[ii][jj] = true;
	}
	printf("%d\n", sz(ans));
	for(auto id : ans)
		printf("%d %d %I64d\n", cells[id].L + 1, cells[id].R + 1, cost[cells[id].L][cells[id].R]);
	return 0;
}
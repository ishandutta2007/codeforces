#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N (210)
#define INF (922337203685477580)

struct edge {
	int to;
	long long dis;
};

int n, m;
vector<edge>e[N];
long long d[N];
bool used[N];
bool zz;

void init(void) {
	memset(used, 0, sizeof(used));
	return;
}

void bellmanford(int x) {
	f(i, N)d[i] = INF;
	zz = true;
	d[x] = 0;
	f(ii, n - 1) {
		f(i, n) {
			f(j, e[i].size()) {
				if (d[e[i][j].to] > d[i] + e[i][j].dis)d[e[i][j].to] = d[i] + e[i][j].dis;
			}
		}
	}
	f(i, n) {
		f(j, e[i].size()) {
			if (d[e[i][j].to] > d[i] + e[i][j].dis) {
				if (d[i] < (INF / 10))zz = false;
			}
		}
	}
}

int mark[N];
bool finv = true;

void dfs(int k, int mm) {
	if (mark[k] == mm)return;
	if (mark[k] >= 0) {
		finv = false;
		return;
	}
	mark[k] = mm;
	f(j, e[k].size()) {
		dfs(e[k][j].to, (mm ^ 1));
		if (!finv)return;
	}
	return;
}


int main(void) {
	int k;
	int x, y;
	finv = true;
	long long z;
	long long s, ans;
	long long recs = -1;
	long long rec[N];
	scanf("%d %d", &n, &m);
	init();
	f(i, m) {
		scanf("%d %d %lld", &x, &y, &z);
		x--;
		y--;
		if (z == 0) {
			e[x].push_back({ y, ((long long)1) });
			e[y].push_back({ x, ((long long)1) });
		}
		else {
			e[x].push_back({ y, ((long long)1) });
			e[y].push_back({ x, ((long long)-1) });
		}
	}
	f(i, n)mark[i] = -1;
	dfs(0, 0);
	if (!finv) {
		cout << "NO" << endl;
		return 0;
	}
	f(i, n) {
		bellmanford(i);
		if (!zz) {
			finv = false;
			break;
		}
		f(j, n) {
			if (d[j] > recs) {
				f(ii, n) {
					rec[ii] = d[ii];
					recs = max(recs, d[ii]);
				}
			}
		}
	}
	if (!finv) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	cout << recs << endl;
	f(i, n - 1)cout << rec[i] << " ";
	cout << rec[n-1] << endl;



	return 0;
}
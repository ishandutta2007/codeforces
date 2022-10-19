#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 510;

struct Node {int x, y, w;};
bool operator < (Node a, Node b) {
	return a.w > b.w;
}

int T, n, k, w1[N][N], w2[N][N], dis[N][N], tmp1[N][N], tmp2[N][N];
priority_queue <Node> q;

int in(int x, int y) {return 1 <= x && x <= k + 1 && 1 <= y && y <= k + 1;}

int main() {
	for (read(T); T; T--) {
		read(n), read(k);
		for (int i = 0; i <= k + 1; i++)
			for (int j = 0; j <= k + 1; j++) {
				w1[i][j] = w2[i][j] = 0, dis[i][j] = inf;
				tmp1[i][j] = tmp2[i][j] = 0;
			}
		for (int i = 1; i <= n; i++) {
			int r1, c1, r2, c2;
			read(r1), read(c1);
			read(r2), read(c2);
			if (c1 > c2 || r1 > r2) swap(r1, r2), swap(c1, c2);
			if (r1 < r2) tmp1[r1+1][c1]++;
			if (c1 < c2) tmp2[r1][c1+1]++;
		}
		int _k = k / 2 + 1;
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++) {
				w1[i][j] += tmp2[i][j];
				w1[k + 1 - i][k + 2 - j] += tmp2[i][j];
				w2[i][j] += tmp1[i][j];
				w2[k + 2 - i][k + 1 - j] += tmp1[i][j];
			}
		dis[_k][_k] = 0;
		q.push((Node){_k, _k, 0});
		while (q.size()) {
			Node tmp = q.top(); q.pop();
			int x = tmp.x, y = tmp.y, w = tmp.w;
			if (w > dis[x][y]) continue;
			if (in(x - 1, y)) {
				if (dis[x - 1][y] > dis[x][y] + w1[x - 1][y]) {
					dis[x - 1][y] = dis[x][y] + w1[x - 1][y];
					q.push((Node){x - 1, y, dis[x - 1][y]});
				}
			}
			if (in(x + 1, y)) {
				if (dis[x + 1][y] > dis[x][y] + w1[x][y]) {
					dis[x + 1][y] = dis[x][y] + w1[x][y];
					q.push((Node){x + 1, y, dis[x + 1][y]});
				}
			}
			if (in(x, y - 1)) {
				if (dis[x][y - 1] > dis[x][y] + w2[x][y - 1]) {
					dis[x][y - 1] = dis[x][y] + w2[x][y - 1];
					q.push((Node){x, y - 1, dis[x][y - 1]});
				}
			}
			if (in(x, y + 1)) {
				if (dis[x][y + 1] > dis[x][y] + w2[x][y]) {
					dis[x][y + 1] = dis[x][y] + w2[x][y];
					q.push((Node){x, y + 1, dis[x][y + 1]});
				}
			}
		}
		int ans = inf;
		for (int i = 1; i <= k + 1; i++)
			ans = min(ans, min(min(dis[1][i], dis[k + 1][i]), min(dis[i][1], dis[i][k + 1])));
		print(n - ans, '\n');
	}
	return 0;
}
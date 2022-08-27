#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e3 + 7;
const int M = N * N;

struct Graph {

int now[5][5], n, m;
int msk[N], ans[N], to[N][7], las[N], tot;
void make(int k) {
	R(i, n, 1) R(j, m, 1) now[i][j] = (k & 1), k >>= 1;
}
int hash() {
	int k = 0;
	L(i, 1, n) L(j, 1, m) k <<= 1, k |= now[i][j];
	return k;
} 
void bfs() {
	int mx = 0;
	memset(ans, 0x3f, sizeof(ans));
	ans[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		L(i, 1, n - 1) L(j, 1, m - 1) {
			L(s1, 0, 1) L(s2, 0, 1) {
				make(u);
				L(p1, 0, 1) L(p2, 0, 1) if(p1 != s1 || p2 != s2) now[i + p1][j + p2] ^= 1;
				int v = hash();
				if(ans[v] > ans[u] + 1) {
					int tot = 0;
					ans[v] = ans[u] + 1, q.push(v);
					L(p1, 0, 1) L(p2, 0, 1) if(p1 != s1 || p2 != s2) to[v][++tot] = i + p1, to[v][++tot] = j + p2;
					las[v] = u;
				}
			}
		}
	}
}

} P[4];

int n, m, tot, X1[M], Y1[M], X2[M], Y2[M], X3[M], Y3[M];
char s[N][N];

void get(int k, int stx, int sty) {
	L(i, 1, P[k].n) L(j, 1, P[k].m) P[k].now[i][j] = s[stx + i - 1][sty + j - 1] - '0';
	int sp = P[k].hash();
	while(sp) {
		++tot;
		X1[tot] = stx + P[k].to[sp][1] - 1;
		Y1[tot] = sty + P[k].to[sp][2] - 1;
		X2[tot] = stx + P[k].to[sp][3] - 1;
		Y2[tot] = sty + P[k].to[sp][4] - 1;
		X3[tot] = stx + P[k].to[sp][5] - 1;
		Y3[tot] = sty + P[k].to[sp][6] - 1;
		sp = P[k].las[sp];
	}
}

void rev(int i, int j) {
	int px = i + 1, py = j + 1;
	if(i == n) px = i - 1;
	if(j == m) py = j - 1;
	++tot, X1[tot] = i, Y1[tot] = j, X2[tot] = px, Y2[tot] = j, X3[tot] = i, Y3[tot] = py;
	++tot, X1[tot] = i, Y1[tot] = j, X2[tot] = px, Y2[tot] = j, X3[tot] = px, Y3[tot] = py;
	++tot, X1[tot] = i, Y1[tot] = j, X2[tot] = px, Y2[tot] = py, X3[tot] = i, Y3[tot] = py;
	s[i][j] = '0';
}
void Main() {
	cin >> n >> m, tot = 0;
	L(i, 1, n) cin >> (s[i] + 1);
	if(n % 2 == 1 && m % 2 == 1) {
		get(3, 1, 1);
		for(int i = 4; i <= m; i += 2) get(2, 1, i);
		for(int i = 4; i <= n; i += 2) get(1, i, 1);
		for(int i = 4; i <= n; i += 2) for(int j = 4; j <= m; j += 2) get(0, i, j);
	}
	if(n % 2 == 0 && m % 2 == 1) {
		for(int i = 1; i <= n; i += 2) get(1, i, 1);
		for(int i = 1; i <= n; i += 2) for(int j = 4; j <= m; j += 2) get(0, i, j);
	}
	if(n % 2 == 1 && m % 2 == 0) {
		for(int i = 1; i <= m; i += 2) get(2, 1, i);
		for(int i = 4; i <= n; i += 2) for(int j = 1; j <= m; j += 2) get(0, i, j);
	}
	if(n % 2 == 0 && m % 2 == 0) {
		for(int i = 1; i <= n; i += 2) for(int j = 1; j <= m; j += 2) get(0, i, j);
	}
	cout << tot << "\n";
	L(i, 1, tot) cout << X1[i] << " " << Y1[i] << " " << X2[i] << " " << Y2[i] << " " << X3[i] << " " << Y3[i] << "\n";
}
int main() {
	P[0].n = 2, P[0].m = 2, P[0].bfs();
	P[1].n = 2, P[1].m = 3, P[1].bfs();
	P[2].n = 3, P[2].m = 2, P[2].bfs();
	P[3].n = 3, P[3].m = 3, P[3].bfs();
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main();
	return 0;
}
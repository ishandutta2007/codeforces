#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
#define fs first
#define sd second
using namespace std;
typedef long double dbl;
typedef long long ll;
const ll INF = (ll)(1e18);
const ll inf = 1e9 + 7;
dbl eps = 1e-15;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll mod = 998244353;
ll pows(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		ll c = pows(a, b / 2);
		return (c * c);
	}
	if (b % 2 == 1) return (a * pows(a, b - 1));
}
vector<string> matr;
vector<int> s, p, used;
vector < pair<int, ll>> d;
int dx[4]{ 0,0,1,-1 }, dy[4]{ -1,1,0,0 };
int conv(int x, int y) {
	return x * 1000 + y;
}
pair<int, int> get(int n) {
	return { n / 1000, n % 1000 };
}
int getpr(int v) {
	if (p[v] != v) p[v] = getpr(p[v]);
	return p[v];
}
void unite(int a, int b) {
	a = getpr(a);
	b = getpr(b);
	if (a == b) return;
	if (s[a] < s[b]) swap(a, b);
	s[a] += s[b];
	p[b] = a;
}
int n; int m;
signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m;
	int q; cin >> q;
	matr.resize(n);
	s.resize(1000 * n, 1);
	used.resize(1000 * n);
	p.resize(1000 * n);
	d.resize(1000 * n, { inf,INF });
	for (int i = 0; i < 1000 * n; i++) {
		p[i] = i;
	}
	for (int i = 0; i < n; i++) cin >> matr[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int z = 0; z < 4; z++) {
				int nx = i + dx[z], ny = j + dy[z];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (matr[i][j] == matr[nx][ny]) unite(conv(i, j), conv(nx, ny));
			}
		}
	}
	queue<int> qr;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[getpr(conv(i, j))] > 1) {
				d[conv(i, j)] = { getpr(conv(i, j)),0 };
				qr.push(conv(i, j));
			}
		}
	}
	while (!qr.empty()) {
		int v = qr.front();
		qr.pop();
		int x = get(v).fs, y = get(v).sd;
		for (int z = 0; z < 4; z++) {
			int nx = x + dx[z], ny = y + dy[z];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			int to = conv(nx, ny);
			if (d[to].sd > d[v].sd + 1) {
				d[to].sd = d[v].sd + 1;
				d[to].fs = d[v].fs;
				qr.push(conv(nx, ny));
			}
		}
	}
	for (int i = 0; i < q; i++) {
		ll x, y, t; cin >> x >> y >> t; x--; y--;
		int v = conv(x, y);
		if (t < d[v].sd) {
			cout << matr[x][y] << '\n';
			continue;
		}
		if ((t - d[v].sd) % 2 == 0) {
			int nx = get(v).fs, ny = get(v).sd;
			cout << matr[x][y] << '\n';
		}
		else {
			int nx = get(v).fs, ny = get(v).sd;
			cout << char((matr[x][y] - '0' + 1) % 2 + '0') << '\n';
		}
	}
}
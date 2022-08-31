#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define sz(a) ((int) (a).size())
#define mkp make_pair
#define vi vector<int>
using namespace std;
const int N = 407, mod = 998244353;
int all = 1, tot;
struct Martix {
	int G[N][N];
	void clear() { L(i, 1, tot) L(j, 1, tot) G[i][j] = 0; }
	void start() { clear(); L(i, 1, tot) G[i][i] = 1; }
} P;
Martix operator * (Martix aa, Martix bb) {
	Martix res; 
	res.clear(); 
	L(i, 1, tot) 
		L(j, 1, tot) 
			L(k, 1, tot) (res.G[i][j] += (ll) aa.G[i][k] * bb.G[k][j] % mod) %= mod;
	return res;
}
Martix operator ^ (Martix aa, int bb)  {
	Martix res; res.start();
	for(; bb; aa = aa * aa, bb >>= 1) if(bb & 1) res = res * aa;
	return res;
}
int n, m, Len, ch[N][26], Cnt[N];
char s[N];
int Vis[N][N], f[N][2];
queue< int > q;
int get(int x, int y) {
	if(x > y) swap(x, y);
	if(!Vis[x][y]) Vis[x][y] = ++tot, f[tot][0] = x, f[tot][1] = y, q.push(tot);
	return Vis[x][y];
}
void getEdge() {
	get(1, 1);
	while( !q.empty() ) {
		int u = q.front(), s1 = f[u][0], s2 = f[u][1];
		q.pop();
		L(i, 0, 25) if(ch[s1][i] && ch[s2][i]) {
			P.G[u][get(ch[s1][i], ch[s2][i])] += 1; 
			P.G[u][get(ch[s1][i], 1)] += Cnt[ch[s2][i]]; 
			P.G[u][get(1, ch[s2][i])] += Cnt[ch[s1][i]]; 
			P.G[u][get(1, 1)] += Cnt[ch[s1][i]] * Cnt[ch[s2][i]];
		}
	}
	if(tot > 300) assert(0);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) {
		cin >> (s + 1), Len = strlen(s + 1);
		int now = 1;
		L(j, 1, Len) {
			if(!ch[now][s[j] - 'a']) ch[now][s[j] - 'a'] = ++all;
			now = ch[now][s[j] - 'a'];
		}
		Cnt[now] ++;
	}
	getEdge();
	cout << (P ^ m).G[1][1] << "\n";
	return 0;
} 
// To Cheat, To attack!
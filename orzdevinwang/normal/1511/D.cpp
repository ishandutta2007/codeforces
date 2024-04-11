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
const int N = 3e3 + 7;
int n, m, a[N], pos[N], all = 50;
int ns[N], tot;
int E[N][N];
void DFS(int x) {
	L(i, 1, m) if(E[x][i]) E[x][i] = 0, DFS(i), ns[++tot] = i;
}
int vis[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, m) L(j, 1, m) E[i][j] = true;
	DFS(1);
	L(i, 1, n) cout << (char) (ns[i % tot + 1] + 'a' - 1);
	cout << "\n";
	return 0;
} 
// To Cheat, To attack!
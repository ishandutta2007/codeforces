#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7;
int n, m, to[N][2], dis[N], cnt; 
void Main () {
	cin >> n >> m, cnt = 0;
	L(i, 1, n) to[i][0] = to[i][1] = dis[i] = 0;
	while(m--) {
		int u, v;
		cin >> u >> v, to[u][!!to[u][0]] = v;
	}
	L(i, 1, n) {
		if(dis[i] == 2) cnt++;
		else L(o, 0, 1) if(to[i][o]) dis[to[i][o]] = max(dis[to[i][o]], dis[i] + 1); 
	}
	cout << cnt << '\n';
	L(i, 1, n) if(dis[i] == 2) cout << i << ' ';
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, Prime[N], vis[N], g[N], tot, ans[N][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n, Prime[1] = true;
	L(i, 2, n) if(!Prime[i]) L(j, 2, n / i) Prime[i * j] = true;
	R(i, n / 2, 2) if(!Prime[i]) {
		int cnt = 0; 
		L(j, 1, n / i) if(!vis[i * j]) g[++cnt] = i * j;
		if(cnt % 2 == 1 && i != 2) {
			L(j, 2, cnt - 1) g[j] = g[j + 1];
			--cnt;
		}
		L(j, 1, cnt / 2) ++tot, ans[tot][0] = g[j * 2], ans[tot][1] = g[j * 2 - 1];
		L(j, 1, cnt) vis[g[j]] = true;
	}
	cout << tot << "\n";
	L(i, 1, tot) cout << ans[i][0] << " " << ans[i][1] << "\n";
	return 0;
}
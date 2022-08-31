#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
#define i128 __int128
using namespace std;
const int N = 1e6 + 7;
int T, n, l, r, vis[N];
void Main() {
	int u, cnt = 0, ns = 0, o = 0;
	cin >> n >> l >> r;
	if(l < r) {
		L(i, 1, l) cin >> u, vis[u]--;
		L(i, 1, r) cin >> u, ++vis[u];
		swap(l, r); 
	}
	else { 
		L(i, 1, l) cin >> u, vis[u]++;
		L(i, 1, r) cin >> u, --vis[u];
	} 
	cnt = (l - r) / 2;
	L(i, 1, n) {
		while(cnt && vis[i] >= 2) vis[i] -= 2, --cnt, ++ns;
		o += abs(vis[i]);
	}
	cout << ns + o / 2 + cnt << "\n";
	L(i, 1, n) vis[i] = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) Main();
	return 0;
}
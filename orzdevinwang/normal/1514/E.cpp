#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define ull unsigned long long
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 233;
int n, tot, v[N];
set < int > S[N];
void merge(int x, int y) {
	for(int k : S[y]) S[x].insert(k);
	S[y].clear();
}
int getin() {
	int k;
	return cin >> k, k;
}
bool check(int x, int y) {
	return cout << 1 << " " << x << " " << y << endl, getin();
}
bool all[N][N], vis[N];
int rmain() {
	memset(all, 0, sizeof(all)), memset(vis, 0, sizeof(vis)), memset(v, 0, sizeof(v));
	L(i, 1, tot) S[i].clear();
	tot = 0;
	cin >> n;
	L(i, 0, n - 1) {
		int l = 1, r = tot + 1;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(mid == tot + 1 || check(i, v[mid])) r = mid;
			else l = mid + 1;
		}
		R(i, tot, l) v[i + 1] = v[i];
		++tot, v[l] = i;
	}
	L(i, 1, tot) S[i].insert(v[i]);
	int now = tot;
	while(now > 1) {
		for(int v : S[now]) if(!vis[v]) {
			cout << 2 << " " << v << " ";
			int cnt = 0;
			L(i, 1, now - 1) cnt += sz(S[i]);
			cout << cnt << " ";
			L(i, 1, now - 1) for(int u : S[i]) cout << u << " ";
			cout << endl;
			if(getin()) {
				merge(now - 1, now);
				break;	
			}
			vis[v] = true;
		}
		--now;
	}
	L(i, 1, tot) L(j, i, tot) for(int u : S[i]) for(int v : S[j]) all[u][v] = true;
	cout << 3 << endl;
	L(i, 0, n - 1) {
		L(j, 0, n - 1) cout << all[i][j];
		cout << endl;	
	} 
	return getin(), 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) rmain();
	return 0;
}
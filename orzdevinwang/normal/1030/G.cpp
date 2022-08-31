#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e6 + 7, mod = 1e9 + 7; 
int n, w[N];
int p[N], rs[N], tot;
bool Prime[N];
void xxs(int x) {
	L(i, 2, x) {
		if(!Prime[i]) p[++tot] = i, rs[i] = i;
		for(int j = 1; p[j] * i <= x && j <= tot; j ++) {
			Prime[p[j] * i] = 1, rs[p[j] * i] = p[j];
			if(i % p[j] == 0) break;
		}
	}
}
int vis[N], like[N], nt[N];
bool FJ (int x) {
	bool ns = 0; 
	while (x > 1) {
		int z = rs[x], cnt = 0;
		while (x % z == 0) x /= z, cnt += 1; 
		if(vis[z] < cnt) vis[z] = cnt, ns = true, nt[z] = 1;
		else if(vis[z] == cnt) nt[z] += 1;
	}
	return ns;
}
bool FFJ (int x) {
	bool ns = 0; 
	while (x > 1) {
		int z = rs[x], cnt = 0;
		while (x % z == 0) x /= z, cnt += 1; 
		if(vis[z] == cnt) ns |= nt[z] == 1;
	}
	return ns;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int one = 0;
	xxs (N - 3);
	cin >> n;
	L(i, 1, n) cin >> w[i];
	sort(w + 1, w + n + 1);
	R(i, n, 1) 
		if(!vis[w[i]]) FJ(w[i]);
		else like[i] = true, FJ(w[i] - 1);
	L(i, 1, n) 
		if(like[i] && !FFJ(w[i] - 1)) 
			one = true;
	int ns = 1;
	L(i, 2, N - 3) L(t, 1, vis[i]) ns = (ll) ns * i % mod;
	cout << (ns + one) % mod << '\n';
	return 0;
}
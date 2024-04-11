#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 5e5 + 7;
int n, x, y, z, mx, tot, cir, g[N];
int c1[N], c2[N], c3[N], Cnt[N];
ll a[N];
map<vi, int> mp;
int get(ll x, int y) {
	if(x > tot) x %= cir, x += (tot - x) / cir * cir;
	return y == 1 ? c1[x] : (y == 2 ? c2[x] : c3[x]);
}
void Main() {
	mp.clear();
	cin >> n >> x >> y >> z, mx = max(max(x, y), z), tot = 0;
	while(1) {
		++tot, c1[tot] = c2[tot] = c3[tot] = 0;
		int v1 = max(tot - x, 0), v2 = max(tot - y, 0), v3 = max(tot - z, 0);
		++ Cnt[c1[v1]], ++ Cnt[c2[v2]], ++ Cnt[c3[v3]];
		while(Cnt[c1[tot]]) ++ c1[tot];
		-- Cnt[c2[v2]];
		while(Cnt[c2[tot]]) ++ c2[tot];
		++ Cnt[c2[v2]], -- Cnt[c3[v3]];
		while(Cnt[c3[tot]]) ++ c3[tot];
		-- Cnt[c1[v1]], -- Cnt[c2[v2]]; 
//		cout << c1[tot] << " " << c2[tot] << " " << c3[tot] << "\n";
		vi now;
		L(i, 0, mx - 1) 
			if(tot > i) now.push_back(c1[tot - i]), now.push_back(c2[tot - i]), now.push_back(c3[tot - i]);
			else now.push_back(0), now.push_back(0), now.push_back(0);
		if(mp[now]) {
			cir = tot - mp[now];
			break;	
		}
		mp[now] = tot;
	}
	L(i, 1, n) cin >> a[i];
	int ns = 0, ans = 0;
	L(i, 1, n) g[i] = get(a[i], 1), ns ^= g[i]; 
	L(i, 1, n) {
		if(! (ns ^ g[i] ^ get(max(a[i] - x, 0ll), 1) ) ) ans ++;
		if(! (ns ^ g[i] ^ get(max(a[i] - y, 0ll), 2) ) ) ans ++;
		if(! (ns ^ g[i] ^ get(max(a[i] - z, 0ll), 3) ) ) ans ++;
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}
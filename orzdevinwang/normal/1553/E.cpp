#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e6 + 7;
int n, m;
int p[N], a[N];
int f [N];
int find (int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
bool chk (int x) {
	L(i, 1, n) f[i] = i;
	L(i, x + 1, n) a[i] = i - x;
	L(i, 1, x) a[i] = n - x + i;
	
	int cnt = 0;
	L(i, 1, n) {
		int u = a[i], v = p[i];
		if(find(u) == find(v)) 
			++cnt; 
		else f[find(u)] = find(v); 
	}
	return n - cnt <= m;
} 
int cnt[N];
void Main () {
	cin >> n >> m; 
	L(i, 1, n) {
		cin >> p[i];
		int u = (i - p[i] + n) % n;	
		cnt[u] ++;
	}
	vi ns;
	L(i, 0, n - 1) if(cnt[i] >= n / 3 - 1 && chk(i)) ns.push_back(i);
	cout << sz(ns) << " ";
	L(i, 0, sz(ns) - 1) cout << ns[i] << " ";
	cout << "\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}
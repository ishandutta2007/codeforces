#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 5e5 + 7;

int n, mid, a[N], p[N], f[N];
vi vc[N];

inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

void Main () {
	cin >> n, mid = -1;
	L(i, 1, n) vc[i].clear();
	L(i, 1, n) cin >> a[i], vc[a[i]].emplace_back(i);
	L(i, 1, n) f[i] = i; 
	int cm = -1;
	L(i, 1, n) if(sz(vc[i]) & 1) {
		if(cm != -1) return cout << "NO\n", void ();
		cm = i;
	} 
	assert((cm != -1) == (n & 1)); 
	if(cm != -1) {
		mid = (n + 1) >> 1;
		if(vc[cm].back() == mid) {
			if(sz(vc[cm]) == 1) return cout << "NO\n", void ();
			swap(vc[cm][sz(vc[cm]) - 1], vc[cm][sz(vc[cm]) - 2]);
		}
		p[mid] = vc[cm].back(), vc[cm].pop_back();
	}
	int v = 1;
	L(i, 1, n / 2) {
		while(!sz(vc[v])) assert(v <= n), ++v;
		p[i] = vc[v].back(), vc[v].pop_back(), 
		p[n - i + 1] = vc[v].back(), vc[v].pop_back();
	}
	L(i, 1, n) f[find(i)] = find(p[i]);
	L(i, 1, n / 2) 
		if(find(i) != find(n - i + 1)) 
			swap(p[i], p[n - i + 1]), f[find(i)] = find(n - i + 1);
	L(i, 2, n / 2) 
		if(find(1) != find(i)) {
			int x1 = p[1], xn = p[n];
			p[1] = p[i], p[n] = p[n - i + 1];
			p[i] = xn, p[n - i + 1] = x1; 
			f[find(i)] = find(1); 
		}
	cout << "YES\n";
	L(i, 1, n) cout << p[i] << ' ';
	cout << '\n';
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main ();
	return 0;
}
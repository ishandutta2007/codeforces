#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define uint unsigned int 
using namespace std;
const int N = 1e5 + 7;
int n, a[N], x[N], y[N], ord[N];
int f[N];
int find (int x) {
	return f[x] == x ? x : f[x] = find (f[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) f[i] = i;
	L(i, 1, n) cin >> x[i] >> y[i] >> a[i];
	L(i, 1, n) if(find(i) != find (a[i])) f[find(i)] = find (a[i]);
	
	vi ord;
	L(i, 1, n) if(a[i] != i) ord.push_back(i); 
	if(!sz(ord)) return cout << 0 << '\n', 0;
	L(i, 0, sz(ord) - 1) 
		if(y[ord[i]] < y[ord[0]] || (y[ord[i]] == y[ord[0]] && x[ord[i]] < x[ord[0]])) 
			swap (ord[0], ord[i]);
	
	int p = ord[0];
	sort(ord.begin() + 1, ord.end(), [&] (int a, int b) {
		ll ax = x[a] - x[p], ay = y[a] - y[p], bx = x[b] - x[p], by = y[b] - y[p];
		return ax * by - ay * bx < 0;
	});
	vector < pair < int, int > > vc;
	
	L(i, 1, sz(ord) - 2) if(find(ord[i]) != find(ord[i + 1])) 
		swap (a[ord[i]], a[ord[i + 1]]), vc.push_back({ord[i], ord[i + 1]}), 
		f[find(ord[i])] = find(ord[i + 1]);
	
	while (a[p] != p) vc.push_back({p, a[p]}), swap (a[p], a[a[p]]);
	L(i, 1, n) assert (a[i] == i);
	cout << sz(vc) << '\n';
	for (auto u : vc) cout << u.first << ' ' << u.second << '\n';
	return 0;
}
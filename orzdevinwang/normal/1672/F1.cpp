#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define ld long double
#define i128 __int128 
using namespace std;
const int N = 1e6 + 7;
int n, m, c[N], a[N], b[N];
vi qwq[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) c[i] = 0, qwq[i].clear();
	L(i, 1, n) {
		qwq[a[i]].emplace_back(i);
		c[a[i]] += 1;
	}
	vi ord;
	L(i, 1, n) if(c[i]) ord.emplace_back(i); 
//	else cout << i << " : " << c[i] << endl;
	sort(ord.begin(), ord.end(), [&] (int x, int y) {
		return c[x] > c[y];
	});
//	for(auto u : ord) 
//		cout << u << ", ";
//	cout << '\n';
	vi nw;
	L(i, 1, sz(ord) - 1) L(j, 1, c[ord[i]]) nw.emplace_back(ord[i]);
	L(j, 1, c[ord[0]]) nw.emplace_back(ord[0]); 
	int p = 0;
	for(auto u : ord) 
		L(i, 0, sz(qwq[u]) - 1) 
			b[qwq[u][i]] = nw[p++];
	L(i, 1, n) 
		cout << b[i] << ' ';
	cout << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}
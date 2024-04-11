#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7;
int n, k, b[N], a[N];
vi vc[N];
void Main() {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 0, n + 1) vc[i].clear();
	L(i, 1, n) vc[a[i]].emplace_back(i);
	int l = 0, r = n;
	L(i, 1, n) {
		int x = i, y = a[i];
		if(x > y) swap(x, y);
		l = max(l, x);
		r = min(r, y - 1);
	}
	assert(l == r);
	k = l;
	vi cur, ns;
	cur.emplace_back(0), cur.emplace_back(n + 1);
	while(true) {
		int mc = -1;
		L(i, 0, sz(cur) - 1) {
			if(sz(vc[cur[i]])) {
				assert(mc == -1);
				mc = i;
			}
		}
		if(mc == -1) {
			for(const int &u : cur) 
				ns.emplace_back(u);
			break ;
		}
		swap(cur[sz(cur) - 1], cur[mc]);
		for(const int &u : cur) 
			ns.emplace_back(u);
		cur = vc[cur[sz(cur) - 1]];
//		cout << "sz cur = " << sz(cur) << endl;
	} 
//	cout << "sz ns = " << sz(ns) << endl;
	assert(sz(ns) == n + 2);
	cout << k << '\n';
	L(i, 2, sz(ns) - 1) cout << ns[i] << ' ';
	cout << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}
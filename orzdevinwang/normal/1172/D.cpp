#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define uint unsigned int 
using namespace std;
const int N = 1e3 + 7;
int n, r[N], c[N], mpr[N], mpc[N];
vector < pair < pair < int, int >, pair < int, int > > > vc;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	L(i, 1, n) cin >> r[i], mpr[r[i]] = i;
	L(i, 1, n) cin >> c[i], mpc[c[i]] = i;
	L(i, 1, n - 1) {
		if(r[i] == i && c[i] == i) 
			continue ;
		int ri = r[i], ci = c[i], x = mpr[i], y = mpc[i];
		vc.push_back({{x, i}, {i, y}});
		swap (r[i], r[x]);
		swap (mpr[ri], mpr[i]);
		swap (c[i], c[y]);
		swap (mpc[ci], mpc[i]);
	}
	cout << sz(vc) << '\n';
	for (auto u : vc) 
		cout << u.first.first << ' ' << u.first.second << ' ' 
		<< u.second.first << ' ' << u.second.second << '\n';
	return 0;
}
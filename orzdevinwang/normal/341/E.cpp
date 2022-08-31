#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define uint unsigned int 
using namespace std;
const int N = 1e5 + 7;
int n, a[N];
vector < pair < int, int > > vc;
void D (int x, int y) {
	assert (a[x] <= a[y]);
	a[y] -= a[x];
	a[x] <<= 1;
	vc.push_back({x, y});
}
pair < int, int > solve (int x, int y, int z) {
	if(a[x] > a[y]) swap(x, y);
	if(a[x] > a[z]) swap(x, z);
	if(a[y] > a[z]) swap(y, z);
	if(a[y] == a[z]) {
		D(y, z);
		return {x, y};
	}
	int w = a[y] / a[x];
	for (; w; w >>= 1) D(x, (w & 1) ? y : z);
	if(!a[y]) return {x, z};
	return solve (x, y, z);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	int pa = 0, pb = 0;
	L(i, 1, n) if(a[i]) {
		if(!pa) pa = i;
		else if(!pb) pb = i;
		else {
			auto x = solve (pa, pb, i);
			pa = x.first;
			pb = x.second;
		}
	}
	if(!pa || !pb) {
		cout << -1 << '\n';
	}
	else {
		cout << sz(vc) << '\n';
		for (auto x : vc) 
			cout << x.first << ' ' << x.second << '\n';
	}
	return 0;
}
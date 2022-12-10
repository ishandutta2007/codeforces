//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 2e5,
	  maxn3 = 6e5;
int cnt[maxn3],
	a[maxn],
	b[maxn],
	c[maxn],
	n, m;
vector<int> all;

int f(int val){
	return cnt[lower_bound(all(all), val) - all.begin()];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], all.PB(a[i]);
	cin >> m;
	for(int i = 0; i < m; i++)
		cin >> b[i], all.PB(b[i]);
	for(int i = 0; i < m; i++)
		cin >> c[i], all.PB(c[i]);
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < n; i++)
		cnt[lower_bound(all(all), a[i]) - all.begin()]++;
	pair<pii, int> ans({-1, -1}, -1);
	for(int i = 0; i < m; i++)
		smax(ans, MP(MP(f(b[i]), f(c[i])), i + 1));
	cout << ans.R << endl;
	return 0;
}
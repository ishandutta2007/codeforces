//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 5000;
pii ans[2][maxn];
int n, m, q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i=  1; i <= q;i++){
		int ty, fi, se;
		cin >> ty >> fi >> se;
		ty--, fi--;
		ans[ty][fi] = MP(i, se);
	}
	for(int i = 0; i < n; i++, cout << '\n')
		for(int j = 0; j < m; j++)
			cout << max(ans[0][i], ans[1][j]).R << ' ';
	return 0;
}
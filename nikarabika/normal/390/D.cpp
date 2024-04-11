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

int n, m, k, anscnt;
vector<vector<pii> > ans;
vector<pair<int, pii> > all;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			all.PB(MP(i + j, MP(i, j)));
	sort(all(all));
	for(auto cel : all){
		if(!k)
			break;
		k--;
		pii cell = cel.R;
		vector<pii> vec;
		for(int i = 1; i <= cell.L; i++)
			vec.PB(MP(i, 1));
		for(int j = 2; j <= cell.R; j++)
			vec.PB(MP(cell.L, j));
		ans.PB(vec);
		anscnt += sz(vec);
	}
	reverse(all(ans));
	cout << anscnt << '\n';
	for(auto vec : ans){
		for(auto cell : vec)
			cout << '(' << cell.L << ',' << cell.R << ')' << ' ';
		cout << '\n';
	}
	return 0;
}
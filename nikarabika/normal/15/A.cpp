//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;
typedef pair<LD, LD> pdd;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, t;
	cin >> n >> t;
	t *= 2;
	vector<pii> all;
	for(int i = 0; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi *= 2, se *= 2;
		all.PB({fi - se / 2, fi + se / 2});
	}
	sort(all(all));
	int ans = 2;
	for(int i = 1; i < sz(all); i++){
		if(all[i].L >= all[i - 1].R + t)
			ans++;
		if(all[i].L > all[i - 1].R + t)
			ans ++;
	}
	cout << ans << endl;
	return 0;
}
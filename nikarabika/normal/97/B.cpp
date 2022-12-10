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

const int maxn = 1e4 + 85 - 69;
vector<int> vec[maxn],
	ans[maxn],
	all;
vector<pii> vecans;
int x[maxn],
	y[maxn],
	n;
stack<pii> stc;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		all.PB(x[i]);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < n; i++){
		int id = lower_bound(all(all), x[i]) - all.begin();
		vec[x[i] = id].PB(y[i]);
	}
	stc.push(MP(0, sz(all) - 1));
	while(sz(stc)){
		pii seg = stc.top();
		stc.pop();
		if(seg.L > seg.R) continue;
		int id = (seg.L + seg.R) >> 1;
		for(int i = seg.L; i <= seg.R; i++)
			for(auto y : vec[i])
				ans[id].PB(y);
		stc.push(MP(seg.L, id - 1));
		stc.push(MP(id + 1, seg.R));
	}
	for(int i = 0; i < sz(all); i++){
		sort(all(ans[i]));
		ans[i].resize(unique(all(ans[i])) - ans[i].begin());
		for(auto y : ans[i])
			vecans.PB(MP(all[i], y));
	}
	cout << sz(vecans) << '\n';
	for(auto P : vecans)
		cout << P.L << ' ' << P.R << '\n';
	return 0;
}
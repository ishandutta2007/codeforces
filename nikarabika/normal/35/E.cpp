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

const int maxn = 2e5 + 85 - 69;
int hei[maxn],
	h[maxn],
	l[maxn],
	r[maxn],
	lord[maxn],
	rord[maxn],
	n;
multiset<int> ms;
vector<pii> ans;
vector<int> all;

bool lcmp(int i, int j){
	return l[i] < l[j];
}

bool rcmp(int i, int j){
	return r[i] < r[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> h[i] >> l[i] >> r[i];
		all.PB(l[i]);
		all.PB(r[i]);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	iota(lord, lord + n, 0);
	sort(lord, lord + n, lcmp);
	iota(rord, rord + n, 0);
	sort(rord, rord + n, rcmp);
	int lp = 0, rp = 0;
	ms.insert(0);
	for(int i = 0; i <= sz(all); i++){
		hei[i] = *ms.rbegin();
		while(lp < n and l[lord[lp]] <= all[i])
			ms.insert(h[lord[lp++]]);
		while(rp < n and r[rord[rp]] <= all[i])
			ms.erase(ms.lower_bound(h[rord[rp++]]));
	}
	for(int i = 1; i <= sz(all); i++){
		if(hei[i - 1] != hei[i]){
			ans.PB(MP(all[i - 1], hei[i - 1]));
			ans.PB(MP(all[i - 1], hei[i]));
		}
	}
	cout << sz(ans) << '\n';
	for(auto P : ans)
		cout << P.L << ' ' << P.R << '\n';
	return 0;
}
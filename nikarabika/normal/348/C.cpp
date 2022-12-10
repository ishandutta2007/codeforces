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

const int maxn = 100 * 1000 + 10,
	  maxsq = 320;
LL a[maxn],
   sumS[maxn],
   cnt[maxsq + 1][maxn],
   added[maxn],
   n, m, q;
vector<int> S[maxn],
	gresets;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi;
		while(fi--){
			cin >> se, se--;
			S[i].PB(se);
			sumS[i] += a[se];
		}
		sort(all(S[i]));
		//index[i] = sz(sets[sz(S[i]) <= maxsq]);
		if(sz(S[i]) > maxsq)
			gresets.PB(i);
	}
	for(int i = 0; i < sz(gresets); i++){
		int id1 = gresets[i];
		for(int j = 0; j < m; j++){
			for(auto val : S[j]){
				int idx = lower_bound(all(S[id1]), val) - S[id1].begin();
				cnt[i][j] += (idx != sz(S[id1]) and S[id1][idx] == val);
			}
		}
	}
	while(q--){
		char ty;
		LL fi, se;
		cin >> ty >> fi, fi--;
		if(ty == '?'){
			LL ans = 0;
			if(sz(S[fi]) <= maxsq)
				for(auto id : S[fi])
					ans += a[id];
			else
				ans = sumS[fi];
			for(int i = 0; i < sz(gresets); i++)
				ans += added[gresets[i]] * cnt[i][fi];
			cout << ans << '\n';
		}
		else{
			cin >> se;
			if(sz(S[fi]) <= maxsq){
				for(auto id : S[fi])
					a[id] += se;
				for(int i = 0; i < sz(gresets); i++)
					sumS[gresets[i]] += se * cnt[i][fi];
			}
			else
				added[fi] += se;
		}
	}
	return 0;
}
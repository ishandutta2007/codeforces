#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef long long int LL;
typedef pair<LL, LL> pie;

const int maxn = 1e5 + 85 - 85 + 1;
int n, m, k;
bool f[maxn];
LL d[maxn], par[maxn];
vector<pie> v[maxn], vv;
set<pie> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(d, 127, sizeof d);
	//memset(dd, 127, sizeof dd);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		LL fi, se, th;
		cin >> fi >> se >> th;
		v[fi].PB(MP(se, th));
		v[se].PB(MP(fi, th));
	}
	for(int i = 0; i < k; i++){
		LL fi, se;
		cin >> fi >> se;
		vv.PB(MP(fi, se));
		if(se < d[fi]){
			s.erase(MP(d[fi], fi));
			d[fi] = se;
			f[fi] = true;
			par[fi] = 1;
			s.insert(MP(d[fi], fi));
		}
	}
	s.erase(MP(d[1], 1));
	d[1] = 0;
	s.insert(MP(0, 1));
	while(s.size()){
		LL x = s.begin() -> R;
		s.erase(s.begin());
		for(auto adj : v[x]){
			LL y = adj.L, w = adj.R;
			if(d[x] + w < d[y]){
				s.erase(MP(d[y], y));
				d[y] = d[x] + w;
				s.insert(MP(d[y], y));
				f[y] = f[x];
				par[y] = x;
			}
			else if(d[x] + w == d[y] and f[y]){
				par[y] = x;
				f[y] = f[x];
			}
		}
	}
	for(int i = 0; i < vv.size(); i++){
		LL x = vv[i].L;
		if(par[x] == 1 and f[x]){
			k--;
			f[x] = false;
			continue;
		}
	}
	cout << k << endl;
	return 0;
}
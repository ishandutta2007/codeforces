#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef long long int LL;
typedef pair<LL, LL> pie;

const int maxn = 1e5 + 85 - 85 + 2;
LL d[maxn];
vector<pie> v[maxn];
vector<int> t[maxn], tt[maxn];
int n, m;
set<pie> s;

int outtime(int x, int tim){
	int id = lower_bound(t[x].begin(), t[x].end(), tim) - t[x].begin();
	if(id == t[x].size() or t[x][id] != tim)
		return tim;
	return tt[x][id];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(d, 127, sizeof d);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		v[fi].PB(MP(se, th));
		v[se].PB(MP(fi, th));
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 0; j < k; j++){
			int x;
			cin >> x;
			t[i].PB(x);
		}
		if(k == 0)
			continue;
		tt[i].resize(t[i].size());
		tt[i][t[i].size() - 1] = t[i].back() + 1;
		for(int j = t[i].size() - 2; j >= 0; j--){
			if(t[i][j] == t[i][j + 1] - 1)
				tt[i][j] = tt[i][j + 1];
			else
				tt[i][j] = t[i][j] + 1;
		}
	}
	d[1] = 0;
	s.insert(MP(0, 1));
	while(s.size()){
		int x = s.begin() -> R;
		s.erase(s.begin());
		for(auto adj : v[x]){
			int y = adj.L, w = adj.R, outt = outtime(x, d[x]);
			if(outt + w < d[y]){
				s.erase(MP(d[y], y));
				d[y] = outt + w;
				s.insert(MP(d[y], y));
			}
		}
	}
	if(d[n] == d[n + 1])
		cout << -1 << endl;
	else
		cout << d[n] << endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;
typedef pair<pie, int> piie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e3 + 85 - 69;
int v[maxn], vc[maxn];
vector<piie> ans;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(v, -1, sizeof v);
	memset(vc, -1, sizeof vc);
	cin >> n >> m;
	while(m--){
		int fi, se, th;
		cin >> fi >> se >> th;
		v[fi] = th;
		vc[se] = fi;
	}
	for(int i = 1; i <= n; i++){
		if(v[i] != -1)
			continue;
		int zarf = 1e9;
		int x = i;
		while(vc[x] != -1){
			x = vc[x];
			zarf = min(zarf, v[x]);
		}
		if(x != i)
			ans.PB(MP(MP(x, i), zarf));
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(auto x : ans)
		cout << x.L.L << ' ' << x.L.R << ' ' << x.R << '\n';
	return 0;
}
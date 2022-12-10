#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back

const int maxn = 1e5 + 85 - 69;
vector<int> v[maxn];
int h[maxn];
LL Cnt[2];
bool mark[maxn];
LL n, m, ans;

void dfs(int x, int p = -1){
	mark[x] = true;
	for(auto y : v[x]){
		if(!mark[y]){
			h[y] = h[x] + 1;
			Cnt[h[y] & 1]++;
			dfs(y, x);
		}
		else if(y != p and (h[x] & 1) == (h[y] & 1)){
			cout << 0 << ' ' << 1 << endl;
			exit(0);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	LL cnt = 0, Max = 0;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		cnt -= 1LL * ((v[fi].size() == 1) + (v[se].size() == 1));
		v[fi].PB(se);
		v[se].PB(fi);
		cnt += 1LL * ((v[fi].size() == 1) + (v[se].size() == 1));
		Max = max(Max, max((LL)v[fi].size(), (LL)v[se].size()));
	}
	if(m == 0){
		cout << 3 << ' ' << 1LL * n * (n - 1) * (n - 2) / 6LL << endl;
		return 0;
	}
	if(Max == 1){
		cnt /= 2;
		cout << 2 << ' ' << 1LL * cnt * (cnt - 1) * 2LL + (n - 2 * cnt) * cnt << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		if(!mark[i]){
			Cnt[1] = 0;
			Cnt[0] = 1;
			dfs(i);
			ans += 1LL * Cnt[0] * (Cnt[0] - 1) / 2LL;
			ans += 1LL * Cnt[1] * (Cnt[1] - 1) / 2LL;
		}
	}
	cout << 1 << ' ' << ans << endl;
	return 0;
}
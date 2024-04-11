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
#define next nxt

const int maxn = 2e5 + 85 - 69;
LL s[maxn],
   a[maxn];
bool mark[maxn];
vector<LL> all;
vector<int> vec[maxn];
int next[maxn];
int n;
int ans = 1000000;

void dfs(int v, int st, int cnt = 0){
	if(mark[v]){
		smin(ans, n - cnt);
		return;
	}
	mark[v] = true;
	dfs(next[v] % n, st, cnt + 1);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], a[i + n] = a[i];
	for(int i = 0; i < n + n; i++)
		s[i + 1] = s[i] + a[i], all.PB(s[i + 1]);
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i <= n + n; i++){
		int id = lower_bound(all(all), s[i]) - all.begin();
		vec[id].PB(i);
		s[i] = id;
	}
	for(int i = 0; i < n; i++){
		auto it = upper_bound(all(vec[s[i]]), i);
		int id = *it;
		next[i] = id;
	}
	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i, i);
	cout << ans << endl;
	return 0;
}
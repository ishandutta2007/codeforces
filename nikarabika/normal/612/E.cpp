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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 1e6 + 85 - 69;
vector<int> vec[maxn];
vector<vector<int> > all[maxn];
bool mark[maxn];
int n, cnt, p[maxn], q[maxn];

void build(vector<int> &v){
	for(int i = 0; i < sz(v); i++)
		p[v[i]] = v[(i + ((sz(v) + 1) / 2)) % sz(v)];
	return;
}

void build(vector<int> &v, vector<int> &w){
	for(int i = 0; i < sz(v); i++){
		p[v[i]] = w[i];
		p[w[i]] = v[(i + 1) % sz(v)];
	}
	return;
}

void dfs(int v){
	mark[v] = true;
	vec[cnt].PB(v);
	if(!mark[q[v]])
		dfs(q[v]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> q[i];
		q[i]--;
	}
	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i), cnt++;
	for(int i = 0; i < cnt; i++)
		all[sz(vec[i])].PB(vec[i]);
	for(int i = 0; i <= n; i++){
		if(((i + 1) & 1) and (sz(all[i]) & 1)){
			cout << -1 << endl;
			return 0;
		}
		if(sz(all[i]) & 1)
			build(all[i][sz(all[i]) - 1]);
		for(int j = 0; j + 2 <= sz(all[i]); j += 2)
			build(all[i][j], all[i][j + 1]);
	}
	for(int i = 0; i < n; i++)
		cout << p[i] + 1 << ' ';
	cout << endl;
	return 0;
}
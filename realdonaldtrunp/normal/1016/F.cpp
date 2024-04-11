#include"bits/stdc++.h"
using namespace std;

int n;
int m;

vector<pair<int,long long int> > v[300002];
vector<pair<int,long long int> > path;
bool flag[300002];

bool dfs(int b,int pr=-1,long long int d=0){
	if (b == n - 1){
		flag[b] = true;
		path.push_back(make_pair(b,d) );
		return true;
	}
	for (auto go : v[b]){
		if (go.first == pr)continue;
		if (dfs(go.first, b, d + go.second)){
			flag[b] = true;
			path.push_back(make_pair(b, d));
			return true;
		}
	}
	return false;
}
int vis;
long long int dfs2(int b, int pr = -1,long long int d=0){
	long long int mx = d;
	vis++;
	int can = 0;
	for (auto go : v[b]){
		if (flag[go.first])continue;
		if (go.first == pr)continue;
		mx = max(mx, dfs2(go.first, b, d + go.second));
		can++;
	}
	if (can >= 2){
		vis = 100;
	}
	return mx;
}
vector<long long int> mx;

int main(){
	cin >> n >> m;
	for (int i = 1; i < n; i++){
		int a, b,w;
		scanf("%d%d%d", &a, &b,&w);
		a--;
		b--;
		assert(w);
		v[a].push_back(make_pair(b, w));
		v[b].push_back(make_pair(a, w));
	}
	dfs(0);
	reverse(path.begin(), path.end());
	long long int lim = LLONG_MAX;
	for (int i = 0; i < path.size(); i++){
		vis = 0;
		mx.push_back(dfs2(path[i].first));
		if (vis >= 3){
			lim = 0;
		}

	}
	long long int base = 0;
	long long int val = LLONG_MIN;
	long long int val2 = LLONG_MIN;
	for (int i = 0; i < path.size(); i++){
		base = path[i].second;
		if (val != LLONG_MIN){
			long long int tmp = val - base + mx[i];
			lim = min(lim, -tmp);
			
		}
		if (val2 != LLONG_MIN){
			if (mx[i]){
				long long int tmp = val2 - base + mx[i];
				lim = min(lim, -tmp);
			}
		}
		if (mx[i])val = max(val, base + mx[i]);
		if(i-1>=0)val = max(val, path[i-1].second + mx[i-1]);
		val2 = max(val2, path[i].second + mx[i]);
	}
	assert(lim < LLONG_MAX);
	while (m--){
		int x;
		scanf("%d", &x);
		if (x >= lim){
			printf("%lld\n", path.back().second);
		}
		else{
			printf("%lld\n", path.back().second - lim + x);
		}
	}
	return 0;
}
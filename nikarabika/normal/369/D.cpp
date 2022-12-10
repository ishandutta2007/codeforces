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

const int maxn = 3000 + 10;
int dis[maxn][maxn];
bool mark[maxn][maxn];
int a[maxn];
bool allzer[maxn],
	 hasone[maxn];
queue<pii> q;
int n, k, ans;

vector<pii> make_adj(pii v){
	vector<pii> ret;
	if(v.L >= n - 1 or v.R >= n)
		return ret;
	if(a[v.L]){
		if(!hasone[v.R])
			ret.PB({v.L, v.R + 1});
		if(!allzer[v.R])
			ret.PB({v.R + 1, v.R + 2});
	}
	if(a[v.L] != 100 and !allzer[v.R])
		ret.PB(MP(v.R, v.R + 1));
	return ret;
}

void bfs(void){
	memset(dis, 63, sizeof dis);
	dis[0][1] = 0;
	q.push(MP(0, 1));
	while(sz(q)){
		auto v = q.front();
		q.pop();
		if(dis[v.L][v.R] > k)
			break;
		ans++;
		pii adj[3];
		int sz = 0;
		if(v.L < n - 1 and v.R < n){
			if(a[v.L]){
				if(!hasone[v.R])
					adj[sz++] = {v.L, v.R + 1};
				if(!allzer[v.R])
					adj[sz++] = {v.R + 1, v.R + 2};
			}
			if(a[v.L] != 100 and !allzer[v.R])
				adj[sz++] = (MP(v.R, v.R + 1));
		}
		for(int i = 0; i < sz; i++){
			pii u = adj[i];
			if(!mark[u.L][u.R]){
				mark[u.L][u.R] = true;
				dis[u.L][u.R] = dis[v.L][v.R] + 1;
				q.push(u);
			}
		}
	}
	return;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	allzer[n] = true;
	for(int i = n - 1; i >= 0; i--){
		allzer[i] = allzer[i + 1] and (a[i] == 0);
		hasone[i] = hasone[i + 1] or (a[i] == 100);
	}
	bfs();
	printf("%d", ans);
	return 0;
}
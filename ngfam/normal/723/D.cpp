#include <bits/stdc++.h>

using namespace std;

const int N = 100;

char s[N][N], result[N][N];
int n, m, k, lab[N * N], cs[N][N], done[N][N], cur;
bool destroy = false;

int x[4] = {0, 0, -1, 1};
int y[4] = {-1, 1, 0, 0};

typedef pair<int,int> ii;

ii ver[N * N];

vector < ii > cell[N * N];

void dfs(int u, int v){
	done[u][v] = 1;

	if(u == 1 || v == 1 || u == n || v == m){
		destroy = true;	
	}

	cell[cur].push_back(ii(u, v));
	for(int i = 0; i < 4; ++i){
		int nu = u + x[i];
		int nv = v + y[i];

		if(done[nu][nv]) continue;
		if(s[nu][nv] != '.') continue;

		dfs(nu, nv);
	}
}

int dist(int u, int v, ii f){
 	return abs(u - f.first) + abs(v - f.second);
}

int howfar(int u, int v, int idx){
	int sz = cell[idx].size();
	
	int ans = n * m;
	for(int i = 0; i < sz; ++i){
		ans = min(ans, dist(u, v, cell[idx][i]));
	} 
	return ans;
}

void go(int u, int v, int i, int j){
	
	if(u == i && v == j) return;

	if(u < i) ++u;
	else if(u > i) --u;
	else if(v > j) --v;
	else if(v < j) ++v;

	result[u][v] = '.';
	go(u, v, i, j);

}

void makepath(int u, int v, int idx){		
	ii close = cell[idx][0];
	for(int i = 1; i < cell[idx].size(); ++i){
		if(dist(u, v, cell[idx][i]) < dist(u, v, close)){
			close = cell[idx][i];
		}
	}
	go(u, v, close.first, close.second);	
}

bool cmp(vector < int > a, vector < int > b){
	return a.size() < b.size();
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("0.inp", "r", stdin);
		freopen("0.out", "w", stdout);	
	#endif

	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%s", s[i] + 1);
	}

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(!done[i][j] && s[i][j] == '.'){
				++cur;
				destroy = false;
				dfs(i, j);
				if(destroy){
					cell[cur].clear();
					--cur;
				}
			}
		}
	}

//	cout << cur << endl;

	for(int i = 1; i <= cur; ++i){
		for(int j = i + 1; j <= cur; ++j){
			if(cell[i].size() > cell[j].size()){
				swap(cell[i], cell[j]);
			}
		}
	}
		
	int ans = 0;
	for(int i = 1; i <= cur - k; ++i){
		ans += cell[i].size();
		for(int u = 0; u < cell[i].size(); ++u){
			s[cell[i][u].first][cell[i][u].second] =  '*';
		}
	}
	//int ans = m * n;

       	printf("%d\n", ans);
	for(int i = 1; i <= n; ++i){
		printf("%s\n", s[i] + 1);
	}
}
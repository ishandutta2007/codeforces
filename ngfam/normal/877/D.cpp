#include <bits/stdc++.h>

using namespace std;

struct data{
	int u;
	int v;
	int d;
	int rem;
};

const int N = 1010;

const int dirx[5] = {0, 0, 0, 1, -1};
const int diry[5] = {0, 1, -1, 0, 0};

int n, m, k;
char a[N][N];
int path[N][N][5];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d%d", &n, &m, &k);

	for(int i = 1; i <= n; ++i){
		scanf("%s", a[i] + 1);
	}

	int frx, fry, tox, toy;
	scanf("%d%d%d%d", &frx, &fry, &tox, &toy);

	vector < data > current;

	current.push_back({frx, fry, 0, 0});



	memset(path, 60, sizeof path);
		path[frx][fry][0] = 0;

	int now = 0;

	while(true){
		++now;
		vector < data > nxt;
		for(int i = 0; i < current.size(); ++i){
			data x = current[i];

			if(x.u == tox && x.v == toy){
				printf("%d\n", path[tox][toy][x.d]);
				return 0;
			}

			if(x.rem > 0){
				int u = x.u + dirx[x.d];
				int v = x.v + diry[x.d];

				if(u > n || u < 1 || v > m || v < 1 || a[u][v] == '#') continue;

				if(path[u][v][x.d] == path[0][0][0]){
					path[u][v][x.d] = now - 1;
					current.push_back({u, v, x.d, x.rem - 1});
				}
			} 
		}

		for(int i = 0; i < current.size(); ++i){
			data x = current[i];
			for(int j = 1; j < 5; ++j){
				int u = x.u + dirx[j];
				int v = x.v + diry[j];

				if(u > n || u < 1 || v > m || v < 1 || a[u][v] == '#') continue;

				if(path[u][v][j] == path[0][0][0]){
					path[u][v][j] = now ;
					nxt.push_back({u, v, j, k - 1});
				}
			}
		}

		if(nxt.empty()){
			puts("-1");
			return 0;
		}
		current = nxt;
		
	}

	return 0;
}
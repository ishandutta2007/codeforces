#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
int f[N][5];
int path[5][5];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> n >> path[1][2] >> path[1][3] >> path[3][2];


	path[2][1] = path[1][2];

	path[3][1] = path[1][3];
	
	path[2][3] = path[3][2];

	memset(f, 60, sizeof f);

	f[1][1] = 0;

	for(int t = 1; t <= n; ++t){
		for(int x = 1; x <= 3; ++x){
			for(int y = 1; y <= 3; ++y){
				if(x == y) continue;


				f[t + 1][y] = min(f[t + 1][y], f[t][x] + path[x][y]);
			}
		}
	}


	cout << min(min(f[n][1], f[n][2]), f[n][3]);

	return 0;
}
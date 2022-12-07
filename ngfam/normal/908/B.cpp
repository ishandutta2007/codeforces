#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};

int n, m;
char a[N][N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> (a[i] + 1);

	string commands;
	cin >> commands;


	vector < int > perm;
	for(int i = 0; i < 4; ++i) perm.push_back(i);

	int ans = 0;

	do{
		int x = 0, y = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				if(a[i][j] == 'S') {
					x = i;
					y = j;
				}
			}
		}

		for(auto c : commands){
			int idx = c - '0';

			idx = perm[idx];

			x += dirx[idx];
			y += diry[idx];


			if(x < 1 || x > n || y < 1 || y > m || a[x][y] == '#') {
				break;
			}
			if(a[x][y] == 'E') {
				++ans;
				break;
			}
		}
	}
	while(next_permutation(perm.begin(), perm.end()));

	cout << ans;

	return 0;
}
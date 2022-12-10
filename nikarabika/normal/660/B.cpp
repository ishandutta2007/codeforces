//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 85 + 85 - 69;
bool mark[4][maxn];
int pos[4][maxn];
pii posm1[4 * maxn];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int j = 0; j < n; j++){
		pos[0][j] = 2 * j;
		pos[1][j] = 2 * n + 2 * j;
		pos[2][j] = 2 * n + 2 * j + 1;
		pos[3][j] = 2 * j + 1;
	}
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < n; j++)
			posm1[pos[i][j]] = {i, j};
	for(int i = 0; i < m; i++)
		mark[posm1[i].L][posm1[i].R] = true;
	int ord[4] = {1, 0, 2, 3};
	for(int j = 0; j < n; j++)
		for(int i = 0; i < 4; i++)
			if(mark[ord[i]][j])
				cout << pos[ord[i]][j] + 1 << ' ';
	cout << endl;
	return 0;
}
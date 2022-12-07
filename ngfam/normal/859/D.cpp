#include <bits/stdc++.h>
#define double long double

using namespace std;

const int N = 101;

int n, m;

double a[N][N];
double f[N][10];
bool done[N];

void build(int x, int l, int r){
	if(l == r){
		f[l][x] = 1;
		return;
	}


	int mid = (l + r) >> 1;
	build(x - 1, l, mid);
	build(x - 1, mid + 1, r);

	for(int u = l; u <= mid; ++u){
		for(int v = mid + 1; v <= r; ++v){
			f[u][x] += (f[u][x - 1] * f[v][x - 1] * a[u][v]);
			f[v][x] += (f[v][x - 1] * f[u][x - 1] * a[v][u]);
		}
	}

}

bool D[10][N][N][N];
double C[10][N][N][N];

double dfs(int t, int l, int r, int w){
	if(D[t][l][r][w]){
		return C[t][l][r][w];
	}
	if(l == r){
		return 0;
	}
	D[t][l][r][w] = 1;
	int mid = (l + r) >> 1;
	double ans = f[w][t] * (1 << (t - 1));
	if(mid < w){
		ans += dfs(t - 1, mid + 1, r, w);
		double sum = 0;
		for(int i = l; i <= mid; ++i){
			sum = max(sum, dfs(t - 1, l, mid, i));
		}
		ans += sum;
	}
	else{
		ans += dfs(t - 1, l, mid, w);
		double sum = 0;
		for(int i = mid + 1; i <= r; ++i){
			sum = max(sum, dfs(t - 1, mid + 1, r, i));
		}
		ans += sum;
	}
	return C[t][l][r][w] = ans;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> m;
	n = (1 << m);

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
			a[i][j] /= 100;
		}
	}
	cout << fixed << setprecision(12);

	build(m, 1, n);

	double Max = 0;

	for(int i = 1; i <= n; ++i){
		Max = max(Max, dfs(m, 1, n, i));
	}

	cout << Max;

	return 0;
}
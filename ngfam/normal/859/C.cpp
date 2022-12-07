#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int M = 101001;

int n;
int a[N];
int sum;
int f[N][2];

int solve(int x, int p){
	if(x > n){
		return 0;
	}

	if(f[x][p] != -1){
		return f[x][p];
	}

	if(p == 0){
		f[x][p] = 0;
		f[x][p] = max(f[x][p], solve(x + 1, 1) + a[x]);
		f[x][p] = max(f[x][p], solve(x + 1, 0));
	}
	else{
		f[x][p] = 1e9;
		f[x][p] = min(f[x][p], solve(x + 1, 0));
		f[x][p] = min(f[x][p], solve(x + 1, 1) + a[x]);
	}

	return f[x][p];
	
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	memset(f, -1, sizeof f);

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		sum += a[i];
	}

	cout << sum - solve(1, 0) << " " << solve(1, 0);

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 301;

int f[N][N][35][8];

int x[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int y[8] = {1, -1, 0, 0, -1, 1, -1, 1};
int ok[N][N], a[N], n;

void dfs(int u, int v, int i, int w){
	if(i > n) return;

//	cout << u - 150 << " " << v - 150 << " " << w << " " << i << endl;

	if(f[u][v][i][w]) return;
	f[u][v][i][w] = 1; 
	
	ok[u][v] = 1;



	for(int j = 1; j < a[i]; ++j){
		u += x[w]; v += y[w];
		ok[u][v] = 1;
	}

	
//	cout << u - 150 << " " << v - 150 << endl;

	///LEN
	if(w == 0){
	      dfs(u + 1, v + 1, i + 1, 5);
	      dfs(u - 1, v + 1, i + 1, 7);
	}

	///XUONG
	if(w == 1){
		dfs(u - 1, v - 1, i + 1, 6);
		dfs(u + 1, v - 1, i + 1, 4);
	}

	///TRAI
	if(w == 2){
		dfs(u - 1, v - 1, i + 1, 6);
		dfs(u - 1, v + 1, i + 1, 7);
	}

	///PHAI
	if(w == 3){
		dfs(u + 1, v + 1, i + 1, 5);
		dfs(u + 1, v - 1, i + 1, 4);
	}

	///TREN TRAI
	if(w == 7){
		dfs(u, v + 1, i + 1, 0);
		dfs(u - 1, v, i + 1, 2);
	}
	///TREN PHAI
	if(w == 5){
		dfs(u + 1, v, i + 1, 3);
		dfs(u, v + 1, i + 1, 0);
	}
	///DUOI TRAI
	if(w == 6){
		dfs(u - 1, v, i + 1, 2);
		dfs(u, v - 1, i + 1, 1);
	}
	///DUOI PHAI
	if(w == 4){
		dfs(u, v - 1, i + 1, 1);
		dfs(u + 1, v, i + 1, 3);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}

	dfs(150, 150, 1, 0);
	int ans = 0;

	for(int i = 0; i <= 300; ++i){
		for(int j = 0; j <= 300; ++j){
			//cout << ok[i][j] << " ";
			
			//if(ok[i][j]) if(i != 150 || j != 150) cout << "X";else cout << "X";
			//else cout << ".";
	        	ans += ok[i][j];
		}
	//	cout << endl;
	}
	cout << ans;
}
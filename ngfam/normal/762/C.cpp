#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int nxt[N][30], fix[N][30], f[N], g[N], suffix[N];
char a[N], b[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%s%s", a + 1, b + 1);
	
	int n = strlen(a + 1), m = strlen(b + 1);
	
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < 26; ++j){
			nxt[i][j] = nxt[i - 1][j];
		}
		nxt[i][a[i] - 'a'] = i;		
	}

	for(int i = n; i >= 1; --i){
		for(int j = 0; j < 26; ++j){
			fix[i][j] = fix[i + 1][j];
		}
		fix[i][a[i] - 'a'] = i;
	}

	int ans = m , lef = 0, rig = m;

	f[1] = fix[1][b[1] - 'a'];
	if(f[1] == 0) f[1] = n + 1;

//	cout << f[1] << endl;

	//cout << nxt[1][0] << endl;

//	cout << f[1] << endl;

	for(int i = 2; i <= m; ++i){
		if(f[i - 1] == n + 1) f[i] = n + 1;
		else f[i] = fix[f[i - 1] + 1][b[i] - 'a'];

		if(f[i] == 0) f[i] = n + 1;

	//	cout << f[i] << " ";
	}

	g[m] = nxt[n][b[m] - 'a'];

	//cout << endl;

	for(int i = m - 1; i >= 1; --i){
		if(g[i + 1] == 0) g[i] = 0;
		else g[i] = nxt[g[i + 1] - 1][b[i] - 'a'];
	//	cout << g[i] << " "; 
	}

	//cout << endl;



	for(int i = 0; i <= m; ++i){
		int fin = upper_bound(g + i + 1, g + m + 1, f[i]) - g;

//		cout << i << " " << fin << endl;

		if(f[i] != n + 1 && fin - i - 1 < ans){
			lef = i;
			rig = fin;
			ans = fin - i - 1;
	//	        cout << i << " " << lef << " " << rig << " " << g[fin] << endl;
		}
	}       	

	if(ans == m) printf("-");
	else{
		//cout << lef << " " << rig << endl;
		for(int i = 1; i <= lef; ++i){
			printf("%c", b[i]);
		}
		for(int i = rig; i <= m; ++i){
			printf("%c", b[i]);
		}
	}

	return 0;
}
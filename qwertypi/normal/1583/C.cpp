#include <bits/stdc++.h>

using namespace std;

char c[1000001];

bool dp[1000001];
bool st[1000001][20];
int n, m;
inline int id(int a, int b){
	return a * m + b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> c[i * m + j];
		}
	}
	for(int j = 0; j < m - 1; j++){
		for(int i = 0; i < n - 1; i++){
			if(c[id(i, j + 1)] == 'X' && c[id(i + 1, j)] == 'X') dp[j] = true;
		}
	}
	for(int i = 0; i < m - 1; i++){
		st[i][0] = dp[i];
	}
	for(int j = 1; j < 20; j++){
		for(int i = 0; i <= m - 1 - (1 << j); i++){
			st[i][j] = st[i][j - 1] | st[i + (1 << j - 1)][j - 1];
		}
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		if(l == r){
			cout << "YES" << endl;
			continue;
		}
		l--; r -= 2;
		int d = __lg(r - l + 1);
		cout << ((st[l][d] || st[r - (1 << d) + 1][d]) ? "NO" : "YES") << endl;
	}
}
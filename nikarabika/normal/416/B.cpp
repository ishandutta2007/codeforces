#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int m, n;
	cin >> m >> n;
	int r[m];
	int t[m][n];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin >> t[i][j];
	memset(r, 0, sizeof r);
	for(int j = 0; j < n; j++){
		int x = r[0];
		for(int i = 0; i < m; i++){
			r[i] = x + t[i][j];
			x = max(x + t[i][j], r[i + 1]);
		}
	}
	for(int i = 0; i < m; i++)
		cout << r[i] << ' ';
	cout << endl;
	return 0;
}
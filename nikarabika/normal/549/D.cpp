#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 10;
int a[maxn][maxn], ez[maxn][maxn];
int n, m, ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		char c;
		for(int j = 1; j <= m; j++){
			cin >> c;
			if(c == 'W')
				a[i][j] = 1;
			if(c == 'B')
				a[i][j] = -1;
		}
	}
	for(int j = m; j >= 1; j--){
		for(int i = n; i >= 1; i--){
			ez[i][j] = ez[i + 1][j] + ez[i][j + 1] - ez[i + 1][j + 1];
			if(ez[i][j] != a[i][j]){
				ans++;
				ez[i][j] = a[i][j];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3 + 85 - 69;
int inv[maxn][maxn];
int a[maxn], n, sum;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int Max = 0, cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			inv[i][j] = inv[i][j - 1] + (a[j] > a[i]);
		sum += inv[i][i];
		for(int j = 1; j < n; j++) if(a[j] > a[i]){
			int x1 = inv[j][i] - inv[j][j],
				x3 = i - j - 1 - (inv[i][i] - inv[i][j]);
			int x2 = i - j - 1 - x1 - x3;
			if(x2 > Max)
				Max = x2, cnt = 0;
			if(x2 == Max)
				cnt++;
		}
	}
	cout << sum - 2 * Max - 1 << ' ' << cnt << endl;
	return 0;
}
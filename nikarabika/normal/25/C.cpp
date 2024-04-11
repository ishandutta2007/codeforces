#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 3e2 + 85 - 75;
int n, k;
LL d[maxn][maxn];
LL sum = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> d[i][j];
			if(i < j)
				sum += d[i][j];
		}
	}
	cin >> k;
	while(k--){
		LL fi, se, th;
		cin >> fi >> se >> th;
		if(th >= d[fi][se]){
			cout << sum << ' ';
			continue;
		}
		sum = sum - d[fi][se] + (d[fi][se] = d[se][fi] = th);
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				d[i][j] = min(d[i][j], min(d[i][fi] + d[fi][se] + d[se][j], d[i][se] + d[fi][se] + d[fi][j]));
				sum -= d[j][i];
				sum += d[i][j];
				d[j][i] = d[i][j];
			}
		}
		cout << sum << ' ';
	}
	cout << endl;
	return 0;
}
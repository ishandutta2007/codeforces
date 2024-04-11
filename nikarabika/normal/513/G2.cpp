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

const int maxn = 30;
LD dp[2][maxn][maxn];
int n, K, p[maxn];

int convert(int idx, int l, int r){
	if(l > idx or r < idx)
		return idx;
	return l + r - idx;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> K;
	for(int i = 0; i < n; i++)
		cin >> p[i];
	int cur = 0, pre = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(p[i] > p[j])
				dp[cur][i][j] = 1;
	LD makh = (LD)n * LD(n + 1) / 2.;
	for(int k = 0; k < K; k++){
		swap(pre, cur);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				dp[cur][i][j] = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				for(int ii = 0; ii < n; ii++)
					for(int jj = ii; jj < n; jj++){
						int idi = convert(i, ii, jj),
							idj = convert(j, ii, jj);
						dp[cur][idi][idj] += dp[pre][i][j] / makh;
					}
			}
	}
	LD ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			ans += dp[cur][i][j];
	cout.precision(15);
	cout << fixed << ans << endl;
	return 0;
}
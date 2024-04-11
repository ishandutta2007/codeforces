#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3;
int n;
int dp[maxn * 4], a[maxn * 4], ans;

void dfs(int id = 1){
	if(id >= (1 << n))
		return;
	int L = id * 2,
		R = L + 1;
	dfs(L);
	dfs(R);
	int X = dp[L] + a[L],
		Y = dp[R] + a[R];
	ans += abs(X - Y);
	dp[id] = max(X, Y);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 2; i < (1 << (n + 1)); i++)
		cin >> a[i];
	dfs();
	cout << ans << endl;
	return 0;
}
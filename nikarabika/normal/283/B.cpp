//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;

const int maxn = 2e5 + 85 - 69;
LL dp[2][maxn], a[maxn];
int mark[2][maxn];
int n;

void make_invalid(bool ty, int v){
	dp[ty][v] = -1;
	return;
}

void dfs(bool ty, int v){
	mark[ty][v] = 1;
	dp[ty][v] = a[v];
	if(!ty){
		int u = v + a[v];
		if(u == 0){
			make_invalid(ty, v);
			goto bokhor;
		}
		if(u < 0 or u >= n)
			goto bokhor;
		if(!mark[!ty][u])
			dfs(!ty, u);
		if(mark[!ty][u] == 1 or dp[!ty][u] == -1){
			make_invalid(ty, v);
			goto bokhor;
		}
		dp[ty][v] += dp[!ty][u];
	}
	else{
		int u = v - a[v];
		if(u == 0){
			make_invalid(ty, v);
			goto bokhor;
		}
		if(u < 0 or u >= n)
			goto bokhor;
		if(!mark[!ty][u])
			dfs(!ty, u);
		if(mark[!ty][u] == 1 or dp[!ty][u] == -1){
			make_invalid(ty, v);
			goto bokhor;
		}
		dp[ty][v] += dp[!ty][u];
	}
bokhor:
	mark[ty][v] = 2;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++){
		if(!mark[1][i])
			dfs(1, i);
	}
	for(LL i = 1; i < n; i++)
		cout << ((dp[1][i] == -1) ? -1 : i + dp[1][i]) << '\n';
	return 0;
}
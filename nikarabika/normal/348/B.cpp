#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
typedef long long int LL;
typedef pair<LL, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 100000 + 100;
const LD maxval = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
vector<int> v[maxn];
LL dp[maxn], a[maxn];
int n;
LL sum;

LL lcm(LL x, LL y){
	if(x == 0 or y == 0)
		return 0;
	x /= __gcd(x, y);
	LD xd = x, yd = y;
	if(x >= maxval / y)
		return maxval;
	return x * y;
}

void dfs(int x, int par = -1){
	dp[x] = 1;
	LL Min = maxval, c = 0;
	for(int i = 0; i < v[x].size(); i++){
		if(v[x][i] != par){
			dfs(v[x][i], x);
			if(a[v[x][i]] == 0){
				a[x] = 0;
				dp[x] = 1;
				return;
			}
			dp[x] = lcm(dp[v[x][i]], dp[x]);
			c++;
			Min = min(Min, a[v[x][i]]);
		}
	}
	if(c < 1)
		return;
	a[x] = c * (dp[x] * (Min / dp[x]));
	dp[x] *= c;
	if(!dp[x])
		dp[x] = 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	LL sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i > 1) sum += a[i];
	}
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		v[fi].PB(se);
		v[se].PB(fi);
	}
	

	dfs(1);
	cout << sum - a[1] << endl;
	
	return 0;
}
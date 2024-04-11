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

//dp[i][j][k] = minimum effort to have j'th place between first i people and point k

const int maxn = 200 * 1000 + 85 - 69;
int order[maxn], p[maxn], e[maxn];
int mask, n, k;

bool cmp(int i, int j){
	if(p[i] != p[j])
		return p[i] > p[j];
	if(i != n and j != n)
		return true;
	if(i == n)
		return (mask >> j) & 1;
	return !((mask >> i) & 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> p[i] >> e[i];
		order[i] = i;
	}
	order[n] = n;
	LL ans = 1000LL * 1000 * 1000;
	ans *= ans;
	for(mask = 0; mask < (1 << n); mask++){
		LL sum = 0;
		for(int i = 0; i < n; i++){
			if((mask >> i) & 1)
				sum += e[i];
			else
				p[i]++;
		}
		p[n] = __builtin_popcount(mask);
		sort(order, order + n + 1, cmp);
		for(int i = 0; i < k; i++)
			if(order[i] == n)
				smin(ans, sum);
		for(int i = 0; i < n; i++)
			if(!((mask >> i) & 1))
				p[i]--;
	}
	cout << (ans == 1e18 ? -1 : ans) << endl;
	return 0;
}
//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
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

const int maxn = 6, maxm = 40;
int dp[729][maxm], num[729][maxn];
int P[maxn + 1];
int n, m;

void preprocess(void){
	P[0] = 1;
	for(int i = 1; i <= maxn; i++)
		P[i] = P[i - 1] * 3;
	for(int mask = 0; mask < P[maxn]; mask++){
		int tmp = mask;
		for(int i = 0; i < maxn; i++, tmp /= 3)
			num[mask][i] = tmp % 3;
	}
	return;
}

bool isvalid(int mask){
	for(int i = 0; i < n; i++){
		if(num[mask][i] == 2){
			if(i - 1 >= 0 and num[mask][i - 1] == 1)
				return false;
			if(i + 1 < n and num[mask][i + 1] == 1)
				return false;
		}
	}
	return true;
}

bool isvalid2(int mask){
	if(!isvalid(mask))
		return false;
	for(int i = 0; i < n; i++)
		if(num[mask][i] == 1)
			return false;
	return true;
}

bool match(int mask1, int mask2){
	for(int i = 0; i < n; i++)
		if(num[mask2][i] == 1 and num[mask1][i] != 2)
			return false;
	for(int i = 0; i < n; i++)
		if(num[mask1][i] == 0){
			bool an = false;
			if(i - 1 >= 0 and num[mask1][i - 1] == 2)
				an = true;
			if(i + 1 < n and num[mask1][i + 1] == 2)
				an = true;
			if(num[mask2][i] == 2)
				an = true;
			if(!an)
				return false;
		}
	for(int i = 0; i < n; i++)
		if(num[mask1][i] == 1){
			bool an = false;
			if(i - 1 >= 0 and num[mask1][i - 1] == 2)
				an = true;
			if(i + 1 < n and num[mask1][i + 1] == 2)
				an = true;
			if(num[mask2][i] == 2)
				an = true;
			if(an)
				return false;
		}
	return true;
}

int freeof(int mask){
	int ret = 0;
	for(int i = 0; i < n; i++)
		ret += num[mask][i] != 2;
	return ret;
}

int DP(int mask, int col){
	if(col == m){
		if(mask == 0)
			return 0;
		return -2;
	}
	if(dp[mask][col] != -1)
		return dp[mask][col];
	int mx = -5;
	for(int mask2 = 0; mask2 < P[n]; mask2++)
		if(isvalid(mask2) and match(mask, mask2))
			smax(mx, DP(mask2, col + 1));
	if(mx == -2)
		return dp[mask][col] = -2;
	return dp[mask][col] = mx + freeof(mask);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	preprocess();
	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	if(n > m)
		swap(n, m);
	int ans = -1;
	for(int mask = 0; mask < P[n]; mask++)
		if(isvalid2(mask))
			smax(ans, DP(mask, 0));
	cout << ans << endl;
	return 0;
}
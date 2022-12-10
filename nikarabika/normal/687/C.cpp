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

const int maxn = 501;
bool dp[2][maxn][maxn];
int n, K;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> K;
	dp[1][0][0] = true;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		int cur = i&1,
			pre = i&1^1;
		for(int j = 0; j <= K; j++)
			for(int k = 0; k <= j; k++){
				dp[cur][j][k] = dp[pre][j][k];
				if(j >= x) dp[cur][j][k] |= dp[pre][j - x][k];
				if(k >= x) dp[cur][j][k] |= dp[pre][j - x][k - x];
			}
	}
	vector<int> vec;
	for(int i = 0; i <= K; i++)
		if(dp[n&1^1][K][i])
			vec.PB(i);
	cout << sz(vec) << '\n';
	for(auto val : vec)
		cout << val << ' ';
	cout << endl;
	return 0;
}
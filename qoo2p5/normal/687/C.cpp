#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()

const int INF = 1e9;
const ll LINF = 1e18;

const int N = 505;

int n, k;
int c[N];
bool dp[N][N];
bool ndp[N][N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
		
	dp[0][0] = 1;
	
	for (int i = 0; i < n; i++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				ndp[x][y] = dp[x][y];
			}
		}
		
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (!dp[x][y]) continue;
				
				{
					int nx = x;
					int ny = y + c[i];
					if (nx < N && ny < N) ndp[nx][ny] = 1;
				}
				
				{
					int nx = x + c[i];
					int ny = y + c[i];
					if (nx < N && ny < N) ndp[nx][ny] = 1;
				}
			}
		}
		
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				dp[x][y] = ndp[x][y];
			}
		}
	}
	
	vector<int> ans;
	for (int x = 0; x <= k; x++) {
		if (dp[x][k]) ans.push_back(x);
	}
	
	printf("%d\n", sz(ans));
	for (int i : ans) printf("%d ", i);
	printf("\n");
	
	return 0;
}
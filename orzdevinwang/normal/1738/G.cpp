#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1007;
int n, k, vis[N][N], dp[N][N];
char s[N][N];
bool go[N][N];
vector < pair < int, int > > prs[N];
void Main() {
	cin >> n >> k;
	L(i, 1, n) cin >> (s[i] + 1);
	L(i, 0, n + 1) 
		L(j, 0, n + 1) 
			dp[i][j] = 0, go[i][j] = false;
	
	L(i, 1, n) L(j, 1, n) vis[i][j] = s[i][j] == '0';
	L(d, 1, n * 2) if(d < k || d > n * 2 - k) {
		L(i, 1, n) {
			int j = d - (n - i);
			if(1 <= j && j <= n) vis[i][j] = true;
		}
	}
	
	L(i, 1, n) {
		L(j, 1, n) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if(vis[i][j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}
	if(dp[n][n] >= k) {
		cout << "No\n";
		return ;
	}
	L(i, 1, k - 1) prs[i].clear();
	L(d, 1, n * 2) {
		L(i, 1, n) {
			int j = d - (n - i);
			if(j < 1 || j > n) continue;
			if(d < k || d > n * 2 - k + 1) {
				go[i][j] = true;
			} else {
				if(vis[i][j]) prs[dp[i][j]].push_back({i, j}); 
			}
		}
	}
	L(i, 1, k - 1) {
		int x = n - k + 1 + i, y = i;
		prs[i].push_back({y, x}); 
		for(auto u : prs[i]) {
			assert(x >= u.first && y <= u.second);
			while(x > u.first || y < u.second) {
				if(x > u.first && !go[x - 1][y]) {
					--x;
				} else {
					++y;
					assert(y <= u.second);
				}
				assert(!go[x][y]);
				go[x][y] = true;
			}
		}	
	} 
	cout << "Yes\n";
	L(i, 1, n) {
		L(j, 1, n) {
			cout << go[i][j];
		}
		cout << '\n';
	}
}
int main() {
//	freopen("data.in", "r", stdin);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}
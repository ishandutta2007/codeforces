#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> t;
	while(t--) {
		string str;
		cin >> str;
		int n = str.size();
		str = " " + str;

		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, n)));
		dp[0][0][0] = 0;

		for(int i = 0; i < n; i++) {
			for(int a = 0; a < 2; a++) {
				for(int b = 0; b < 2; b++) {
					for(int c = 0; c < 2; c++) {
						int cost = 1 - c;
					
						if(i > 0 && b == 1 && str[i + 1] == str[i]) {
							if(c == 1)
								cost = n;
							else
								cost = 1;
						}
						if(i > 1 && a == 1 && str[i + 1] == str[i - 1]) {
							if(c == 1)
								cost = n;
							else
								cost = 1;
						}
						
						dp[i + 1][b][c] = min(dp[i + 1][b][c], dp[i][a][b] + cost);
					}
				}
			}
		}

		int ans = n;
		for(int a = 0; a < 2; a++) {
			for(int b = 0; b < 2; b++) {
				ans = min(ans, dp[n][a][b]);
			}
		}
		cout << ans << "\n";
	}

	
    return 0;
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;



int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
   	int i, j, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<string> digits = {"1110111", "0010010", "1011101",
    						 "1011011", "0111010", "1101011",
    						 "1101111", "1010010", "1111111",
    						 "1111011"};

    cin >> n >> k;
    vector<string> table(n);
    vector<vector<int>> match(n, vector<int>(10, -1));
    for(i = 0; i < n; i++) {
    	cin >> table[i];
    	for(int d = 0; d < 10; d++) {
    		bool bad = false;
    		int cnt = 0;
    		for(j = 0; j < 7 && bad == false; j++) {
    			if(table[i][j] > digits[d][j]) {
    				bad = true;
    			}
    			if(table[i][j] != digits[d][j]) {
    				cnt++;
    			}
    		}
    		if(bad == false) {
    			match[i][d] = cnt;
    		}
    	}
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    vector<vector<int>> mx_digit(n + 1, vector<int>(k + 1));

    dp[n][0] = true;
    for(i = n; i > 0; i--) {
    	for(j = 0; j <= k; j++) {
    		if(dp[i][j] == false) continue;

    		for(int d = 0; d < 10; d++) {
    			int cur = match[i - 1][d];
    			if(cur != -1 && j + cur <= k) {
    				dp[i - 1][j + cur] = true;
    				mx_digit[i - 1][j + cur] = max(mx_digit[i - 1][j + cur], d);
    			}
    		}
    	}
    }

    if(dp[0][k] == false) {
    	cout << -1;
    	return 0;
    }

   	i = 0;
   	j = k;
   	while(i < n) {
   		int cur = mx_digit[i][j];
   		cout << cur;
   		j -= match[i][cur];
   		i++;
   	}

   	assert(i == n && j == 0);
    
    return 0;
}
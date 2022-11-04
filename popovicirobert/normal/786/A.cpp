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
   	int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    
    vector<vector<int>> arr(2);
    for(int t = 0; t < 2; t++) {
    	int sz;
    	cin >> sz;
    	while(sz--) {
    		int x;
    		cin >> x;
    		arr[t].push_back(x);
    	}
    }

    vector<vector<int>> deg(2, vector<int>(n, 0));
    for(int t = 0; t < 2; t++) {
    	for(i = 0; i < n; i++) {
    		deg[t][i] = (int)arr[t].size();
    	}
    }
    vector<vector<int>> dp(2, vector<int>(n, -1));
    dp[0][0] = dp[1][0] = 0;

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    Q.push({1, 0});

    while(Q.size()) {
    	int t, nod;
    	tie(t, nod) = Q.front();
    	Q.pop();
    	for(auto it : arr[t ^ 1]) {
    		int cur = (nod - it + n) % n;
    		deg[t ^ 1][cur]--;
    		if(dp[t][nod] == 0) {
    			if(dp[t ^ 1][cur] == -1) {
    				dp[t ^ 1][cur] = 1;
    				Q.push({t ^ 1, cur});
    			}
    		}
    		else if(deg[t ^ 1][cur] == 0 && dp[t ^ 1][cur] == -1) {
    			Q.push({t ^ 1, cur});
    			dp[t ^ 1][cur] = 0;
    		}
    	}
    }

    for(int t = 0; t < 2; t++) {
    	for(i = 1; i < n; i++) {
    		if(dp[t][i] == 1) {
    			cout << "Win ";
    		}
    		if(dp[t][i] == 0) {
    			cout << "Lose ";
    		}
    		if(dp[t][i] == -1) {
    			cout << "Loop ";
    		} 
    	}
    	cout << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;
const int inf = 1e9 + 7;



signed main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

 	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);


    int t;
    cin >> t;
    while(t--) {
    	int n, k;
    	string s;
    	cin >> n >> k >> s;

    	vector<vector<int>> cnt(k, vector<int>(26));
    	vector<int> sum(k);
    	for(int i = 0;i < n;i++) {
    		int j = min(i % k, k - i % k - 1);

    		sum[j]++;
    		cnt[j][s[i] - 'a']++;
    	}

    	/*for(int i = 0;i < k;i++) {
    		cout << sum[i] << " ";
    		for(int j = 0;j < 2;j++) cout << cnt[i][j] << " ";
    		cout << '\n';
    	}
    	cout << '\n';*/


    	int res = 0;
    	for(int i = 0;i < k;i++) {
    		res += sum[i];
    		int Max = 0;
    		for(int j : cnt[i]) Max = max(Max, j);
    		res -= Max;
    	}

    	cout << res << '\n';
    }

}
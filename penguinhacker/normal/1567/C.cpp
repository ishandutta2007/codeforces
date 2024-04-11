#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> d;
		int x=n;
		while(x) {
			d.push_back(x%10);
			x/=10;
		}
		vector<vector<int>> dp(d.size()+1, vector<int>(4));
		dp[0][0]=1;
		for (int i=0; i<d.size(); ++i) {
			for (int j=0; j<4; ++j) {
				if (!dp[i][j])
					continue;
				int nm=j>>1;
				bool b=j&1;
				for (int d1=0; d1<10; ++d1)
					for (int d2=0; d2<10; ++d2) {
						int cur=d1+d2+b;
						if (cur%10!=d[i])
							continue;
						dp[i+1][nm+(cur>=10?2:0)]+=dp[i][j];
					}
			}
		}
		cout << dp[d.size()][0]-2 << "\n";
	}
	return 0;
}
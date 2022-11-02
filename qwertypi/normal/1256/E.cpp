#include <bits/stdc++.h>
#define int long long
#define INF (1LL << 60)
using namespace std;


int dp[200001][6]; // i th person, j th of team
int track[200001];
int Ans[200000];
vector<pair<int, int>> player;
int32_t main(){
	for(int i = 1; i <= 200000; i++){
		fill(dp[i], dp[i] + 6, INF);
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		player.push_back({v, i});
	}
	sort(player.begin(), player.end());
	for(int i = 0; i < n; i++){
		for(int j = 1; j < 6; j++){
			if(i + 1 >= j){
				dp[i + 1][j] = min(dp[i + 1][j], dp[i + 1 - j][0] + player[i].first - player[i-j+1].first);
			}
		}
		for(int j = 3; j < 6; j++){
			if(dp[i + 1][j] < dp[i + 1][0]){
				dp[i + 1][0] = dp[i + 1][j];
				track[i + 1] = j;
			}
		}
	}
	vector<int> ans;
	int curPos = n;
	while(curPos != 0){
		ans.push_back(track[curPos]);
		curPos -= track[curPos];
	}
	cout << dp[n][0] << ' ' << ans.size() << endl;
	curPos = 0;
	for(int i = (int) ans.size() - 1; i >= 0; i--){
		for(int j = curPos; j < curPos + ans[i]; j++){
			Ans[player[j].second] = i + 1;
		}
		curPos += ans[i];
	}
	for(int i = 0; i < n; i++){
		cout << Ans[i] << ' ';
	}
}
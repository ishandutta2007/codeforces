#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second
#pragma optimize("Ofast")
typedef long long ll;
using namespace std;

int cnt[20];
ll cnt_2[20][20]; // i after j
ll dp[1048576];
int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int v;
		cin >> v;
		v--;
		for(int i=0;i<20;i++){
			cnt_2[v][i] += cnt[i];
		}
		cnt[v]++;
	}
	for(int m = 0; m < (1 << 20); m++){
		dp[m] = (1LL << 60);
		int sum = 0;
		for(int i = 0; i < 20; i++){
			if((1 << i) & m){
				ll res = (m - (1 << i) == 0) ? 0 : dp[m - (1 << i)];
				for(int j = 0; j < 20; j++){
					res += cnt_2[i][j] * (((1 << j) & m) > 0) * (i != j);
				}
				dp[m] = min(dp[m], res);
			}
		}
	}
	cout << dp[(1 << 20) - 1];
	return 0;
}
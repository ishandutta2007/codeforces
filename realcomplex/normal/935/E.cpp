#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

const int N = 10005;
const int M = 105;
vector<int> T[N];

int ct = 1;

int dp[N][M][2];

int dd = 1;
int add, rem;

void dfs(int u){
	for(auto x : T[u])
		dfs(x);
	if(T[u].empty())	
		return;
	int ch1 = T[u][0];
	int ch2 = T[u][1];
	if(dd == 0){ // add is less
		for(int v1 = 0; v1 <= add; v1 ++ ){
			for(int v2 = 0; v2 <= add; v2 ++ ){
				if(v1 + v2 > add)
					continue;
				if(v1 + v2 + 1 <= add){
					dp[u][v1 + v2 + 1][1] = max(dp[u][v1 + v2 + 1][1], dp[ch1][v1][1] + dp[ch2][v2][1]);
					dp[u][v1 + v2 + 1][0] = min(dp[u][v1 + v2 + 1][0], dp[ch1][v1][0] + dp[ch2][v2][0]);
				}
				if(v1 + v2 <= add){
					dp[u][v1 + v2][0] = min(dp[u][v1 + v2][0], dp[ch1][v1][0] - dp[ch2][v2][1]);
					dp[u][v1 + v2][1] = max(dp[u][v1 + v2][1], dp[ch1][v1][1] - dp[ch2][v2][0]);
				}
			}
		}
	}
	else{
		for(int v1 = 0; v1 <= rem; v1 ++ ){
			for(int v2 = 0; v2 <= rem; v2 ++ ){
				if(v1 + v2 > rem)
					continue;
				if(v1 + v2 + 1 <= rem){
					dp[u][v1 + v2 + 1][0] = min(dp[u][v1 + v2 + 1][0], dp[ch1][v1][0] - dp[ch2][v2][1]);
					dp[u][v1 + v2 + 1][1] = max(dp[u][v1 + v2 + 1][1], dp[ch1][v1][1] - dp[ch2][v2][0]);
				}
				if(v1 + v2 <= rem){
					dp[u][v1 + v2][0] = min(dp[u][v1 + v2][0], dp[ch1][v1][0] + dp[ch2][v2][0]);
					dp[u][v1 + v2][1] = max(dp[u][v1 + v2][1], dp[ch1][v1][1] + dp[ch2][v2][1]);
				}
			}
		}
	}
}

int main(){
	fastIO;
	int n;
	string t;
	cin >> t;
	if(t.size() == 1){
		cout << t[0] << "\n";
		return 0;
	}
	n = t.size();
	cin >> add >> rem;
	dd = add > rem;
	for(int i = 0 ; i < N; i ++ ){
		for(int j = 0; j < M ; j ++ ){
			dp[i][j][0] = (int)1e9 + 9;
			dp[i][j][1] = -(int)1e9 + 9;
		}
	}
	vector<int> tt;
	int las;
	for(char y : t){
		if(y == '('){
			if(!tt.empty()){
				las = tt.back();
				T[las].push_back(ct);
			}
			tt.push_back(ct);
			++ ct;
		}
		else if(y == ')'){
			tt.pop_back();
		}
		else if(y >= '1' and y <= '9'){
			las = tt.back();
			T[las].push_back(ct);
			dp[ct][0][0] = y - '0';
			dp[ct][0][1] = y - '0';
			++ ct;
			
		}
	}
	dfs(1);
	cout << dp[1][min(add, rem)][1] << "\n";
	return 0;
}
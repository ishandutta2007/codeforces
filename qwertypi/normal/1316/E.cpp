#include <bits/stdc++.h>
#define IOS cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
#define int long long
using namespace std;
int n, p, k;
int A[100000];
int B[100000][7];
int dp[100001][1 << 7];
int f[1 << 7];
int sos[100001];
int g(int i){
	int res = 0;
	while(i){
		if(i % 2){
			res++;
		}
		i /= 2;
	}
	return res;
}
 
void init(){
	for(int i = 0; i < (1 << 7); i++){
		f[i] = g(i);
	}
}
 
vector<pair<int, int>> C;
int32_t main(){
	IOS;
	init();
	cin >> n >> p >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		C.push_back({A[i], i});
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < p; j++){
			cin >> B[i][j];
		}
	}
	sort(C.begin(), C.end(), [](pair<int, int> a, pair<int, int> b){
		return a.first > b.first;
	});
	
	for(int i = 0; i < n; i++){
		sos[i] = C[i].second;
	}
	for(int i = 0; i < (1 << p) - 1; i++){
		dp[0][i] = -(1LL << 60);
	}
	for(int x = 0; x < n; x++){
		int i = sos[x];
		for(int j = 0; j < (1 << p); j++){
			if(x - (p - f[j]) < k){
				dp[x + 1][j] = dp[x][j] + A[i];
			}else{
				dp[x + 1][j] = dp[x][j];
			}
			for(int y = 0; y < p; y++){
				if(j & (1 << y)){
					dp[x + 1][j - (1 << y)] = max(dp[x + 1][j - (1 << y)], dp[x][j] + B[i][y]);
				}
			}
		}
	}
	cout << dp[n][0] << endl;
}
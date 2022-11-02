#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int A[200001];
bool no[200001];

int dp[200001];
int K[200001];
int main(){
	int n, p;
	cin >> n >> p;
	for(int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n);
	set<int> S;
	for(int i = 0; i < n; i++) S.insert(A[i]);
	for(int i = 0; i < n; i++){
		int v = A[i];
		while(v > 0){
			if(v % 2 == 1){
				v /= 2;
			}else{
				if(v % 4 == 2){
					break;
				}else{
					v /= 4;
				}
			}
			if(S.find(v) != S.end()){
				no[i] = true;
				break;
			}
		}
	}
	
	vector<int> v;
	for(int i = 0; i < n; i++){
		if(!no[i]) v.push_back(A[i]);
	}
	n = v.size();
	for(int i = 0; i < n; i++){
		A[i] = v[i];
	}
	int k = 0;
	for(int i = 0; i < n; i++){
		while((1 << k) <= A[i]) k++;
		K[k - 1]++;
	}
	for(int i = 0; i < 30; i++){
		dp[i] = K[i];
	}
	/*
	for(int i = 0; i < 30; i++){
		cout << dp[i] << ' ';
	}
	cout << endl;
	*/
	for(int i = 1; i <= p; i++){
		if(i >= 1) dp[i] = (dp[i - 1] + dp[i]) % mod;
		if(i >= 2) dp[i] = (dp[i - 2] + dp[i]) % mod;
	}
	/*
	for(int i = 0; i < 30; i++){
		cout << dp[i] << ' ';
	}
	cout << endl;*/
	int ans = 0;
	for(int i = 0; i < p; i++){
		ans = (ans + dp[i]) % mod;
	}
	cout << ans << endl;
}
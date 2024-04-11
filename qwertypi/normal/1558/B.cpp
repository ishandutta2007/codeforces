#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dp[4000001];
int s[4000001];
int lp[4000001];

void cp(int n){
	for(int i = 2; i <= n; i++){
		if(lp[i] != 0) continue;
		lp[i] = i;
		for(int j = i * i; j <= n; j += i){
			if(lp[j] == 0) lp[j] = i;
		}
	}
}

vector<int> pf(int n){
	vector<pair<int, int>> cnt;
	vector<int> res = {1}, temp;
	int prev = -1, c = 0;
	while(n != 1){
		int v = lp[n];
		if(prev != v){
			if(prev != -1) cnt.push_back({prev, c});
			prev = v, c = 1;
		}else{
			c++;
		}
		n /= v;
	}
	cnt.push_back({prev, c});
	for(auto i : cnt){
		for(auto j : res){
			int _j = j;
			for(int k = 0; k <= i.second; k++){
				temp.push_back(_j);
				_j *= i.first;
			}
		}
		swap(temp, res);
		temp.clear();
	} 
	res.pop_back();
	return res;
}

int32_t main(){
	int n, m;
	cin >> n >> m;
	cp(n);
	dp[1] = 1;
	s[1] = 1;
	int k = 0;
	for(int i = 2; i <= n; i++){
		dp[i] = i + s[i - 2];
		dp[i] %= m;
		for(auto j : pf(i)){
			if(j != 1) k += (dp[j] - dp[j - 1]), k = (k % m + m) % m;;
		}
		dp[i] = (dp[i] + k) % m;
		k += dp[i] - dp[i - 1]; 
		k = (k % m + m) % m;
		s[i] = (s[i - 1] + dp[i]) % m;
	}
	cout << dp[n] << endl;
}
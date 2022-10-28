#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
bitset < N > dp;
int brute(int n){
	dp.reset();
	dp[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		dp = (dp << 1) | (dp << 5) | (dp << 10) | (dp << 50);
	}
	return dp.count();
}
long long solve(int n){
	if(n < 1000){
		return brute(n);
	}
	long long res = 0;
	set < long long > s;
	s.clear();
	for(int i = 0 ; i <= 50 ; ++i){
		for(int j = 0 ; j <= 50 ; ++j){
			long long val = i * 10LL + j * 5LL + (n - i - j) * 1LL;
			if(val >= n && val <= n + 50LL){
				s.insert(val);
			}
		}
	}
	for(int i = 0 ; i <= 60 ; ++i){
		for(int j = 0 ; j <= 60 ; ++j){
			for(int k = 0 ; k <= 60 ; ++k){
				long long val = 1LL * i + 5LL * j + 10LL * k + 50LL * (n - i - j - k);
				if(val >= n * 50LL - 1000LL && val <= n * 50LL){
					s.insert(val);
				}
			}
		}
	}
	res += s.size();
	res += n * 50LL - 1000LL - 1LL - (n + 50LL + 1LL) + 1LL;
	return res;
}
int main(){
	int n;
	cin >> n;
	cout << solve(n) << endl;
}
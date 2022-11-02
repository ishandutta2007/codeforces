#include <bits/stdc++.h>

#define int long long
using namespace std;

int mod = 1e9 + 7;
int A[500000];
int cnt[60];
int pow2[61];
int _A[60], _B[60];
void sub(){
	for(int i = 0; i < 60; i++){
		cnt[i] = 0;
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 60; j++){
			if(A[i] & (1LL << j)){
				cnt[j]++;
			}
		}
	}
	
	for(int i = 0; i < 60; i++){
		_A[i] = (pow2[i] * n) % mod;
		_B[i] = (pow2[i] * cnt[i]) % mod;
	}
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		int P = 0, Q = 0;
		for(int j = 0; j < 60; j++){
			if(A[i] & (1LL << j)){
				Q += _A[j];
				P += _B[j];
			}else{
				Q += _B[j];
			}
		}
		P %= mod;
		Q %= mod;
		int res = (P * Q) % mod;
		ans = (ans + res) % mod;
	}
	cout << ans << endl;
}

int32_t main(){
	pow2[0] = 1;
	for(int i = 0; i < 60; i++){
		pow2[i + 1] = (pow2[i] * 2) % mod;
	}
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}
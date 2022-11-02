#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

int mod = 998244353;
int powmod(int a, int b){
	int res = 1;
	while(b){
		if(b % 2){
			res = (res * a) % mod;
		}
		b /= 2;
		a = (a * a) % mod;
	}
	return res;
}

int modinv(int a){
	return powmod(a, mod - 2);
}

int fact[200001];
int C(int n, int r){
	return fact[n] * modinv(fact[n - r]) % mod * modinv(fact[r]) % mod;
}
int A[100000];
void sub(){
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<int, char>> cnt;
	char prev = '\0';
	int c = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == prev){
			c++;
		}else{
			if(prev != '\0') cnt.push_back({c, prev});
			c = 1;
			prev = s[i];
		}
	}
	cnt.push_back({c, prev});
	
	vector<int> zeros;
	int cnt_0 = 0;
	for(auto i : cnt){
		if(i.second == '0') cnt_0 += i.first;
		if(i.second == '1' && i.first % 2 == 1){
			zeros.push_back(cnt_0);
			cnt_0 = 0;
		}
	}
	zeros.push_back(cnt_0);
	
	int sum = 0;
	for(auto i : zeros) sum += i;
	sum += (int) zeros.size() - 1;
//	cout << sum + (n - sum) / 2 << ' ' << (n - sum) / 2 << endl;
	cout << C(sum + (n - sum) / 2 - (zeros.size() - 1), (n - sum) / 2) << endl;
}

int32_t main(){
	fact[0] = 1;
	for(int i = 1; i <= 200000; i++){
		fact[i] = (fact[i - 1] * i) % mod;
	}
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}
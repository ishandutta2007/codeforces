#include <bits/stdc++.h>
#define int long long
using namespace std;
int m = 998244353;
map<int, int> cnt;
vector<vector<int>> q(1000000);

int powmod(int a, int b){
	int res = 1;
	while(b){
		if(b % 2){
			res = (res * a) % m;
		}
		b /= 2;
		a = (a * a) % m;
	}
	return res;
}

int modinv(int a){
	return powmod(a, m - 2);
}

int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		for(int j = 0; j < k; j++){
			int v;
			cin >> v;
			q[i].push_back(v);
			cnt[v]++;
		}
	}
	int ans = modinv(powmod(n, 2));
	int mk = 0;
	for(int i = 0; i < n; i++){
		int P = 0;
		int Q = q[i].size();
		for(auto j : q[i]){
			P += cnt[j];
			P %= m;
		}
		mk += P * modinv(Q) % m;
		mk %= m;
	}
	ans = (ans * mk) % m;
	cout << ans << endl;
}
#include <bits/stdc++.h>
#define inf (1LL << 60)
#define int long long
using namespace std;

int powmod(int a, int b, int p){
	int res = 1;
	while(b){
		if(b % 2){
			res = (res * a) % p;
		}
		a = (a * a) % p;
		b /= 2;
	}
	return res;
}

string s;
int LR[1000001], RR[1000001];
int32_t main(){
	cin.tie(0);
	cin >> s;
	int a, b;
	cin >> a >> b;
	int n = s.size();
	for(int i = 0; i < n; i++){
		LR[i + 1] = (LR[i] * 10 + (s[i] - '0')) % a;
	}
	for(int i = n - 1; i >= 0; i--){
		RR[i] = (RR[i + 1] + (s[i] - '0') * powmod(10, (n - 1) - i, b)) % b;
	}
//	for(int i = 0; i <= n; i++){
//		cout << LR[i] << ' ';
//	}
//	cout << endl;
//	for(int i = 0; i <= n; i++){
//		cout << RR[i] << ' ';
//	}
//	cout << endl;
	for(int i = 1; i < n; i++){
		if(LR[i] == 0 && RR[i] == 0 && s[i] != '0'){
			cout << "YES" << endl;
			cout << s.substr(0, i) << endl;
			cout << s.substr(i, n - i) << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
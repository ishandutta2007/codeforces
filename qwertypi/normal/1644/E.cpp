#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int mod = 998244353;
int bp(int a, int b, int p){
	if(b == 0) return 1;
	return bp(a * a % p, b / 2, p) * (b % 2 ? a : 1) % p;
}
 
int rightmost[200001], downmost[200001];
int solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool diff = false;
	for(int i = 1; i < s.size(); i++){
		if(s[i] != s[0]) diff = true;
	}
	if(!diff){
		cout << n << endl;
		return 0;
	}
	if(s[0] == 'D'){
		for(int i = 0; i < (int) s.size(); i++){
			s[i] = (s[i] == 'D' ? 'R' : 'D');
		}
	}
	int mx_r = 0, mx_c = 0;
	for(int i = 0; i < (int) s.size(); i++){
		if(s[i] == 'D'){
			mx_r++;
		}else{
			mx_c++;
		}
	}
	int delta_r = n - 1 - mx_r, delta_c = n - 1 - mx_c;
	int r = 0, c = 0;
	for(int i = 0; i < (int) s.size(); i++){
		if(s[i] == 'D'){
			rightmost[r] = c;
			r++;
		}else{
			downmost[c] = r;
			c++;
		}
	}
	rightmost[r] = c;
	downmost[c] = r;
	/*
	cout << delta_r << ' ' << delta_c << endl;
	for(int i = 0; i <= r; i++){
		cout << rightmost[i] << ' '; 
	}
	cout << endl;
	for(int i = 0; i <= c; i++){
		cout << downmost[i] << ' '; 
	}
	cout << endl;
	*/
	int ans = n * n;
	for(int i = 0; i <= r; i++){
		ans -= n - 1 - rightmost[i] - delta_c;
	}
	for(int i = 0; i <= c; i++){
		if(downmost[i] == 0){
			ans -= n - 1;
		}else{
			ans -= n - 1 - downmost[i] - delta_r;
		}
	}
	cout << ans << endl;
	return 0;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
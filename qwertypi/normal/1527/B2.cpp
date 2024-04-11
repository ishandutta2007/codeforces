#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool odd = n % 2 == 1 && s[n / 2] == '0';
	int par = 0, rem = 0;
	for(int i = 0; i < n / 2; i++) par += s[i] != s[n - 1 - i], rem += (s[i] == '0' && s[n - 1 - i] == '0') * 2;
	if(odd){
		if(par == 0 && rem == 0){
			cout << "BOB" << endl;
		}else if(par == 1 && rem == 0){
			cout << "DRAW" << endl;
		}else{
			cout << "ALICE" << endl;
		}
	}else{
		if(par == 0){
			cout << "BOB" << endl;
		}else{
			cout << "ALICE" << endl; 
		}
	}
}
 
int32_t main(){
	int t; cin >> t;
	while(t--) solve();
}
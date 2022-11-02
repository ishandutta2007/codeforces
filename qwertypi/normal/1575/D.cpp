#include <bits/stdc++.h>

using namespace std;

string s, t;

int ans = 0;
int check(int x){
	// cout << "check " << x << endl;
	bool ex_x = false;
	for(auto i : t) ex_x |= i == 'X';
	if(t.size() >= 1 && t[0] == 'X' && x == 0) return 0;
	int res = 1;
	if(ex_x && x == -1){
		res *= 9 + (t[0] != 'X');
	}
	for(int i = 0; i < (int) t.size(); i++){
		if(t[i] == '_'){
			res *= 9 + (i != 0);
		}
	}
	return res;
}

int main(){
	cin >> s;
	if(s == "XX"){
		cout << 0 << endl;
		return 0;
	}
	if(s.size() == 1){
		cout << (s[0] == '0' || s[0] == '_' || s[0] == 'X' ? 1 : 0) << endl;
		return 0;
	}
	if(s[0] == '0'){
		cout << 0 << endl;
		return 0;
	}
	int n = s.size();
	t = s.substr(0, s.size() - 2);
	for(int i = 0; i <= 75; i += 25){
		if(s.size() == 2 && i == 0) continue;
		int d0 = i % 10, d1 = i / 10;
		if((s[n - 1] == '0' + d0 || s[n - 1] == 'X' || s[n - 1] == '_') && (s[n - 2] == '0' + d1 || s[n - 2] == 'X' || s[n - 2] == '_')){
			int x = -1;
			if(s[n - 1] == 'X') x = d0;
			if(s[n - 2] == 'X'){
				if(x != -1 && d0 != d1) continue;
				x = d1;
			}
			ans += check(x);
		}
	}
	cout << ans << endl; 
}
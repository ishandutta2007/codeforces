#include <bits/stdc++.h>

#define int long long
using namespace std;

int n, k;

string f(string& s){
	string t(n, ' ');
	t[0] = '0' + (s[0] == '1' || s[0] == '0' && s[1] == '1');
	t[n - 1] = '0' + (s[n - 1] == '1' || s[n - 1] == '0' && s[n - 2] == '1');
	for(int i = 1; i < n - 1; i++){
		if(s[i] == '1' || s[i] == '0' && (s[i - 1] + s[i + 1]) == '0' + '1'){
			t[i] = '1';
		}else{
			t[i] = '0';
		}
	} 
	return t;
}

void sub(){
	cin >> n >> k;
	string s, t;
	cin >> s;
	t = f(s);
	while(k != 0 && s != t){
		s = t;
		k--;
		t = f(s);
	}
	cout << s << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}
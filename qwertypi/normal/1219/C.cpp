#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int l = s.length();
	string ans;
	bool all_9 = true;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != '9') all_9 = false;
	}
	if(all_9){
		l++;
		int k = s.size();
		s = "1";
		for(int i = 0; i < k; i++) s += "0";
	}
	if(l % n != 0){
		string t;
		t.push_back('1');
		for(int i = 0; i < n - 1; i++) t.push_back('0');
		for(int i = 0; i < (l + n - 1) / n; i++){
			ans += t;
		}
	}else{
		string t;
		for(int i = 0; i < n; i++){
			t.push_back(s[i]);
		}
		for(int i = 0; i < l / n; i++){
			ans += t;
		}
		if(ans <= s){
			t[n - 1]++;
			for(int i = n - 1; i >= 0; i--){
				if(t[i] > '9') t[i] = '0', t[i - 1]++;
			}
			ans = "";
			for(int i = 0; i < l / n; i++){
				ans += t;
			} 
		}
	}
	cout << ans << endl;
}
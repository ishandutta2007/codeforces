#include <bits/stdc++.h>

using namespace std;

void sub(){
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	string s;
	cin >> s;
	string ans;
	for(auto i : s){
		if(i == 'R'){
			if(b){
				b--;
				ans.push_back('P');
			}else{
				ans.push_back('.');
			}
		}else if(i == 'P'){
			if(c){
				c--;
				ans.push_back('S');
			}else{
				ans.push_back('.');
			}
		}else{
			if(a){
				a--;
				ans.push_back('R');
			}else{
				ans.push_back('.');
			}
		}
	}
	int cnt = count(ans.begin(), ans.end(), '.');
	if(cnt > n / 2){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		string t;
		for(int i = 0; i < a; i++){
			t.push_back('R');
		}
		for(int i = 0; i < b; i++){
			t.push_back('P');
		}
		for(int i = 0; i < c; i++){
			t.push_back('S');
		}
		int pos = 0;
		for(int i = 0; i < n; i++){
			if(ans[i] == '.'){
				ans[i] = t[pos++];
			}
		}
		cout << ans << endl;
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}
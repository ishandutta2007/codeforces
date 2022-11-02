#include <bits/stdc++.h>

using namespace std;

void sub(){
	string s;
	cin >> s;
	string is_odd, is_even;
	for(auto i : s){
		if((i - '0') % 2){
			is_odd.push_back(i);
		}else{
			is_even.push_back(i);
		}
	}
	string ans;
	is_odd.push_back(127);
	is_even.push_back(127);
	int x = 0, y = 0;
	for(int i = 0; i < s.size(); i++){
		if(is_odd[x] < is_even[y]){
			ans.push_back(is_odd[x++]);
		}else{
			ans.push_back(is_even[y++]);
		}
	}
	cout << ans << endl;
}

int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
	return 0;
}
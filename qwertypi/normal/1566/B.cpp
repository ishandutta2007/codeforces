#include <bits/stdc++.h>

using namespace std;

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		bool ex_0 = false, ex_1 = false;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '0') ex_0 = true;
			if(s[i] == '1') ex_1 = true;
		}
		if(!ex_0){
			cout << 0 << endl;
			continue;
		}
		vector<int> pos;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '0'){
				pos.push_back(i);
			}
		}
		bool DONE = false;
		for(int i = 0; i < (int) pos.size() - 1; i++){
			if(pos[i] + 1 != pos[i + 1]){
				cout << 2 << endl;
				DONE = true;
				break;
			}
		}
		if(DONE) continue;
		cout << 1 << endl;
	}
}
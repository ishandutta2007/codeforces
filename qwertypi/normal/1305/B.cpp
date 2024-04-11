#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int cnt_0[1001], cnt_1[1001];
int32_t main(){
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(i == 0){
			cnt_0[0] = (s[i] == '(');
		}else{
			cnt_0[i] = cnt_0[i - 1] + (s[i] == '(');
		}
	}
	for(int i = s.size() - 1; i >= 0; i--){
		if(i == s.size() - 1){
			cnt_1[i] = (s[i] == ')');
		}else{
			cnt_1[i] = cnt_1[i + 1] + (s[i] == ')');
		}
	}
	for(int i = 0; i < s.size() - 1; i++){
		if(cnt_0[i] == cnt_1[i + 1]){
			vector<int> ans;
			for(int j = 0; j <= i; j++){
				if(s[j] == '('){
					ans.push_back(j + 1);
				}
			}
			for(int j = i + 1; j < s.size(); j++){
				if(s[j] == ')'){
					ans.push_back(j + 1);
				}
			}
			if(ans.size() == 0){
			    continue;
			}
			cout << 1 << endl;
			cout << ans.size() << endl;
			for(auto i : ans){
				cout << i << ' ';
			}
			exit(0);
		}
	}
	cout << 0 << endl;
}
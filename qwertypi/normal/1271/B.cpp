#include <bits/stdc++.h>

using namespace std;
int main(){
	int n;
	string s;
	cin >> n >> s;
	vector<int> ans;
	for(int i = 0; i < n - 1; i++){
		if(s[i] == 'W'){
			s[i] = 'B';
			if(s[i + 1] == 'W'){
				s[i + 1] = 'B';
			}else{
				s[i + 1] = 'W';
			}
			ans.push_back(i + 1);
		}
	}
	if(s[n - 1] == 'W'){
		if(n % 2 == 0){
			cout << -1;
			return 0;
		}
		for(int i = 0; i < n / 2; i++){
			ans.push_back(i * 2 + 1);
		}
	}
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i << ' ';
	}
}
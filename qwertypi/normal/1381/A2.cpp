#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> ans;
void sub(){
	ans.clear();
	int n;
	string s, t;
	cin >> n;
	cin >> s >> t;
	int l = 0, r = n - 1;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0){
			if(s[l++] == t[n - 1 - i]){
				ans.push_back(1);
			}
			ans.push_back(n - i);
		}else{
			if(s[r--] != t[n - 1 - i]){
				ans.push_back(1);
			}
			ans.push_back(n - i);
		}
	}
	
	cout << ans.size() << ' ';
	for(auto i : ans){
		cout << i << ' ';
	}
	cout << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}
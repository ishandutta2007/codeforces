#include <bits/stdc++.h>
using namespace std;

void sub(){
	int n;
	cin >> n;
	set<int> ans;
	int prev = 0;
	int i = 1; 
	while(i <= n / i){
		ans.insert(i);
		ans.insert(n / i);
		i++;
	}
	ans.insert(0);
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i << ' ';
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int itr = 0; itr < t; itr++){
		long long T;
		cin >> T;
		if(T % 2 == 1){
			cout << -1 << endl;
			continue;
		}
		vector<int> ans;
		for(int j = 59; j >= 2; j--){
			while(T >= (1LL << j) - 2){
				ans.push_back(1);
				for(int i = 0; i < j - 2; i++) ans.push_back(0);
				T -= (1LL << j) - 2;
			}
		}
		cout << ans.size() << endl;
		for(auto i : ans){
			cout << i << ' ';
		}
		cout << endl;
	}
}
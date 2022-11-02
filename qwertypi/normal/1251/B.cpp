#include <bits/stdc++.h>

using namespace std;

void sub(){
	int n;
	cin >> n;
	int cnt_0 = 0, cnt_1 = 0;
	int OK = false;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(auto i : s){
			if(i == '0'){
				cnt_0++;
			}else{
				cnt_1++;
			}
		}
		if(s.size() % 2){
			OK = true;
		}
	}
	if(OK){
		cout << n << endl;
	}else{
		if(cnt_0 % 2){
			cout << n - 1 << endl;
		}else{
			cout << n << endl;
		}
	}
}

int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
	return 0;
}
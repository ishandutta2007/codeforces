#include <bits/stdc++.h>

using namespace std;

void sub(){
	string s;
	cin >> s;
	set<int> OK;
	char prev = ' ';
	int cnt = 0; 
	for(auto i : s){
		if(i != prev){
			if(cnt % 2 == 1){
				OK.insert(prev);
			}
			cnt = 1;
		}else{
			cnt++;
		}
		prev = i;
	}
	if(cnt % 2 == 1){
		OK.insert(prev);
	}
	for(auto i : OK){
		cout << (char)i;
	}
	cout << endl;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
	return 0;
}
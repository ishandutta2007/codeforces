#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int cnt = 0;
	for(char x : s){
		if(x=='0')cnt++;
	}
	for(char x : s){
		if(x=='0')cnt--;
		else{
			if(cnt>=6){
				cout << "yes\n";
				exit(0);
			}
		}
	}
	cout << "no\n";
	return 0;
}
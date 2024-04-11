#include "bits/stdc++.h"
using namespace std;
string str;
void check(){
	int l = 0;
	int r = str.size() - 1;
	while(l < r){
		if(str[l] != str[r]){
			return;
		}
		++l;
		--r;
	}
	cout << "YES\n";
	exit(0);
}
int main(){
	cin >> str;
	for(int i = 0 ; i < str.size() ; ++i){
		char tmp = str[i];
		for(int j = 0 ; j < 26 ; ++j){
			if('a' + j != tmp){
				str[i] = 'a' + j;
				check();
			}
		}
		str[i] = tmp;
	}
	cout << "NO\n";
}
#include "bits/stdc++.h"
using namespace std;
int n;
int main(){
	cin >> n;
	long long num = 0;
	string str = to_string(n);
	if(str[0] == '9'){
		num = 1;
		for(int i = 0 ; i < str.size() ; ++i){
			num *= 10;
		}
	}
	else{
		num = str[0] - '0' + 1;
		for(int i = 1 ; i < str.size() ; ++i){
			num *= 10;
		}
	}
	cout << num - n << endl;
}
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
string str;
int n;
int main(){
	cin >> str;
	n = str.size();
	str = " " + str + " ";
	for(int i = 1 ; i <= n ; ++i){
		if(str[i] == str[i - 1]){
			for(char tmp = 'a' ; tmp <= 'z' ; ++tmp){
				if(tmp != str[i - 1] && tmp != str[i + 1]){
					str[i] = tmp;
					break;
				}
			}
		}
	}
	str.erase(str.begin());
	cout << str;
}
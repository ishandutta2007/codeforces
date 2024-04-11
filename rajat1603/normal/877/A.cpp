#include "bits/stdc++.h"
using namespace std;
string arr[5] = {"Danil", "Olya", "Slava", "Ann" , "Nikita"};
string str;
int cnt;
int main(){
	cin >> str;
	for(int i = 0 ; i < str.size() ; ++i){
		for(int j = 0 ; j < 5 ; ++j){
			if(i + arr[j].size() - 1 < str.size()){
				bool ok = 1;
				for(int k = 0 ; k < arr[j].size() ; ++k){
					if(arr[j][k] != str[i + k]){
						ok = 0;
					}
				}
				cnt += ok;
			}
		}
	}
	if(cnt == 1){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}
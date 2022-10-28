#include "bits/stdc++.h"
using namespace std;
int n , p;
string str;
int main(){
	cin >> n >> p;
	cin >> str;
	str = " " + str;
	for(int i = n ; i >= 1 ; --i){
		if(str[i] - 'a' + 1 == p){
			continue;
		}
		++str[i];
		if(str[i] == str[i - 1] || str[i] == str[i - 2]){
			if(str[i] - 'a' + 1 == p){
				continue;
			}
			++str[i];
			if(str[i] == str[i - 1] || str[i] == str[i - 2]){
				if(str[i] - 'a' + 1 == p){
					continue;
				}
				++str[i];
			}
		}
		bool ok = 1;
		for(int j = i + 1 ; j <= n ; ++j){
			if(str[j - 1] == 'a' || str[j - 2] == 'a'){
				if(p <= 1){
					ok = 0;
					break;
				}
				if(str[j - 1] == 'b' || str[j - 2] == 'b'){
					if(p <= 2){
						ok = 0;
						break;
					}
					str[j] = 'c';
				}
				else{
					str[j] = 'b';
				}
			}
			else{
				str[j] = 'a';
			}
		}
		if(ok){
			for(int j = 2 ; j < i ; ++j){
				if(str[j] == str[j - 1] || str[j] == str[j - 2]){
					ok = 0;
					break;
				}
			}
			if(!ok){
				continue;
			}
			str.erase(str.begin() , str.begin() + 1);
			cout << str;
			return 0;
		}
	}
	cout << "NO\n";
}
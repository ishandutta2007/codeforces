#include "bits/stdc++.h"
using namespace std;
string str;
int main(){
	cin >> str;
	int idx = -1;
	int cur = str.size() - 1;
	int point = str.size();
	for(int i = 0 ; i < str.size() ; ++i){
		if(str[i] == '0'){
			continue;
		}
		if(isdigit(str[i])){
			printf("%c" , str[i]);
			idx = i;
			break;
		}
	}
	for(int i = 0 ; i < str.size() ; ++i){
		if(str[i] == '.'){
			point = i;
		}
	}
	while((cur >= 0) && ((str[cur] == '0') || str[cur] == '.')){
		--cur;
	}
	bool ok = 0;
	for(int i = idx + 1 ; i <= cur ; ++i){
		if(isdigit(str[i])){
			if(!ok){
				ok = 1;
				printf(".");
			}
			printf("%c" , str[i]);
		}
	}
	int expo = point - idx - 1;
	if(expo > 0){
		printf("E%d\n" , expo);
	}
	else if(expo < 0){
		printf("E%d\n" , expo + 1);
	}
}
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string s;
int n,k;
int sx,ex;

int main(){
	cin >> n >> k;
	cin >> s;
	for(int i = 0;i<s.size();i++){
		if(s[i] == 'G') sx = i;
		if(s[i] == 'T') ex = i;
	}

	if(sx > ex){
		for(int j = sx;s[j] != 'T';j -= k){
			if(j < 0) {
				printf("NO\n");
				return 0;
			}
			if(s[j] == '#'){
				printf("NO\n");
				return 0;
			}
			
		}
	}
	else{
		for(int j = sx;s[j] != 'T';j += k){
			if(j >= n) {
				printf("NO\n");
				return 0;
			}
			if(s[j] == '#'){
				printf("NO\n");
				return 0;
			}
			
		}
	}
	printf("YES\n");
}
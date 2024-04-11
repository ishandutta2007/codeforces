#include "bits/stdc++.h"
using namespace std;
const int N = 3e3 + 3;
int n;
char str[N];
bool vowel(char c){
	if(c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'){
		return 1;
	}
	return 0;
}
int main(){
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	int cnt = 0;
	char who = -1;
	bool gg = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(vowel(str[i])){
			cnt = 0;
			who = -1;
			gg = 0;
		}
		else{
			if(cnt == 0){
				who = str[i];
			}
			++cnt;
			if(who != str[i]){
				gg = 1;
			}
		}
		if(gg && cnt >= 3){
			printf(" ");
			cnt = 1;
			who = str[i];
			gg = 0;
		}
		printf("%c" , str[i]);
	}
	printf("\n");
}
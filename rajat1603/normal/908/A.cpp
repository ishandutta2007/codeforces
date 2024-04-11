#include "bits/stdc++.h"
using namespace std;
//vowel => even digits
const int N = 1e3 + 3;
char str[N];
int n;
int ans;
int main(){
	scanf("%s" , str);
	n = strlen(str);
	for(int i = 0 ; i < n ; ++i){
		if(str[i] >= '0' && str[i] <= '9'){
			int val = str[i] - '0';
			if(val & 1){
				++ans;
			}
			else{

			}
		}
		else{
			if(str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'i' || str[i] == 'u'){
				++ans;
			}
			else{

			}
		}
	}
	printf("%d\n" , ans);
}
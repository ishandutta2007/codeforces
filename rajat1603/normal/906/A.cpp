#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int ans;
bool ok;
char a[5];
char b[N];
int n;
bool okay[26];
bool fine;
bool there[26];
int main(){
	scanf("%d" , &n);
	for(int i = 0 ; i < 26 ; ++i){
		okay[i] = 1;
	}
	for(int i = 1 ; i < n ; ++i){
		scanf("%s" , a);
		scanf("%s" , b);
		if(a[0] == '.'){
			for(int j = 0 ; b[j] ; ++j){
				okay[b[j] - 'a'] = 0;
			}
		}
		else if(a[0] == '!'){
			memset(there , 0 , sizeof(there));
			for(int j = 0 ; b[j] ; ++j){
				there[b[j] - 'a'] = 1;
			}
			for(int j = 0 ; j < 26 ; ++j){
				if(!there[j]){
					okay[j] = 0;
				}
			}
		}
		else{
			okay[b[0] - 'a'] = 0;
		}
		ans += fine && (a[0] != '.');
		int cnt = 0;
		for(int j = 0 ; j < 26 ; ++j){
			cnt += okay[j];
		}
		if(cnt == 1){
			fine = 1;
		}
	}
	printf("%d\n" , ans);
}
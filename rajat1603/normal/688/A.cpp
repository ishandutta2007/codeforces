#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , d;
char str[N];
int l;
int ans;
int main(){
	scanf("%d %d" , &n , &d);
	l = 1;
	ans = 0;
	for(int i = 1 ; i <= d ; ++i){
		scanf("%s" , str + 1);
		bool ok = 0;
		for(int i = 1 ; i <= n ; ++i){
			if(str[i] == '0'){
				ok = 1;
				break;
			}
		}
		if(!ok){
			l = i + 1;
		}
		ans = max(ans , i - l + 1);
	}
	printf("%d\n" , ans);
}
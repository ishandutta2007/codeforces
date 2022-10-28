#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n , m;
char s[N];
char t[N];
int ans;
int main(){
	scanf("%d %d" , &n , &m);
	scanf("%s" , s + 1);
	scanf("%s" , t + 1);
	ans = N;
	int idx = -1;
	for(int i = 1 ; i + n - 1 <= m ; ++i){
		int res = 0;
		for(int j = 1 ; j <= n ; ++j){
			res += s[j] != t[i + j - 1];
		}
		ans = min(ans , res);
		if(ans == res){
			idx = i;
		}
	}
	printf("%d\n" , ans);
	for(int j = 1 ; j <= n ; ++j){
		if(s[j] != t[idx + j - 1]){
			printf("%d " , j);
		}
	}
	printf("\n");
}
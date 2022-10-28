#include "bits/stdc++.h"
using namespace std;
const int N = 1505;
int n;
char str[N];
int q;
int m;
char tmp[5];
int ans[26][N];
void solve(char c){
	for(int m = 0 ; m <= n ; ++m){
		int res = 0;
		int ptr = 1;
		int tot = 0;
		for(int i = 1 ; i <= n ; ++i){
			tot += (str[i] != c);
			while(tot > m){
				tot -= (str[ptr++] != c);
			}
			res = max(res , i - ptr + 1);
		}
		ans[c - 'a'][m] = res;
	}
}
int main(){
	scanf("%d" , &n);
	scanf("%s" , str + 1);
	scanf("%d" , &q);
	for(int i = 0 ; i < 26 ; ++i){
		solve(char('a' + i));
	}
	while(q--){
		scanf("%d %s" , &m , tmp);
		printf("%d\n" , ans[tmp[0] - 'a'][m]);
	}
}
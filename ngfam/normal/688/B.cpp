#include <bits/stdc++.h>

using namespace std;

const int N = 123456;
char s[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("0.inp", "r", stdin);
		freopen("0.out", "w", stdout);	
	#endif

	scanf("%s", s + 1);
	printf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = n; i >= 1; --i){
		printf("%c", s[i]); 
	}
	return 0;	
}
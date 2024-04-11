#include "bits/stdc++.h"
using namespace std;
const int N = 205;
int n;
char str[N];
set < string > s;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str);
		if(s.find(str) == s.end()){
			printf("NO\n");
			s.insert(str);
		}
		else{
			printf("YES\n");
		}
	}
}
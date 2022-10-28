#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
char str[N];
char suf[N];
int ptr;
stack < char > s;
int main(){
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	suf[n] = str[n];
	for(int i = n - 1 ; i >= 1 ; --i){
		suf[i] = min(str[i] , suf[i + 1]);
	}
	ptr = 1;
	while(!s.empty()){
		s.pop();
	}
	for(int i = 1 ; i <= n ; ++i){
		if(ptr > n){
			printf("%c" , s.top());
			s.pop();
		}
		else if(!s.empty() && s.top() <= suf[ptr]){
			printf("%c" , s.top());
			s.pop();
		}
		else{
			while(ptr <= n && str[ptr] != suf[ptr]){
				s.push(str[ptr++]);
			}
			s.push(str[ptr++]);
			printf("%c" , s.top());
			s.pop();
		}
	}
	printf("\n");
}
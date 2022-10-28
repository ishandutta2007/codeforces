#include "bits/stdc++.h"
using namespace std;
int n;
char op[5];
int val;
int c1 , c2 , c3;
int main(){
	scanf("%d" , &n);
	c1 = 1023;
	c2 = 0;
	c3 = 0;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , op);
		scanf("%d" , &val);
		if(op[0] == '&'){
			c1 &= val;
			c2 &= val;
			c3 &= val;
		}
		else if(op[0] == '^'){
			c3 ^= val;
		}
		else{
			c2 |= val;
			c3 &= ~val;
		}
	}
	printf("3\n");
	printf("& %d\n" , c1);
	printf("| %d\n" , c2);
	printf("^ %d\n" , c3);
}
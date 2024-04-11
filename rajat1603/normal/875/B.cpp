#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n;
int pos;
int there[N];
int ptr;
int main(){
	scanf("%d" , &n);
	for(int i = 0 ; i <= n ; ++i){
		there[i] = 1;
	}
	ptr = n;
	printf("1");
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &pos);
		there[pos] = 0;
		while(!there[ptr]){
			--ptr;
		}
		printf(" %d" , ptr - (n - i) + 1);
	}
	printf("\n");
}
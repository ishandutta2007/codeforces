#include "bits/stdc++.h"
using namespace std;
int n , t;
int main(){
	scanf("%d %d" , &n , &t);
	for(int i = 1 ; i <= n ; ++i){
		int a;
		scanf("%d" , &a);
		a = 86400 - a;
		if(a >= t){
			printf("%d\n" , i);
			break;
		}
		t -= a;
	}
}
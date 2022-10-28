#include "bits/stdc++.h"
using namespace std;
int a , b , c;
int n;
int x;
int ans;
int main(){
	scanf("%d %d %d" , &a , &b , &c);
	scanf("%d" , &n);
	while(n--){
		scanf("%d" , &x);
		ans += (x > b) && (x < c);
	}
	printf("%d\n" , ans);
}
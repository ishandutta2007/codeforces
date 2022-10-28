#include "bits/stdc++.h"
using namespace std;
int n;
int x;
int sum;
int l , r;
int main(){
	scanf("%d" , &n);
	while(n--){
		scanf("%d" , &x);
		sum += x;
	}
	scanf("%d" , &n);
	while(n--){
		scanf("%d %d" , &l , &r);
		if(r < sum){
			continue;
		}
		if(l <= sum){
			printf("%d\n" , sum);
			return 0;
		}
		printf("%d\n" , l);
		return 0;
	}
	printf("-1\n");
}
#include "bits/stdc++.h"
using namespace std;
int n;
bool solve(int x){
	for(int i = 0 ; i <= x ; i += 123456){
		int lft = x - i;
		if(lft % 1234 == 0){
			return 1;
		}
	}
	return 0;
}
int main(){
	cin >> n;
	for(int i = 0 ; i <= n ; i += 1234567){
		if(solve(n - i)){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}
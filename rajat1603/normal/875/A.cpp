#include "bits/stdc++.h"
using namespace std;
int n;
vector < int > ans;
int sum(int x){
	int res = 0;
	while(x){
		res += x % 10;
		x /= 10;
	}
	return res;
}
int main(){
	cin >> n;
	for(int i = max(1 , n - 100) ; i <= n ; ++i){
		if(sum(i) + i == n){
			ans.emplace_back(i);
		}
	}
	printf("%d\n" , int(ans.size()));
	for(int x : ans){
		printf("%d\n" , x);
	}
}
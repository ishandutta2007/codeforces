#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
int ans;
int solve(int rows){
	int cols = (n + rows - 1) / rows;
	int tot = 0;
	tot += cols;
	tot += rows * 2;
	tot += cols;
	return tot;
}
int main(){
	cin >> n;
	ans = solve(1);
	for(int i = 2 ; i <= n ; ++i){
		ans = min(ans , solve(i));
	}
	printf("%d\n" , ans);
}
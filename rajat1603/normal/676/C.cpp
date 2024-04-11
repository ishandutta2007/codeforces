#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n , k;
char arr[N];
int solve(){
	int sum = 0;
	int lft = 1;
	int res = 0;
	for(int i = 1 ; i <= n ; ++i){
		sum += (arr[i] == 'b');
		while(sum > k){
			sum -= (arr[lft++] == 'b');
		}
		res = max(res , i - lft + 1);
	}
	return res;
}
int main(){
	scanf("%d %d" , &n , &k);
	scanf("%s" , arr + 1);
	int ans = solve();
	for(int i = 1 ; i <= n ; ++i){
		arr[i] = 'a' ^ 'b' ^ arr[i];
	}
	ans = max(ans , solve());
	printf("%d\n" , ans);
}
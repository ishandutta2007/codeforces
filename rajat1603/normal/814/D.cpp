#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n;
pair < int , pair < int , int > > arr[N];
vector < int > v[N];
long long sqr(int x){
	return 1LL * x * x;
}
bool inside(pair < int , pair < int , int > > small , pair < int , pair < int , int > > big){
	int x = small.second.first - big.second.first;
	int y = small.second.second - big.second.second;
	int R = big.first;
	int r = small.first;
	return sqr(x) + sqr(y) <= sqr(R - r);
}
long long dp[N][2];
bool calc[N][2];
long long solve(int node , bool lft , bool rgt){
	if(calc[node][lft]){
		return dp[node][lft];
	}
	long long res1 = 0;
	long long res2 = 0;
	if(lft & 1){
		res1 -= 1LL * arr[node].first * arr[node].first;
	}
	else{
		res1 += 1LL * arr[node].first * arr[node].first;
	}
	if(rgt & 1){
		res2 -= 1LL * arr[node].first * arr[node].first;
	}
	else{
		res2 += 1LL * arr[node].first * arr[node].first;
	}
	for(int next : v[node]){
		res1 += solve(next , lft ^ 1 , rgt);
		res2 += solve(next , left , rgt ^ 1);
	}
	calc[node][lft] = 1;	
	return dp[node][lft] = max(res1 , res2);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d" , &arr[i].second.first , &arr[i].second.second , &arr[i].first);
	}
	sort(arr + 1 , arr + 1 + n);
	reverse(arr + 1 , arr + 1 + n);
	for(int i = 1 ; i <= n ; ++i){
		int idx = 0;
		for(int j = i - 1 ; j >= 1 ; --j){
			if(inside(arr[i] , arr[j])){
				idx = j;
				break;
			}
		}
		v[idx].emplace_back(i);
	}
	long long ans = 0;
	for(int next : v[0]){
		ans += solve(next , 0 , 0);
	}
	printf("%.9lf\n" , ans * acos(-1));
}
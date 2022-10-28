#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
const int M = 1e5 + 5;
const int inf = N * N;
int n;
int arr[N];
int dp[N][N];
int calc[N][N];
int tc;
vector < int > v;
vector < int > a , b;
int ans;
int solve(int pos , int sub , int plus){
	if(pos >= b.size()){
		return 0;
	}
	if(calc[pos][sub] == tc){
		return dp[pos][sub];
	}
	int res = inf;
	res = min(res , solve(pos + 1 , sub , plus + 1) + int(a.size()) - b[pos] - 1 - (int(b.size()) - 1 - pos));
	res = min(res , solve(pos + 1 , sub + 1 , plus) + b[pos] - sub);
	calc[pos][sub] = tc;
	return dp[pos][sub] = res;
}
void solve(int val){
	a.clear();
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] <= val){
			a.emplace_back(arr[i]);
		}
	}
	b.clear();
	for(int i = 0 ; i < a.size() ; ++i){
		if(a[i] == val){
			b.emplace_back(i);
		}
	}
	++tc;
	ans += solve(0 , 0 , 0);
}
int main(){
	scanf("%d" , &n);
	v.clear();
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		arr[i] = max(arr[i] , -arr[i]);
		v.emplace_back(arr[i]);
	}
	sort(v.begin() , v.end());
	v.resize(unique(v.begin() , v.end()) - v.begin());
	reverse(v.begin() , v.end());
	for(int x : v){
		solve(x);
	}
	printf("%d\n" , ans);
}
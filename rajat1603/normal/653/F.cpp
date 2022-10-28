#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
const int LN = 20;
int n;
char str[N];
int sum[N];
vector < int > v[N + N];
int dp[LN][N];
int finalsa[N];
int lcp[N];
pair < pair < int , int > , int > tmp[N];
long long ans;
int rgt[N];
stack < int > stk;
void buildsa(){
	for(int i = 1 ; i <= n ; ++i){
		dp[0][i] = 1 + (str[i] == ')');
	}
	tmp[0] = make_pair(make_pair(-1 , -1) , -1);
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			int x = j + (1 << (i - 1));
			tmp[j] = make_pair(make_pair(dp[i - 1][j] , (x <= n) ? dp[i - 1][x] : (-1)) , j);
		}
		sort(tmp + 1 , tmp + 1 + n);
		int cur = 0;
		for(int j = 1 ; j <= n ; ++j){
			cur += tmp[j].first != tmp[j - 1].first;
			dp[i][tmp[j].second] = cur;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		finalsa[dp[LN - 1][i]] = i;
	}
	for(int i = 1 ; i < n ; ++i){
		int x = finalsa[i];
		int y = finalsa[i + 1];
		int res = 0;
		for(int j = LN - 1 ; j >= 0 ; --j){
			if(dp[j][x] == dp[j][y]){
				res += 1 << j;
				x += 1 << j;
				y += 1 << j;
			}
		}
		lcp[i] = res;
	}
	lcp[n] = 0;
}
void solve(int idx , int l , int r){
	int val = sum[idx - 1];
	if(l <= r){
		ans += lower_bound(v[val].begin() , v[val].end() , r + 1) - lower_bound(v[val].begin() , v[val].end() , l);
	}
}
int main(){
	scanf("%d" , &n);
	scanf("%s" , str + 1);
	sum[0] = N;
	for(int i = 1 ; i <= n ; ++i){
		sum[i] = sum[i - 1];
		if(str[i] == '('){
			++sum[i];
		}
		else{
			--sum[i];
		}
		v[sum[i]].emplace_back(i);
	}
	sum[n + 1] = -N;
	stk.push(n + 1);
	for(int i = n ; i >= 0 ; --i){
		while(sum[stk.top()] >= sum[i]){
			stk.pop();
		}
		rgt[i] = stk.top();
		stk.push(i);
	}
	buildsa();
	for(int i = n ; i >= 1 ; --i){
		solve(finalsa[i] , finalsa[i] + lcp[i] , rgt[finalsa[i] - 1] - 1);
	}
	printf("%lld\n" , ans);
}
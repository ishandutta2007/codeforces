#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N + N];
long long sum[N + N];
int l , r;
map < long long , vector < int > > mp;
int ans;
int cnt(int l , int r , long long val){
	return lower_bound(mp[val].begin() , mp[val].end() , r + 1) - lower_bound(mp[val].begin() , mp[val].end() , l);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	ans = n - 1;
	for(int i = n + 1 ; i <= n + n ; ++i){
		arr[i] = arr[i - n];
	}
	sum[0] = 0;
	for(int i = 1 ; i <= n + n ; ++i){
		sum[i] = sum[i - 1] + arr[i];
	}
	for(int i = 1 ; i <= n + n ; ++i){
		mp[sum[i]].emplace_back(i);
	}
	l = 1;
	r = n;
	while(r <= n + n){
		int x = cnt(l , r - 1 , sum[l - 1]);
		ans = min(ans , r - l - x);
		++l;
		++r;
	}
	cout << ans;
}
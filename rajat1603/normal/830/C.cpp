#include "bits/stdc++.h"
using namespace std;
const int N = 105;
const int M = 35005;
int n;
long long k;
int arr[N];
long long ans;
vector < int > v;
bool check(long long d){
	long long cst = 0;
	for(int i = 1 ; i <= n ; ++i){
		cst += ((arr[i] + d - 1LL) / d) * d - arr[i];
	}
	return cst <= k;
}
int main(){
	scanf("%d %lld" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	ans = 1;
	for(int i = 1 ; i < M ; ++i){
		if(check(i)){
			ans = i;
		}
	}
	v.clear();
	v.push_back(M);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= arr[i] ; j = (arr[i] / (arr[i] / j)) + 1){
			if(j >= M){
				v.emplace_back(j);
				if(j - 1 >= M){
					v.emplace_back(j - 1);
				}
			}
		}
		v.emplace_back(arr[i]);
	}
	sort(v.begin() , v.end());
	v.resize(unique(v.begin() , v.end()) - v.begin());
	for(int i = 0 ; i + 1 < v.size() ; ++i){
		if(check(v[i])){
			ans = max(ans , 1LL * v[i]);
		}
		if(v[i + 1] - v[i] <= 3){
			for(int j = v[i] + 1 ; j < v[i + 1] ; ++j){
				if(check(j)){
					ans = max(ans , 1LL * j);
				}
			}
		}
		else{
			int l = v[i] + 1;
			int r = v[i + 1] - 1;
			while(l < r){
				int mid = l + r + 1 >> 1;
				if(check(mid)){
					ans = max(ans , 1LL * mid);
					l = mid;
				}
				else{
					r = mid - 1;
				}
			}
			if(check(l)){
				ans = max(ans , 1LL * l);
			}
		}
	}
	if(check(v.back())){
		ans = max(ans , 1LL * v.back());
		long long l = v.back() + 1;
		long long r = 1e12 + 12;
		while(l < r){
			long long mid = l + r + 1 >> 1;
			if(check(mid)){
				ans = max(ans , mid);
				l = mid;
			}
			else{
				r = mid - 1;
			}
		}
		if(check(l)){
			ans = max(ans , l);
		}
	}
	printf("%lld\n" , ans);
}
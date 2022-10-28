#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
long long arr[N];
long long ans;
void solve(long long val){
	map < long long , int > mp;
	mp.clear();
	for(int i = 1 ; i <= n ; ++i){
		++mp[__gcd(arr[i] , val)];
	}
	for(int i = 1 ; 1LL * i * i <= val ; ++i){
		if(val % i == 0){
			int cnt1 = 0;
			int cnt2 = 0;
			for(auto it : mp){
				if(it.first % i == 0){
					cnt1 += it.second;
				}
				if(it.first % (val / i) == 0){
					cnt2 += it.second;
				}
			}
			if(cnt1 >= (n + 1 >> 1)){
				ans = max(ans , 1LL * i);
			}
			if(cnt2 >= (n + 1 >> 1)){
				ans = max(ans , val / i);
				break;
			}
		}
	}
}
int myrand(){
	return ((1LL * ((1LL * rand() * rand()) & INT_MAX) + rand()) & INT_MAX);
}
int main(){
	clock_t timer = clock();
	srand(time(NULL));
	scanf("%d" ,  &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld" , arr + i);
	}
	ans = 1;
	set < long long > s;
	s.clear();
	while(1.0 * (clock() - timer) / CLOCKS_PER_SEC <= 3.6){
		long long val = arr[1 + (myrand() % n)];
		if(val <= ans){
			continue;
		}
		bool rekt = 0;
		for(auto it : s){
			if((it % val) == 0){
				rekt = 1;
				break;
			}
		}
		if(!rekt){
			solve(val);
			s.insert(val);
		}
	}
	printf("%lld\n" , ans);
}
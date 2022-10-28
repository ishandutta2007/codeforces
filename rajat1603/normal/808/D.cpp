#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
long long arr[N];
long long sum[N];
vector < pair < long long , int > > v;
void done(){
	printf("YES\n");
	exit(0);
}
void solve1(long long suml , long long sumr , int idx){
	long long val = suml - sumr;
	if(val < 0){
		return;
	}
	if(val == 0){
		done();
	}
	if(val & 1){
		return;
	}
	val >>= 1;
	auto it = lower_bound(v.begin() , v.end() , make_pair(val , 1));
	if(it == v.end()){
		return;
	}
	if(it -> first != val){
		return;
	}
	if(it -> second > idx){
		return;
	}
	done();
}
void solve2(long long suml , long long sumr , int idx){
	long long val = sumr - suml;
	if(val < 0){
		return;
	}
	if(val == 0){
		done();
	}
	if(val & 1){
		return;
	}
	val >>= 1;
	auto it = lower_bound(v.begin() , v.end() , make_pair(val , idx + 1));
	if(it == v.end()){
		return;
	}
	if(it -> first != val){
		return;
	}
	done();
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld" , arr + i);
		sum[i] = sum[i - 1] + arr[i];
		v.emplace_back(make_pair(arr[i] , i));
	}
	sort(v.begin() , v.end());
	for(int i = 0 ; i <= n ; ++i){
		solve1(sum[i] , sum[n] - sum[i] , i);
	}
	for(int i = 0 ; i <= n ; ++i){
		solve2(sum[i] , sum[n] - sum[i] , i);
	}
	printf("NO\n");
	return 0;
}
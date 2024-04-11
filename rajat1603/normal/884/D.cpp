#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n;
int arr[N];
long long ans;
priority_queue < long long > pq;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		pq.push(-arr[i]);
	}
	ans = 0;
	if(!(n & 1)){
		long long val = 0;
		val += -pq.top();
		pq.pop();
		val += -pq.top();
		pq.pop();
		ans += val;
		pq.push(-val);
	}
	while(pq.size() > 1){
		if(pq.size() == 2){
			ans += -pq.top();
			pq.pop();
			ans += -pq.top();
			pq.pop();
			continue;
		}
		if(pq.size() == 3){
			ans += -pq.top();
			pq.pop();
			ans += -pq.top();
			pq.pop();
			ans += -pq.top();
			pq.pop();
			continue;
		}
		long long val = 0;
		val -= pq.top();
		pq.pop();
		val -= pq.top();
		pq.pop();
		val -= pq.top();
		pq.pop();
		ans += val;
		pq.push(-val);
	}
	printf("%lld\n" , ans);
}
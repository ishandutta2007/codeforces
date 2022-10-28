#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , k;
int arr[N];
vector < int > v[N];
int ans[N];
priority_queue < pair < int , int > > pq;
long long tot;
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		v[max(i , k + 1)].emplace_back(i);
	}
	for(int i = k + 1 ; i <= n + k ; ++i){
		for(int idx : v[i]){
			pq.push({arr[idx] , idx});
		}
		ans[pq.top().second] = i;
		pq.pop();
	}
	for(int i = 1 ; i <= n ; ++i){
		tot += 1LL * (ans[i] - i) * arr[i];
	}
	printf("%lld\n" , tot);
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , ans[i] , " \n"[i == n]);
	}
}
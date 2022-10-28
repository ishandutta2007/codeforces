#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , t;
int a[N] , k[N];
vector < int > v[N];
priority_queue < pair < int , int > > pq;
void print(){
	printf("%d\n%d\n" , int(pq.size()) , int(pq.size()));
	while(!pq.empty()){
		printf("%d " , pq.top().second);
		pq.pop();
	}
	printf("\n");
}
int solve(int pos){
	while(!pq.empty()){
		pq.pop();
	}
	int res = 0;
	int idx = n + 1;
	int sum = 0;
	for(int i = N - 1 ; i >= 1 ; --i){
		for(int idx : v[i]){
			pq.push({k[idx] , idx});
			sum += k[idx];
		}
		while(pq.size() > i){
			sum -= pq.top().first;
			pq.pop();
		}
		while(sum > t){
			sum -= pq.top().first;
			pq.pop();
		}
		if(pos == i){
			print();
			return 0;
		}
		if(pq.size() > res){
			res = pq.size();
			idx = i;
		}
	}
	return idx;
}
int main(){
	scanf("%d %d" , &n , &t);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , a + i , k + i);
		v[a[i]].emplace_back(i);
	}
	solve(solve(0));
}
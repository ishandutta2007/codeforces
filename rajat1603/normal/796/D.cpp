#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , k , d;
pair < int , int > dist[N];
int val;
int a[N] , b[N];
vector < int > v[N];
queue < int > q;
int main(){
	scanf("%d %d %d" , &n , &k , &d);
	for(int i = 1 ; i <= n ; ++i){
		dist[i] = {N , N};
	}
	for(int i = 1 ; i <= k ; ++i){
		scanf("%d" , &val);
		if(dist[val].first == N){
			dist[val] = {0 , i};
			q.push(val);
		}
	}
	printf("%d\n" , int(q.size()) - 1);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , a + i , b + i);
		v[a[i]].emplace_back(i);
		v[b[i]].emplace_back(i);
	}
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int edge : v[node]){
			int next = a[edge] ^ b[edge] ^ node;
			if(dist[next].first > dist[node].first + 1){
				dist[next].first = dist[node].first + 1;
				dist[next].second = dist[node].second;
				q.push(next);
			}
		}
	}
	for(int i = 1 ; i < n ; ++i){
		if(dist[a[i]].second != dist[b[i]].second){
			printf("%d " , i);
		}
	}
	printf("\n");
}
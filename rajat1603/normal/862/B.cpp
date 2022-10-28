#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int a , b;
vector < int > v[N];
int cnt[2];
void dfs(int node , int parent , int part){
	++cnt[part];
	for(int next : v[node]){
		if(next != parent){
			dfs(next , node , part ^ 1);
		}
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs(1 , 0 , 0);
	printf("%lld\n" , 1LL * cnt[0] * cnt[1] - n + 1LL);
}
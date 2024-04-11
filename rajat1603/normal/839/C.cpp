#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int a , b;
vector < int > v[N];
double dfs(int node , int parent){
	double sum = 0;
	int cnt = 0;
	for(int next : v[node]){
		if(next != parent){
			sum += dfs(next , node) + 1;
			++cnt;
		}
	}
	if(cnt){
		sum /= cnt;
	}
	return sum;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	printf("%.9lf\n" , dfs(1 , 0));
}
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
vector < int > comps;
int visited[N];
int arr[N];
long long ans;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &arr[i]);
		visited[i] = 0;
	}
	comps.clear();
	ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(visited[i]){
			continue;
		}
		int node = i;
		int siz = 0;
		do{
			++siz;
			visited[node] = 1;
			node = arr[node];
		}
		while(node != i);
		comps.emplace_back(siz);
		ans += 1LL * siz * siz;
	}
	if(comps.size() > 1){
		sort(comps.begin() , comps.end());
		ans += 2LL * comps[comps.size() - 1] * comps[comps.size() - 2];
	}
	printf("%lld\n" , ans);
}
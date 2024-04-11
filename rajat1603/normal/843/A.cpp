#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
pair < int , int > inp[N];
int arr[N];
int visited[N];
vector < vector < int > > ans;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &inp[i].first);
		inp[i].second = i;
	}
	sort(inp + 1 , inp + 1 + n);
	for(int i = 1 ; i <= n ; ++i){
		arr[inp[i].second] = i;
	}
	ans.clear();
	for(int i = 1 ; i <= n ; ++i){
		if(visited[i]){
			continue;
		}
		int node = i;
		ans.emplace_back(vector < int > ());
		do{
			visited[node] = 1;
			ans.back().emplace_back(node);
			node = arr[node];
		}while(node != i);
	}
	printf("%d\n" , int(ans.size()));
	for(auto it : ans){
		printf("%d" , int(it.size()));
		for(int x : it){
			printf(" %d" , x);
		}
		printf("\n");
	}
}
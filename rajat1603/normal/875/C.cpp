#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , m;
vector < int > arr[N];
vector < int > v[N];
vector < int > rv[N];
queue < pair < int , int > > s;
bool done[N];
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		int siz;
		scanf("%d" , &siz);
		arr[i].resize(siz);
		for(int j = 0 ; j < siz ; ++j){
			scanf("%d" , &arr[i][j]);
		}
	}
	for(int i = 1 ; i < n ; ++i){
		int s = min(arr[i].size() , arr[i + 1].size());
		int wtf = 0;
		int idx;
		for(int j = 0 ; j < s ; ++j){
			if(arr[i][j] != arr[i + 1][j]){
				if(arr[i][j] < arr[i + 1][j]){
					wtf = -1;
				}
				else{
					wtf = 1;
				}
				idx = j;
				break;
			}
		}
		if(wtf == 0){
			if(arr[i].size() > arr[i + 1].size()){
				printf("No\n");
				return 0;
			}
		}
		else{
			int a = arr[i][idx];
			int b = arr[i + 1][idx];
			v[a].emplace_back(b);
			rv[b].emplace_back(a);
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		for(int j : v[i]){
			if(j < i){
				s.push({i , j});
			}
		}
	}
	while(!s.empty()){
		auto it = s.front();
		s.pop();
		int a = it.first;
		int b = it.second;
		if(done[a] && !done[b]){
			continue;
		}
		if(!done[a] && done[b]){
			done[a] = 1;
			if(a > b){
				printf("No\n");
				return 0;
			}
			for(int x : rv[a]){
				if(x > a || !done[x]){
					s.push({x , a});
				}
			}
			continue;
		}
		if(a < b){
			continue;
		}
		if(done[a] && done[b]){
			printf("No\n");
			return 0;
		}
		done[a] = 1;
		for(int x : rv[a]){
			if(x > a || !done[x]){
				s.push({x , a});
			}
		}
	}
	vector < int > ans;
	for(int i = 1 ; i <= m ; ++i){
		if(done[i]){
			ans.emplace_back(i);
		}
	}
	printf("Yes\n");
	printf("%d\n" , int(ans.size()));
	for(int x : ans){
		printf("%d " , x);
	}
	printf("\n");
}
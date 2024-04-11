#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
int arr[N];
vector < int > v[N];
int indeg[N];
int outdeg[N];
vector < int > rv[N];
queue < int > a;
queue < int > b;
int ans;
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i <= m ; ++i){
		int a , b;
		scanf("%d %d" , &a , &b);
		++a;
		++b;
		v[a].emplace_back(b);
		++indeg[b];
		++outdeg[a];
		rv[b].emplace_back(a);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!outdeg[i]){
			if(arr[i]){
				b.push(i);
			}
			else{
				a.push(i);
			}
		}
	}
	while(!(a.empty() && b.empty())){
		while(!a.empty()){
			int node = a.front();
			a.pop();
			for(int prev : rv[node]){
				--outdeg[prev];
				if(!outdeg[prev]){
					if(arr[prev]){
						b.push(prev);
					}
					else{
						a.push(prev);
					}
				}
			}
		}
		if(!b.empty()){
			++ans;
			while(!b.empty()){
				int node = b.front();
				b.pop();
				for(int prev : rv[node]){
					--outdeg[prev];
					if(!outdeg[prev]){
						if(arr[prev]){
							b.push(prev);
						}
						else{
							a.push(prev);
						}
					}
				}
			}
		}
	}
	printf("%d\n" , ans);
}
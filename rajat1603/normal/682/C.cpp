#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
vector < pair < int , int > > v[N];
int ans;
int a , b;
void dfs(int node , int parent , long long dist , bool rekt , long long mn){
	mn = min(mn , dist);
	if(dist - mn > arr[node]){
		rekt = 1;
	}
	ans += rekt;
	for(auto it : v[node]){
		if(it.first != parent){
			dfs(it.first , node , dist + it.second , rekt , mn);
		}
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &arr[i]);
	}
	for(int i = 2 ; i <= n ; ++i){
		scanf("%d %d" , &a , &b);
		v[i].emplace_back(make_pair(a , b));
		v[a].emplace_back(make_pair(i , b));
	}
	dfs(1 , 0 , 0 , 0 , 0);
	cout << ans << endl;
}
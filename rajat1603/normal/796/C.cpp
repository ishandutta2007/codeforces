#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n;
int arr[N];
vector < int > v[N];
multiset < int > ms;
int ans;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		ms.insert(arr[i]);
	}
	for(int i = 1 ; i < n ; ++i){
		int a , b;
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	ans = 2e9 + 9;
	for(int i = 1 ; i <= n ; ++i){
		ms.erase(ms.find(arr[i]));
		int tmp = arr[i];
		for(int j : v[i]){
			ms.erase(ms.find(arr[j]));
			tmp = max(tmp , arr[j] + 1);
		}
		if(!ms.empty()){
			tmp = max(tmp , *prev(ms.end()) + 2);
		}
		for(int j : v[i]){
			ms.insert(arr[j]);
		}
		ms.insert(arr[i]);
		ans = min(ans , tmp);
	}
	printf("%d\n" , ans);
}
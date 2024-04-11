#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int arr[N];
int tin[N];
int pre[N];
int lst[N];
int val2[N];
int siz;
int a , b;
vector < int > v[N];
int ans[N];
int n;
int solve(){
	int suf = 0;
	int idx = siz;
	int res = pre[siz];
	while(idx){
		int tmp = lst[idx];
		suf = __gcd(suf , val2[idx]);
		res = max(res , __gcd(pre[tmp - 1] , suf));
		suf = __gcd(suf , tin[tmp]);
		idx = tmp - 1;
	}
	return res;
}
void dfs(int node , int parent){
	++siz;
	tin[siz] = arr[node];
	pre[siz] = __gcd(pre[siz - 1] , tin[siz]);
	if(pre[siz] == pre[siz - 1]){
		lst[siz] = lst[siz - 1];
		val2[siz] = __gcd(val2[siz - 1] , tin[siz]);
	}
	else{
		lst[siz] = siz;
		val2[siz] = 0;
	}
	ans[node] = solve();
	for(int next : v[node]){
		if(next != parent){
			dfs(next , node);
		}
	}
	pre[siz] = 0;
	tin[siz] = 0;
	--siz;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	siz = 0;
	pre[0] = 0;
	lst[0] = 0;
	dfs(1 , 0);
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , ans[i] , " \n"[i == n]);
	}
}
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SQN = 330;
int n , m;
int a[N];
int b[N];
int c[N];
int cnt[N];
int q;
int qu[N];
int qv[N];
int ans[N];
int parent[N];
int sz;
int buf[N];
vector < int > v[N];
map < int , int > mp[N];
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
void join(int a , int b){
	int x = find(a);
	int y = find(b);
	if(x != y){
		parent[y] = x;
		buf[++sz] = y;
	}
}
void solvebig(int color){
	for(int i : v[color]){
		join(a[i] , b[i]);
	}
	for(int i = 1 ; i <= q ; ++i){
		if(find(qu[i]) == find(qv[i])){
			++ans[i];
		}
	}
}
int arr[SQN * 2];
int siz;
void solvesmall(int color){
	for(int i : v[color]){
		join(a[i] , b[i]);
	}
	siz = 0;
	for(int i : v[color]){
		arr[++siz] = a[i];
		arr[++siz] = b[i];
	}
	sort(arr + 1 , arr + 1 + siz);
	siz = unique(arr + 1 , arr + 1 + siz) - arr - 1;
	for(int i = 1 ; i < siz ; ++i){
		for(int j = i + 1 ; j <= siz ; ++j){
			if(find(arr[i]) == find(arr[j])){
				++mp[arr[i]][arr[j]];
			}
		}
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , a + i , b + i , c + i);
		++cnt[c[i]];
		v[c[i]].emplace_back(i);
	}
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , qu + i , qv + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		parent[i] = i;
	}
	sz = 0;
	for(int i = 1 ; i <= m ; ++i){
		if(cnt[i] >= SQN){
			solvebig(i);
		}
		else{
			solvesmall(i);
		}
		for(int i = 1 ; i <= sz ; ++i){
			parent[buf[i]] = buf[i];
		}
		sz = 0;
	}
	for(int i = 1 ; i <= q ; ++i){
		printf("%d\n" , ans[i] + mp[min(qu[i] , qv[i])][max(qu[i] , qv[i])]);
	}
}
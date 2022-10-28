#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 12;
const int M = 1 << 14;
bitset < M + 5 > arr[N + 5];
int n , m;
char str[M + 5];
int ans;
int parent[M + M + 5];
int done[M + M + 5];
int what[M + M + 5];
int when;
inline int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
inline void join(int a , int b){
	int x = find(a);
	int y = find(b);
	if(x != y){
		parent[y] = x;
		--ans;
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str + 1);
		int idx = 1;
		for(int j = 1 ; j <= m ; j += 4){
			int num = 0;
			if(str[idx] >= '0' && str[idx] <= '9'){
				num = str[idx] - '0';
			}
			else{
				num = 10 + str[idx] - 'A';
			}
			if(num & 8){
				++ans;
				arr[i].set(j);
			}
			if(num & 4){
				++ans;
				arr[i].set(j + 1);
			}
			if(num & 2){
				++ans;
				arr[i].set(j + 2);
			}
			if(num & 1){
				++ans;
				arr[i].set(j + 3);
			}
			++idx;
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		parent[i] = i;
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			parent[j + m] = j + m;
		}
		for(int j = 1 ; j <= m ; ++j){
			if(i > 1 && arr[i].test(j) && arr[i - 1].test(j)){
				join(j , j + m);
			}
			if(j < m && arr[i].test(j) && arr[i].test(j + 1)){
				join(j + m , j + m + 1);
			}
		}
		for(int j = 1 ; j <= m + m ; ++j){
			find(j);
		}
		++when;
		for(int j = 1 ; j <= m ; ++j){
			int val = parent[j + m];
			assert(val >= 1);
			assert(val <= m + m);
			if(done[val] != when){
				done[val] = when;
				what[val] = j;
			}
		}
		for(int j = 1 ; j <= m ; ++j){
			parent[j] = what[parent[j + m]];
		}
	}
	printf("%d\n" , ans);
}
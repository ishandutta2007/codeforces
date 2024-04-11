#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 30;
int n , m , q;
int a[N] , b[N] , c[N];
int visited[N];
vector < int > v[N];
int x , y;
int pre[N];
int cur;
vector < int > basis[N];
vector < int > vals[N];
void dfs(int node , int last , int xo){
	pre[node] = xo;
	visited[node] = cur;
	for(int edge : v[node]){
		if(edge == last){
			continue;
		}
		int next = a[edge] ^ b[edge] ^ node;
		int val = c[edge];
		if(!visited[next]){
			dfs(next , edge , xo ^ val);
		}
		else{
			vals[cur].emplace_back(xo ^ pre[next] ^ val);
		}
	}
}
void gauss(int comp){
	for(int i = LN - 1 ; i >= 0 ; --i){
		int num = 0;
		for(int &x : vals[comp]){
			if(x & (1 << i)){
				if(!num){
					num = x;
					x = 0;
				}
				else{
					x ^= num;
				}
			}
		}
		if(num){
			basis[comp].emplace_back(num);
		}
	}
}
int query(int comp , int num){
	for(auto it : basis[comp]){
		if((num ^ it) < num){
			num ^= it;
		}
	}
	return num;
}
int main(){
	scanf("%d %d" , &n , &m);
	q = 1;
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , a + i , b + i , c + i);
		v[a[i]].emplace_back(i);
		v[b[i]].emplace_back(i);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!visited[i]){
			++cur;
			dfs(i , 0 , 0);
		}
	}
	for(int i = 1 ; i <= cur ; ++i){
		gauss(i);
	}
	while(q--){
		//scanf("%d %d" , &x , &y);
		x = 1;
		y = n;
		if(visited[x] != visited[y]){
			printf("XIT\n");
		}
		else{
			printf("%d\n" , query(visited[x] , pre[x] ^ pre[y]));
		}
	}
}
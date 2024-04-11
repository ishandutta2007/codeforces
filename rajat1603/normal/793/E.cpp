#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
int n;
int a , b , c , d;
vector < int > v[N];
int parent[N];
int subtree[N];
bitset < N > bit;
bool solve(int a , int b , int c){
	if(subtree[1] & 1){
		return 0;
	}
	int at , bt , ct;
	vector < int > tmp;
	tmp.clear();
	while(a > 1){
		at = a;
		a = parent[a];
		if(a > 1){
			for(int next : v[a]){
				if(next != at){
					tmp.emplace_back(subtree[next]);
				}
			}
		}
	}
	while(b > 1){
		bt = b;
		b = parent[b];
		if(b > 1){
			for(int next : v[b]){
				if(next != bt){
					tmp.emplace_back(subtree[next]);
				}
			}
		}
	}
	while(c > 1){
		ct = c;
		c = parent[c];
	}
	int target = (subtree[1] - 2) >> 1;
	target -= subtree[ct];
	if(target < 0){
		return 0;
	}
	for(int next : v[1]){
		if(next != at && next != bt && next != ct){
			tmp.emplace_back(subtree[next]);
		}
	}
	bit.reset();
	bit.set(0);
	for(int x : tmp){
		bit |= bit << x;
	}
	return bit.test(target);
}
int main(){
	scanf("%d" , &n);
	scanf("%d %d %d %d" , &a , &b , &c , &d);
	for(int i = 2 ; i <= n ; ++i){
		scanf("%d" , parent + i);
		v[parent[i]].emplace_back(i);
	}
	for(int i = n ; i >= 1 ; --i){
		if(v[i].empty()){
			subtree[i] = 1;
		}
		else{
			subtree[i] = 0;
			for(int j : v[i]){
				subtree[i] += subtree[j];
			}
		}
	}
	if((solve(a , b , c) && solve(c , d , b)) || (solve(a , b , d) && solve(d , c , b))){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int ans1[N];
int ans2[N];
bool rip = 0;
void solve1(vector < int > &pos , vector < int > &val , int bit){
	if(rip){
		return;
	}
	if(pos.size() > val.size()){
		rip = 1;
		return;
	}
	if(pos.size() == 1){
		ans1[pos[0]] = val.back();
		val.pop_back();
		return;
	}
	vector < int > p[2] , v[2];
	p[0].clear();
	p[1].clear();
	v[0].clear();
	v[1].clear();
	for(int x : pos){
		p[(x >> bit) & 1].emplace_back(x);
	}
	for(int x : val){
		v[(x >> bit) & 1].emplace_back(x);
	}
	solve1(p[1] , v[0] , bit + 1);
	if(rip){
		return;
	}
	if(v[0].size() > v[1].size()){
		val.swap(v[0]);
		for(int x : v[1]){
			val.emplace_back(x);
		}
	}
	else{
		val.swap(v[1]);
		for(int x : v[0]){
			val.emplace_back(x);
		}
	}
	solve1(p[0] , val , bit + 1);
}
void put(vector < int > &v){
	for(int i = 0 ; i < v.size() ; ++i){
		ans2[v[i]] = v[(i + 1) % v.size()];
	}
}
void solve2(vector < int > &p , int bit){
	if(p.size() == 7){ 
		ans2[p[0]] = 3;
		ans2[p[1]] = 6;
		ans2[p[2]] = 1;
		ans2[p[3]] = 5;
		ans2[p[4]] = 4;
		ans2[p[5]] = 7;
		ans2[p[6]] = 2;
		return;
	}
	vector < int > one;
	one.clear();
	vector < int > zero;
	zero.clear();
	for(int x : p){
		if((x >> bit) & 1){
			one.emplace_back(x);
		}
		else{
			zero.emplace_back(x);
		}
	}
	put(one);
	solve2(zero , bit - 1);
}
int main(){
	scanf("%d" , &n);
	vector < int > a , b;
	a.clear();
	b.clear();
	for(int i = 1 ; i <= n ; ++i){
		a.emplace_back(i);
		b.emplace_back(i);
	}
	solve1(a , b , 0);
	if(n == 1){
		rip = 1;
	}
	if(rip){
		printf("NO\n");
	}
	else{
		printf("YES\n");
		for(int i = 1 ; i <= n ; ++i){
			printf("%d " , ans1[i]);
		}
		printf("\n");
	}
	if(n <= 5){
		printf("NO\n");
		return 0;
	}
	if((n & -n) == n){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if(n == 6){
		printf("3 6 2 5 1 4\n");
		return 0;
	}
	a.clear();
	for(int i = 1 ; i <= n ; ++i){
		a.emplace_back(i);
	}
	solve2(a , 20);
	for(int i = 1 ; i <= n ; ++i){
		printf("%d " , ans2[i]);
	}
	printf("\n");
}
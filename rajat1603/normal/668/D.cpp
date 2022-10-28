#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
map < int , int > m1 , m2;
int v1 = 0 , v2 = 0;
int n;
int type[N];
int timer[N];
int val[N];
vector < pair < int , int > > v[N];
int bit[N];
int ans[N];
void update(int idx , int val){
	while(idx <= v1){
		bit[idx] += val;
		idx += idx & -idx;
	}
}
void clear(int idx){
	while(idx <= v1){
		bit[idx] = 0;
		idx += idx & -idx;
	}
}
int query(int idx){
	int res = 0;
	while(idx){
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}
int main(){
	m1.clear();
	m2.clear();
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d" , type + i , timer + i , val + i);
		m1[timer[i]];
		m2[val[i]];
	}
	for(auto &it : m1){
		it.second = ++v1;
	}
	for(auto &it : m2){
		it.second = ++v2;
	}
	for(int i = 1 ; i <= n ; ++i){
		timer[i] = m1[timer[i]];
		val[i] = m2[val[i]];
	}
	for(int i = 1 ; i <= n ; ++i){
		ans[i] = -1;
		v[val[i]].emplace_back(make_pair(type[i] + ((type[i] == 3) ? i : 0) , timer[i]));
	}
	for(int i = 1 ; i <= v2 ; ++i){
		for(auto it : v[i]){
			if(it.first == 1){
				update(it.second , 1);
			}
			else if(it.first == 2){
				update(it.second , -1);
			}
			else{
				ans[it.first - 3] = query(it.second);
			}
		}
		for(auto it : v[i]){
			clear(it.second);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(ans[i] != -1){
			printf("%d\n" , ans[i]);
		}
	}
}
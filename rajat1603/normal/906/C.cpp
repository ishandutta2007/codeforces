#include "bits/stdc++.h"
using namespace std;
const int N = 25;

int bitcnt[1 << 13];
inline int bitcount(int x){
	return bitcnt[x & 4095] + bitcnt[x >> 12];
}
int n , m;
int graph[N];
int k;
int perm[N];


bool done[N];

int tmp[N];
int sz;


int ans;
int print[N];

void solve(){
	int who = -1;
	int val = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(done[i]){
			continue;
		}
		sz = 0;
		for(int j = 1 ; j <= n ; ++j){
			if((graph[i] >> j) & 1){
				tmp[++sz] = j;
			}
		}
		int cur = (sz * (sz - 1));
		for(int j = 1 ; j <= sz ; ++j){
			cur -= bitcount(graph[i] & graph[tmp[j]]);
		}
		if(cur > val){
			val = cur;
			who = i;
		}
	}
	if(val == 0){
		for(int i = 1 ; i <= n ; ++i){
			if(bitcount(graph[i]) != n - 1){
				return;
			}
		}
		if(k < ans){
			ans = k;
			for(int i = 1 ; i <= k ; ++i){
				print[i] = perm[i];
			}
		}
		return;
	}
	if(k + 1 >= ans){
		return;
	}
	perm[++k] = who;
	int old[N];
	for(int i = 1 ; i <= n ; ++i){
		old[i] = graph[i];
	}
	for(int i = 1 ; i <= n ; ++i){
		if((graph[who] >> i) & 1){
			graph[i] |= graph[who];
			graph[i] &= ~(1 << i);
		}
	}
	done[who] = 1;
	solve();
	perm[k--] = 0;
	for(int i = 1 ; i <= n ; ++i){
		graph[i] = old[i];
	}
	solve();
	done[who] = 0;
}



int main(){
	bitcnt[0] = 0;
	for(int i = 1 ; i < (1 << 13) ; ++i){
		bitcnt[i] = bitcnt[i >> 1] + (i & 1);
	}
	scanf("%d %d" , &n , &m);
	memset(graph , 0 , sizeof(graph));
	for(int i = 1 ; i <= m ; ++i){
		int a , b;
		scanf("%d %d" , &a , &b);
		graph[a] |= 1 << b;
		graph[b] |= 1 << a;
	}
	ans = n;
	for(int i = 1 ; i <= n ; ++i){
		print[i] = i;
	}
	solve();
	printf("%d\n" , ans);
	for(int i = 1 ; i <= ans ; ++i){
		printf("%d " , print[i]);
	}
	printf("\n");
}
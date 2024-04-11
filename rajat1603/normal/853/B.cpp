#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const long long inf = 1e17 + 17;
int n , m , k;
int day[N] , a[N] , b[N] , cst[N];
vector < int > v[N];
long long pre[N];
long long suf[N + 1];
long long bst[N];
int done;
int when1 , when2;
long long ans;
int main(){
	scanf("%d %d %d" , &n , &m , &k);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d %d" , day + i , a + i , b + i , cst + i);
		v[day[i]].emplace_back(i);
	}
	pre[0] = 0;
	done = 0;
	when1 = N;
	for(int i = 1 ; i <= n ; ++i){
		bst[i] = inf;
	}
	for(int i = 1 ; i < N ; ++i){
		pre[i] = pre[i - 1];
		for(int edge : v[i]){
			if(b[edge] == 0){
				int node = a[edge];
				if(bst[node] == inf){
					++done;
					bst[node] = cst[edge];
					pre[i] += cst[edge];
				}
				else if(cst[edge] < bst[node]){
					pre[i] -= bst[node];
					pre[i] += cst[edge];
					bst[node] = cst[edge];
				}
			}
		}
		if(done == n){
			when1 = min(when1 , i);
		}
	}
	when2 = 0;
	done = 0;
	suf[N] = 0;
	for(int i = 1 ; i <= n ; ++i){
		bst[i] = inf;
	}
	for(int i = N - 1 ; i > 0 ; --i){
		suf[i] = suf[i + 1];
		for(int edge : v[i]){
			if(a[edge] == 0){
				int node = b[edge];
				if(bst[node] == inf){
					++done;
					bst[node] = cst[edge];
					suf[i] += cst[edge];
				}
				else if(cst[edge] < bst[node]){
					suf[i] -= bst[node];
					suf[i] += cst[edge];
					bst[node] = cst[edge];
				}
			}
		}
		if(done == n){
			when2 = max(when2 , i);
		}
	}
	ans = inf;
	for(int i = when1 ; i + k + 1 <= when2 ; ++i){
		ans = min(ans , pre[i] + suf[i + k + 1]);
	}
	if(ans >= inf){
		ans = -1;
	}
	printf("%lld\n" , ans);
}
#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int mod = 1e9 + 7;
int m , n;
char str[N];
vector < int > v[N << 2];
int cur;
int bell[N];
int ncr[N];
int main(){
	scanf("%d %d" , &m , &n);
	cur = 1;
	for(int i = 1 ; i <= m ; ++i){
		v[1].emplace_back(i);
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str + 1);
		for(int j = cur ; j >= 1 ; --j){
			int zero = 0;
			int one = 0;
			for(int x : v[j]){
				if(str[x] == '0'){
					zero = 1;
				}
				if(str[x] == '1'){
					one = 1;
				}
			}
			if(zero && one){
				for(int x : v[j]){
					if(str[x] == '0'){
						v[cur + 1].emplace_back(x);
					}
					else{
						v[cur + 2].emplace_back(x);
					}
				}
				v[j].clear();
				v[j].swap(v[cur + 2]);
				++cur;
			}
		}
	}
	bell[0] = 1;
	ncr[0] = 1;
	for(int i = 1 ; i <= m ; ++i){
		for(int k = 1 ; k <= i ; ++k){
			bell[i] = (bell[i] + 1LL * bell[i - k] * ncr[k - 1]) % mod;
		}
		for(int j = i ; j >= 1 ; --j){
			ncr[j] += ncr[j - 1];
			ncr[j] -= (ncr[j] >= mod) * mod;
		}
	}
	int ans = 1;
	for(int i = 1 ; i <= cur ; ++i){
		ans = (1LL * ans * bell[v[i].size()]) % mod;
	}
	printf("%d\n" , ans);
}
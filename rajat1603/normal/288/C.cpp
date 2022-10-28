#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int SN = 1 << 22;
int n;
int siz[SN];
long long tot;
int ans[N];
void insert(int num){
	int node = 1;
	for(int i = 19 ; i >= 0 ; --i){
		node += node + ((num >> i) & 1);
		++siz[node];
	}
}
void erase(int num){
	int node = 1;
	for(int i = 19 ; i >= 0 ; --i){
		node += node + ((num >> i) & 1);
		--siz[node];
	}
}
int get(int num){
	int node = 1;
	int res = 0;
	for(int i = 19 ; i >= 0 ; --i){
		if((num >> i) & 1){
			if(siz[node + node]){
				node += node;
			}
			else{
				node += node + 1;
				res |= 1 << i;
			}
		}
		else{
			if(siz[node + node + 1]){
				node += node + 1;
				res |= 1 << i;
			}
			else{
				node += node;
			}
		}
	}
	return res;
}
int main(){
	scanf("%d" , &n);
	for(int i = 0 ; i <= n ; ++i){
		insert(i);
	}
	for(int i = n ; i >= 0 ; --i){
		ans[i] = get(i);
		tot += ans[i] ^ i;
		erase(ans[i]);
	}
	printf("%lld\n" , tot);
	for(int i = 0 ; i <= n ; ++i){
		printf("%d%c" , ans[i] , " \n"[i == n]);
	}
}
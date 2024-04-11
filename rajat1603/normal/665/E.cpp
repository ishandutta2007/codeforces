#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int LN = 30;
int n , k;
int arr[N];
int trie[LN * N];
int lft[LN * N];
int rgt[LN * N];
int cur = 1;
int prexor = 0;
long long ans = 0;
void insert(int val){
	int node = 1;
	++trie[node];
	for(int i = LN - 1 ; i >= 0 ; --i){
		bool bit = (val >> i) & 1;
		if(bit){
			if(!rgt[node]){
				rgt[node] = ++cur;
			}
			node = rgt[node];
		}
		else{
			if(!lft[node]){
				lft[node] = ++cur;
			}
			node = lft[node];
		}
		++trie[node];
	}
}
int query(int num){
	int node = 1;
	int res = 0;
	for(int i = LN - 1 ; i >= 0 ; --i){
		bool bit = (k >> i) & 1;
		bool bit2 = (num >> i) & 1;
		if(bit && bit2){
			if(!lft[node]){
				return res;
			}
			node = lft[node];
		}
		else if(!(bit || bit2)){
			res += (rgt[node] ? trie[rgt[node]] : 0);
			if(!lft[node]){
				return res;
			}
			node = lft[node];
		}
		else if(bit && (!bit2)){
			if(!rgt[node]){
				return res;
			}
			node = rgt[node];
		}
		else{
			res += (lft[node] ? trie[lft[node]] : 0);
			if(!rgt[node]){
				return res;
			}
			node = rgt[node];
		}
	}
	res += trie[node];
	return res;
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	insert(0);
	for(int i = 1 ; i <= n ; ++i){
		prexor ^= arr[i];
		ans += query(prexor);
		insert(prexor);
	}
	printf("%lld\n" , ans);
}
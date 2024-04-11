#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int primes[19] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67};
const int LN = 19;
const int mod = 1e9 + 7;
int n , b;
int inp;
int basis[LN];
void insert(int x){
	for(int i = LN - 1 ; i >= 0 && x > 0 ; --i){
		if(!((x >> i) & 1)){
			continue;
		}
		if(basis[i]){
			x ^= basis[i];
		}
		else{
			basis[i] = x;
			++b;
			break;
		}
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &inp);
		int x = 0;
		for(int j = 0 ; j < 19 ; ++j){
			int cnt = 0;
			while(inp % primes[j] == 0){
				cnt ^= 1;
				inp /= primes[j];
			}
			if(cnt){
				x |= 1 << j;
			}
		}
		insert(x);
	}
	int ans = 1;
	for(int i = 0 ; i < n - b ; ++i){
		ans = (ans << 1) % mod;
	}
	--ans;
	printf("%d\n" , ans);
}
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
char str[N];
int n;
int ans[N];
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int base = 33;
int pw1[N];
int pw2[N];
int inv1[N];
int inv2[N];
int hash1[N];
int hash2[N];
inline int add(int a , int b , int mod){
	int res = a + b;
	if(res >= mod){
		return res - mod;
	}
	return res;
}
inline int mult(int a , int b , int mod){
	long long res = a;
	res *= b;
	if(res >= mod){
		return res % mod;
	}
	return res;
}
inline int power(int a , int b , int mod){
	int res = 1;
	while(b){
		if(b & 1){
			res = mult(res , a , mod);
		}
		a = mult(a , a , mod);
		b >>= 1;
	}
	return res;
}
void build(){
	pw1[0] = 1;
	pw2[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		pw1[i] = mult(pw1[i - 1] , base , mod1);
		pw2[i] = mult(pw2[i - 1] , base , mod2);
	}
	int tmp1 = power(base , mod1 - 2 , mod1);
	int tmp2 = power(base , mod2 - 2 , mod2);
	inv1[0] = 1;
	inv2[0] = 1;
	for(int i = 1 ; i <= n ; ++i){
		inv1[i] = mult(inv1[i - 1] , tmp1 , mod1);
		inv2[i] = mult(inv2[i - 1] , tmp2 , mod2);
	}
	hash1[0] = 0;
	hash2[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		hash1[i] = add(hash1[i - 1] , mult(pw1[n - i] , str[i] - 'a' + 1 , mod1) , mod1);
		hash2[i] = add(hash2[i - 1] , mult(pw2[n - i] , str[i] - 'a' + 1 , mod2) , mod2);
	}
}
inline pair < int , int > gethash(int x , int y){
	int res1 = hash1[y];
	res1 = add(res1 , mod1 - hash1[x - 1] , mod1);
	res1 = mult(res1 , inv1[n - y] , mod1);
	int res2 = hash2[y];
	res2 = add(res2 , mod2 - hash2[x - 1] , mod2);
	res2 = mult(res2 , inv2[n - y] , mod2);
	return {res1 , res2};
}
inline int lcp(int x , int y){
	if(str[x] != str[y]){
		return 0;
	}
	int l = 1;
	int r = n - max(x , y) + 1;
	while(l < r){
		int mid = l + r + 1 >> 1;
		if(gethash(x , x + mid - 1) == gethash(y , y + mid - 1)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	return l;
}
int main(){
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	build();
	for(int i = 1 ; i <= n ; ++i){
		ans[i] = lcp(1 , i);
	}
	int len = 0;
	int mx = 0;
	int before;
	for(int i = 2 ; i <= n ; ++i){
		int idx = i + ans[i] - 1;
		if(idx == n){
			if(mx >= ans[i]){
				if(ans[i] > len){
					len = ans[i];
					before = i;
				}
			}
		}
		mx = max(mx , ans[i]);
	}
	int start;
	for(int i = 2 ; i < before ; ++i){
		if(ans[i] >= len){
			start = i;
			break;
		}
	}
	if(len < 1){
		printf("Just a legend\n");
	}
	else{
		for(int j = start ; j < start + len ; ++j){
			printf("%c" , str[j]);
		}
		printf("\n");
	}
}
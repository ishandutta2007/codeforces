#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SQN = 105;
int n , mod;
int arr[N];
int q;
int l , r;
int okay(long long val , int mod){
	if(val < mod){
		return val;
	}
	return (val % mod) + mod;
}
int power(int a , int b , int mod){
	int res = 1;
	while(b){
		if(b & 1){
			res = okay(1LL * res * a , mod);
		}
		a = okay(1LL * a * a , mod);
		b >>= 1;
	}
	return res;
}
int phi(int n){
    int res = n;
    for(int i = 2 ; i * i <= n ; ++i){
    	if(n % i == 0){
    		res /= i;
    		res *= i - 1;
    		while(n % i == 0){
    			n /= i;
    		}
    	}
    }
    if(n > 1){
        res /= n;
        res *= n - 1;
    }
    return res;
}
int mods[SQN];
int sz;
int get(int l , int r , int cur){
	if(cur == sz){
		return 1;
	}
	if(l == r){
		return okay(arr[l] , mods[cur]);
	}
	return power(arr[l] , get(l + 1 , r , cur + 1) , mods[cur]);
}
int main(){
	scanf("%d %d" , &n , &mod);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	scanf("%d" , &q);
	mods[0] = mod;
	sz = 0;
	while(mods[sz] != 1){
		++sz;
		mods[sz] = phi(mods[sz - 1]);
	}
	while(q--){
		scanf("%d %d" , &l , &r);
		printf("%d\n" , get(l , r , 0) % mod);
	}
}
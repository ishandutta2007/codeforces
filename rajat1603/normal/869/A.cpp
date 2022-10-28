#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 22;
int n;
int a[N];
int b[N];
int there[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , a + i);
		there[a[i]] = 1;
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , b + i);
		there[b[i]] = 1;
	}
	int tot = 0;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			tot ^= there[a[i] ^ b[j]];
		}
	}
	printf(tot ? "Koyomi\n" : "Karen\n");
}
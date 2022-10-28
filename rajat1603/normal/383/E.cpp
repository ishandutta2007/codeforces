#include "bits/stdc++.h"
using namespace std;
const int N = 24;
const int P = 1 << N;
int n;
char str[5];
int sum[P];
int ans;
int main(){
	scanf("%d" , &n);
	for(int i = 0 ; i < n ; ++i){
		scanf("%s" , str);
		int val = 0;
		for(int j = 0 ; j < 3 ; ++j){
			val |= 1 << (str[j] - 'a');
		}
		++sum[val];
	}
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < P ; ++j){
			if((j >> i) & 1){
				sum[j] += sum[j ^ (1 << i)];
			}
		}
	}
	for(int i = 0 ; i < P ; ++i){
		ans ^= (n - sum[i]) * (n - sum[i]);
	}
	printf("%d\n" , ans);
}
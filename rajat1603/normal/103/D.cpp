#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int SQN = 500;
int n;
int arr[N];
int q;
int a[N];
int b[N];
vector < int > v[SQN];
long long ans[N];
long long tmp[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , a + i , b + i);
		if(b[i] >= SQN){
			ans[i] = 0;
			for(int j = a[i] ; j <= n ; j += b[i]){
				ans[i] += arr[j];
			}
		}
		else{
			v[b[i]].emplace_back(i);
		}
	}
	for(int b = 1 ; b < SQN ; ++b){
		if(!v[b].empty()){
			for(int j = n ; j >= 1 ; --j){
				tmp[j] = arr[j] + (((j + b) <= n) ? tmp[j + b] : 0);
			}
			for(int idx : v[b]){
				ans[idx] = tmp[a[idx]];
			}
		}
	}
	for(int i = 1 ; i <= q ; ++i){
		printf("%lld\n" , ans[i]);
	}
}
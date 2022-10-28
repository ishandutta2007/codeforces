#include "bits/stdc++.h"
using namespace std;
const int N = 605;
int t;
int n , m;
int arr1[2][N];
int inp;
int sqr(int x){
	return x * x;
}
int main(){
	scanf("%d" , &t);
	while(t--){
		scanf("%d %d" , &n , &m);
		vector < int > v;
		v.resize(n + 1);
		for(int i = 1 ; i <= n ; ++i){
			int sum = 0;
			for(int j = 1 ; j <= m ; ++j){
				scanf("%d" , &arr1[i & 1][j]);
				sum += sqr(arr1[i & 1][j] - arr1[!(i & 1)][j]);
			}
			if(i > 1){
				v[i - 1] = sum;
			}
		}
		if(v[n >> 1] > 300000){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}
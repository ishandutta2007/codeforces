#include "bits/stdc++.h"
using namespace std;
const int N = 1e9;
int n , m;
int val;
vector < int > ans;
unsigned arr[1 + (N >> 5)];
int main(){
	scanf("%d %d" , &n , &m);
	while(n--){
		scanf("%d" , &val);
		arr[val >> 5] |= 1u << (val & 31);
	}
	for(int i = 1 ; i <= m ; ++i){
		if(!(arr[i >> 5] & (1u << (i & 31)))){
			ans.emplace_back(i);
			m -= i;
		}
	}
	printf("%d\n" , int(ans.size()));
	for(int x : ans){
		printf("%d " , x);
	}
}
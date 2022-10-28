#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
int n;
int l , r;
pair < int , int > arr[N];
int cur;
int main(){
	scanf("%d" , &n);
	cur = 0;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , &l , &r);
		arr[++cur] = make_pair(l , 1);
		arr[++cur] = make_pair(r + 1 , -1);
	}
	sort(arr + 1 , arr + 1 + cur);
	int sum = 0;
	for(int i = 1 ; i <= cur ; ++i){
		sum += arr[i].second;
		if(sum > 2){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}
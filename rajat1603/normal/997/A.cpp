#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n , rev , flip;
char arr[N];
int tot;
long long ans;
int main(){
	scanf("%d %d %d" , &n , &rev , &flip);
	scanf("%s" , arr + 1);
	tot = 0;
	arr[n + 1] = '1';
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] == '1'){
			continue;
		}
		int j = i;
		while(arr[j + 1] == '0'){
			++j;
		}
		++tot;
		i = j;
	}
	if(!tot){
		printf("0\n");
		return 0;
	}
	ans = 1LL << 60;
	for(int i = 0 ; i < tot ; ++i){
		ans = min(ans , 1LL * i * rev + 1LL * (tot - i * 1LL) * flip);
	}
	printf("%lld\n" , ans);
}
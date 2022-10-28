#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int g;
int main(){
	scanf("%d" , &n);
	g = 0;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		g = __gcd(g , arr[i]);
	}
	if(g > 1){
		printf("YES\n0\n");
		return 0;
	}
	int ans = 0;
	for(int i = 1 ; i < n ; ++i){
		int x = arr[i];
		int y = arr[i + 1];
		bool a = x & 1;
		if(a){
			arr[i] = x - y;
			arr[i + 1] = x + y;
			++ans;
			--i;
		}
	}
	if(arr[n] & 1){
		ans += 2;
	}
	printf("YES\n%d\n" , ans);
}
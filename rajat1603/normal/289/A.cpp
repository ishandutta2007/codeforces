#include "bits/stdc++.h"
using namespace std;
int n , k;
int ans;
int l , r;
int main(){
	scanf("%d %d" , &n , &k);
	while(n--){
		scanf("%d %d" , &l , &r);
		ans += r - l + 1;
		ans %= k;
	}
	printf("%d\n" , (k - ans) % k);
}
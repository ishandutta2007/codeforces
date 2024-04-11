#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , h , k;
int arr[N];
long long ans;
int cur;
int pos;
int main(){
	scanf("%d %d %d" , &n , &h , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	ans = 0;
	cur = 0;
	pos = 1;
	while(pos <= n){
		if(arr[pos] + cur <= h){
			cur += arr[pos++];
		}
		else{
			ans += cur / k;
			cur %= k;
			if(arr[pos] + cur > h){
				++ans;
				cur = 0;
			}
		}
	}
	ans += (cur + k - 1) / k;
	cout << ans;
}
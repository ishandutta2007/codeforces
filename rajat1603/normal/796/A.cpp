#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m , k;
int arr[N];
int ans;
int main(){
	scanf("%d %d %d" , &n , &m , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	ans = N;
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] && arr[i] <= k){
			ans = min(ans , abs(i - m));
		}
	}
	ans *= 10;
	cout << ans << endl;
}
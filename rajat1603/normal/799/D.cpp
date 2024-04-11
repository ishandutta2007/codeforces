#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e9 + 9;
const long long mxx = 1e15 + 15;
int n;
int arr[N];
int dp[N];
vector < long long > v;
int solve(int a , int b , int h , int w){
	if(a <= h && b <= w){
		return 0;
	}
	for(int i = 0 ; i < N ; ++i){
		dp[i] = 0;
	}
	dp[1] = 1;
	h = (a + h - 1) / h;
	w = (b + w - 1) / w;
	long long prod = 1;
	int res = inf;
	v.clear();
	for(int i = 1 ; i <= n ; ++i){
		for(int j = N - 1 ; j >= 0 ; --j){
			if(1LL * j * arr[i] < N){
				dp[arr[i] * j] |= dp[j];
			}
			else if(dp[j]){
				v.emplace_back(1LL * arr[i] * j);
			}
		}
		if(prod <= mxx / arr[i] + 5){
			prod *= arr[i];
		}
		else{
			prod = mxx;
		}
		prod = min(prod , mxx);
		for(int j = h ; j < N ; ++j){
			if(1LL * j * w <= prod){
				if(dp[j]){
					res = i;
					i = n + 1;
					break;
				}
			}
		}
		for(long long j : v){
			if(j >= h){
				if(1LL * j * w <= prod){
					res = i;
					i = n + 1;
					break;
				}
			}
		}
	}
	return res;
}
int main(){
	int a , b;
	int h , w;
	scanf("%d %d %d %d" , &a , &b , &h , &w);
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	sort(arr + 1 , arr + 1 + n);
	reverse(arr + 1 , arr + 1 + n);
	n = min(n , 40);
	int ans = min(solve(a , b , h , w) , solve(b , a , h , w));
	if(ans >= inf){
		ans = -1;
	}
	printf("%d\n" , ans);
}
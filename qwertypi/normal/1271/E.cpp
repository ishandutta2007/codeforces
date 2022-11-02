#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
int test(int u){
	if(u == 0){
		return n;
	}
	int l = u, r = u + (u % 2 == 0);
	int res = 0;
	while(l <= n){
		res += min(r, n) - l + 1;
		l *= 2;
		r = r * 2 + 1;
	}
	return res;
}

int32_t main(){
	cin >> n >> k;
	int odd, even;
	int upper = n / 2;
	int lower = 0;
	while(upper != lower){
		int mid = (upper + lower + 1) / 2;
		if(test(mid * 2) < k){
			upper = mid - 1;
		}else{
			lower = mid;
		}
	}
	even = lower * 2;
	upper = n / 2 + n % 2;
	lower = 0;
	while(upper != lower){
		int mid = (upper + lower + 1) / 2;
		if(test(mid * 2 - 1) < k){
			upper = mid - 1;
		}else{
			lower = mid;
		}
	}
	odd = lower * 2 - 1;
	cout << max(odd, even) << endl;
}
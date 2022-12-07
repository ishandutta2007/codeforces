#include <bits/stdc++.h>

using namespace std;

int solve(int x, vector < int > &vec){
	int n = vec.size();
	int ans = 0;

	for(int mask = 1; mask < (1 << n); ++mask){
		int cur = 1;
		for(int i = 0; i < n; ++i){
			if(mask & (1 << i)) cur = cur * vec[i]; 
		}
		if(__builtin_popcount(mask) % 2) ans += x / cur;
		else ans -= x / cur;
	}

	return x - ans;
}

int main(){

	int t;
	scanf("%d", &t);

	while(t--){
		int x, p, k;
		scanf("%d%d%d", &x, &p, &k);
	
		vector < int > pr;

		for(int i = 2; i * i <= p; ++i){
			if(p % i == 0){
				pr.push_back(i);
			}
			while(p % i == 0) p /= i;
		}

		if(p > 1) pr.push_back(p);

		int low = x, high = 1e9, ans = 1e9;

		while(low <= high){
			int mid = (low + high) >> 1;

			if(solve(mid, pr) - solve(x, pr) >= k){
				ans = mid;
				high = mid - 1;
			}
			else{
				low = mid + 1;
			}
		}	

		printf("%d\n", ans);
	}

	return 0;
}
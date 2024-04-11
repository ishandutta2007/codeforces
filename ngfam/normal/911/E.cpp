#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int n, k, sz;
int a[N];
int f[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; ++i){
		scanf("%d", a + i);
	}

	set < int > avail;

	for(int i = 1; i <= n; ++i){
		avail.insert(i);
	}

	int x = 0;

	for(int i = 1; i <= k; ++i){
		if(a[i] < x) {
			cout << -1;
			exit(0);
		}

		while(sz > 0 && a[i] > f[sz]){
			x = max(x, f[sz--]);
		}

		f[++sz] = a[i];
		avail.erase(a[i]);
	}

	for(int i = k + 1; i <= n; ++i){
		int low = 1, high = n, ans = -1;

		while(low <= high){
			int mid = (low + high) >> 1;


			if(mid > *avail.rbegin()) {
				high = mid - 1;
				continue;
			}

			int curr = *avail.lower_bound(mid);

			int lo = 1, hi = sz, ret = 0;

			while(lo <= hi){
				int m = (lo + hi) >> 1;
				if(f[m] < curr){
					ret = f[m];
					hi = m - 1;
				}
				else{
					lo = m + 1;
				}
			}



			int now = max(ret, x);
			if(!avail.empty() && now > *avail.begin()){
				high = mid - 1;
			}
			else{
				ans = curr;
				low = mid + 1;
			}

		}

		if(ans == -1){
			cout << -1;
			return 0;
		}

		a[i] = ans;
		avail.erase(ans);
	
	    
	  while(sz > 0 && a[i] > f[sz]) {
	    x = max(x, f[sz--]);
	  }
	  f[++sz] = a[i];
	}

	for(int i = 1; i <= n; ++i){
		printf("%d ", a[i]);
	}

	return 0;
}
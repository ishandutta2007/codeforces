#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, x, k;
long long a[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d%d", &n, &x, &k);

	for(int i = 1; i <= n; ++i){
		scanf("%lld", a + i);
	} 
	sort(a + 1, a + n + 1);

	long long ans = 0;

	for(int i = 1; i <= n; ++i){


		long long first = a[i] - a[i] % x;

		first += 1LL * (k - (a[i] % x == 0)) * x;
		long long last = first + x - 1;
		first = max(first, a[i]);


		int l = lower_bound(a + 1, a + n + 1, first) - a;
		int r = upper_bound(a + 1, a + n + 1, last) - a;
		ans += (r - l);
	}

	cout << ans;

	return 0;
}
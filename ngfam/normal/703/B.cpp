#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

const int N = 123456;

llint c[N], ans;

int n, k, cap[N], a[N], b[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	llint sum = 0;

	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", c + i);
		sum += c[i];
	}

	if(n == 2){
		cout << c[1] * c[2];
		return 0;
	}

	for(int i = 1; i <= k; ++i){
	 	int val; scanf("%d", &val);
	 	cap[val] = 1;
	}

	for(int i = 1; i <= n; ++i){
		a[i] = i - 1;
		b[i] = i + 1;
	}

	a[1] = n; b[n] = 1;

	llint sumcap = 0;

	for(int i = 1; i <= n; ++i){
		if(cap[i]){
			ans += (sum - c[i]) * c[i];
		//	if(i == n && cap[1]) ans += c[i] * c[1];
		//	cout << i << " " << sum - c[i] - c[a[i]] - sumcap << endl;
		}
		else{
                	ans += c[i] * (c[b[i]] + c[a[i]]);
                }
	}

//	cout << ans << endl;

	for(int i = 1; i <= n; ++i){
		if(cap[i] == 0) continue;
		ans -= c[i] * sumcap;
		sumcap += c[i];
	}
	
//	cout << ans << endl;

	for(int i = 1; i <= n; ++i){
	//	ans -= c[i] * c[a[i]];
		if(!cap[i] || !cap[a[i]]){
			ans -= c[i] * c[a[i]];
		}
	}

	cout << ans;

	return 0;	
}
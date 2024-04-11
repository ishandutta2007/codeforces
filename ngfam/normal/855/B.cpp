#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, p, q, r;
int a[N];
int preMin[N];
int preMax[N];
int sufMin[N];
int sufMax[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d%d%d", &n, &p, &q, &r);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	preMin[0] = sufMin[n + 1] = 1e9 + 1;
	sufMax[n + 1] = preMax[0] = -preMin[0];

	for(int i = 1; i <= n; ++i){
		preMin[i] = min(preMin[i - 1], a[i]);
		preMax[i] = max(preMax[i - 1], a[i]);
	}

	long long ans = -3e18 - 10;

	for(int i = n; i >= 1; --i){
		sufMin[i] = min(sufMin[i + 1], a[i]);
		sufMax[i] = max(sufMax[i + 1], a[i]);
	}

	for(int i = 1; i <= n; ++i){
		long long tot = 1LL * q * a[i];
		if(p < 0) tot += 1LL * p * preMin[i];
		else tot += 1LL * p * preMax[i];
		if(r < 0) tot += 1LL * r * sufMin[i];
		else tot += 1LL * r * sufMax[i];

		ans = max(ans, tot);
	}

	cout << ans;

	return 0;
}
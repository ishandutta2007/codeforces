#include <bits/stdc++.h>

using namespace std;

const int N = 70;
const int Base = 11;
const int Mask = 1 << 10;

int a[N];
long long f[Base][N][Mask];

long long solve(long long x, int base){
	if(x == 0) return 0;

	int n = 0;

	while(x > 0){
		a[++n] = x % base;
		x /= base;
	}

	reverse(a + 1, a + n + 1);

	int mask = 0;
	long long ans = 0;

	for(int len = 1; len < n; ++len){
		for(int c = 1; c < base; ++c) ans += f[base][len - 1][1 << c];
	}

	for(int i = 0; i < n; ++i){
		if(i > 0) mask ^= (1 << a[i]);
		for(int c = (i == 0); c < a[i + 1]; ++c){
			ans += f[base][n - i - 1][mask ^ (1 << c)];
		}
	}


	mask ^= (1 << a[n]);

	return ans + (mask == 0);
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	for(int base = 2; base <= 10; ++base){
		f[base][0][0] = 1;

		for(int i = 1; i <= 64; ++i){
			for(int last = 0; last < (1 << base); ++last){
				if(f[base][i - 1][last] == 0) continue;
				for(int c = 0; c < base; ++c){
					f[base][i][last ^ (1 << c)] += f[base][i - 1][last];
				}
			}
		}
	}




	int q;
	scanf("%d", &q);

	while(q--){
		int b;
		long long l, r;
		scanf("%d%lld%lld",  &b, &l, &r);

		printf("%lld\n", solve(r, b) - solve(l - 1, b));
	}

	return 0;
}
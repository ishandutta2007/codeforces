#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int f[N];
int cnt[N][11];

int main(){

	for(int i = 1; i < N; ++i){
		if(i < 10){
			f[i] = i;
			continue;
		}

		int prod = 1, tmp = i;

		while(tmp > 0){
			int x = tmp % 10;
			tmp /= 10;
			if(x) prod *= x;
		}
		f[i] = f[prod];
	}

	for(int i = 1; i < N; ++i){
		for(int j = 1; j <= 10; ++j){
			cnt[i][j] = cnt[i - 1][j];
		}
		++cnt[i][f[i]];
	}

	int q;
	scanf("%d", &q);

	while(q--){
		int l, r, k;

		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", cnt[r][k] - cnt[l - 1][k]);
	}

	return 0;
}
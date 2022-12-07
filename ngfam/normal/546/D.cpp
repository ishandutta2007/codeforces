#include <bits/stdc++.h>

using namespace std;

const int P = 5e6 + 1;

int prime[P], calc[P];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	for(int i = 2; i < P; ++i){
		if(prime[i] > 0) continue;
		for(int j = i; j < P; j += i){
			prime[j] = i;
		}
	}

	for(int i = 1; i < P; ++i){
		int val = i;
		while(val != 1){
			int node = prime[val];
			while(val % node == 0){
				++calc[i];
				val /= node;
			}
		}
	}
	
	for(int i = 1; i < P; ++i){
		calc[i] += calc[i - 1];
	}

	int t; scanf("%d", &t);

	while(t--){
		int a, b; scanf("%d%d", &a, &b);
		printf("%d\n", calc[a] - calc[b]);
	}

	return 0;
}
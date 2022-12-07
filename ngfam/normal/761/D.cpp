#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int a[N], inv[N], n, l, r, can[N], b[N], biggest, fr[N], to[N], c[N];

map < int, bool > used;

bool cmp(int u, int v){
	return inv[u] < inv[v];
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &l, &r);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		//to[i] = r - a[i];
	}
	for(int i = 1; i <= n; ++i){
		scanf("%d", inv + i);
		can[i] = i;
	}
	sort(can + 1, can + n + 1, cmp);

	int least = -1e9 - 1;

	for(int i = 1; i <= n; ++i){
		int idx = can[i];
		b[idx] = max(l, least + a[idx] + 1);
		if(b[idx] > r){
			puts("-1");
			return 0;
		}
		least = max(least, b[idx] - a[idx]);
	}

	for(int i = 1; i <= n; ++i){
		printf("%d ", b[i]);
	}
	return 0;
}
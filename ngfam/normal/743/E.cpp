#include <bits/stdc++.h>

using namespace std;

const int N = 1234, M = 1 << 8;

int a[N], f[N][M], n, ok[10], ans;
vector < int > pos[10];

int check(int val){
	memset(f, -1, sizeof f);
	f[0][0] = 0;

	int result = -1;

	for(int i = 0; i <= n; ++i){
		for(int mask = 0; mask < M; ++mask){
			if(f[i][mask] == -1) continue;

			for(int c = 1; c <= 8; ++c){
				if(mask & (1 << (c - 1))) continue;
				int newmask = mask | (1 << (c - 1));

				int fin = upper_bound(pos[c].begin(), pos[c].end(), i) - pos[c].begin();
				if(pos[c].size() - fin < val) continue;

				int u = pos[c][fin + val - 1];
				f[u][newmask] = max(f[u][newmask], f[i][mask]);

				if(pos[c].size() - fin > val){
					int v = pos[c][fin + val];
					f[v][newmask] = max(f[v][newmask], f[i][mask] + 1);
				}
			}
			if(mask == M - 1) result = max(result, f[i][mask]);
		}
	}
	return result;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		pos[a[i]].push_back(i);

		ans += (!ok[a[i]]);
		ok[a[i]] = 1;
	}

	int low = 1, high = n;

	while(low <= high){
		int val = (low + high) >> 1;

		int now = check(val);
		if(now != -1){
			low = val + 1;
			ans = max(ans, val * 8 + now);
		}
		else{
			high = val - 1;
		}
	}

	cout << ans;

	return 0;
}
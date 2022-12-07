#include <bits/stdc++.h>

using namespace std;

const int N = 345678;

int n, a[N];

struct query{
	int a[N], f[N][20], ok;

	int combine(int u, int v){
		if(ok == 1) return __gcd(u, v);
		return min(u, v);
	}

	void build(){
		memset(f, -1, sizeof f);
		
		for(int i = 1; i <= n; ++i){
			f[i][0] = a[i];
		}

		for(int j = 1; j <= 20; ++j){
			for(int i = 1; i <= n; ++i){
				if(i + (1 << j) - 1 > n) break;
				f[i][j] = combine(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	int ask(int l, int r){
		int lgr = log2(r - l + 1);
		return combine(f[l][lgr], f[r - (1 << lgr) + 1][lgr]);
	}
}gcd, rmin;


vector < int > ok(int val){
	vector < int > result;
	for(int i = 1; i <= n - val + 1; ++i){
		if(gcd.ask(i, i + val - 1) == rmin.ask(i, i + val - 1)){
		//	return i;
			result.push_back(i);
		}
	}
	return result;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	gcd.ok = 1;

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		gcd.a[i] = a[i];
		rmin.a[i] = a[i];
	}

	gcd.build(); rmin.build();

	int ans = 0, low = 1, high = n;

	while(low <= high){
		int val = (low + high) >> 1;
		if(ok(val).size() > 0){
			ans = val;
			low = val + 1;
		}
		else{
			high = val - 1;
		}
	}

	vector < int > can = ok(ans);

	printf("%d %d\n", int(can.size()), ans - 1);
	for(int i = 0; i < can.size(); ++i){
		printf("%d ", can[i]);
	}

	return 0;
}
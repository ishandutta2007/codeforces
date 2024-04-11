#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 3e5 + 85 - 75;
int Min[maxn * 4], GCD[maxn * 4];
int a[maxn], n;

void make(int L = 0, int R = n, int id = 1){
	if(R - L == 1){
		Min[id] = a[L];
		GCD[id] = a[L];
		return;
	}
	int mid = (L + R) >> 1;
	make(L, mid, id * 2 + 0);
	make(mid, R, id * 2 + 1);
	Min[id] = min(Min[id * 2 + 0], Min[id * 2 + 1]);
	GCD[id] = __gcd(GCD[id * 2 + 0], GCD[id * 2 + 1]);
}

pie get(int l, int r, int L = 0, int R = n, int id = 1){
	if(l == L and r == R)
		return MP(GCD[id], Min[id]);
	pie x = MP(0, 1e9), y;
	int mid = (L + R) >> 1;
	if(l < mid){
		y = get(l, min(mid, r), L, mid, id * 2 + 0);
		x.L = __gcd(x.L, y.L);
		x.R = min(x.R, y.R);
	}
	if(r > mid){
		y = get(max(l, mid), r, mid, R, id * 2 + 1);
		x.L = __gcd(x.L, y.L);
		x.R = min(x.R, y.R);
	}
	return x;
}

int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	make();
	int lo = 1, hi = n + 1;
	while(hi - lo > 1){
		int sz = (lo + hi) >> 1;
		bool x = false;
		for(int i = 0; i + sz <= n; i++){
			pie y = get(i, i + sz);
			if(y.L == y.R){
				x = true;
				break;
			}
		}
		if(x)
			lo = sz;
		else
			hi = sz;
	}
	vector<int> ans;
	for(int i = 0; i + lo <= n; i++){
		pie y = get(i, i + lo);
		if(y.L == y.R)
			ans.PB(i + 1);
	}
	printf("%d %d\n", (int)ans.size(), lo - 1);
	for(int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
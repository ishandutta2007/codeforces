#include <bits/stdc++.h>

using namespace std;

const int N = 35050;
const int K = 55;

int n, k;
int a[N];
int last[N];
int f[N][K];

struct SegmentTree{
	int it[N * 8];
	int lazy[N * 8];

	#define ii (i << 1)
	#define mid ((l + r) >> 1)

	void solve(int i){
		if(lazy[i] != 0){
			it[i] += lazy[i];
			lazy[ii] += lazy[i];
			lazy[ii + 1] += lazy[i];
		}
		lazy[i] = 0;
	}

	void upd(int i, int l, int r, int x, int y, int val){
		solve(i);
		if(l > y || r < x){
			return;
		}
		if(l >= x && r <= y){
			lazy[i] += val;
			solve(i);
			return;
		}
		upd(ii, l, mid, x, y, val);
		upd(ii + 1, mid + 1, r, x, y, val);
		it[i] = max(it[ii], it[ii + 1]);
	}

	int ask(){
		return it[1];
	}
}Smt[K];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
	#endif
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}
	memset(f, -1, sizeof f);
	for(int i = 1; i <= n; ++i){
		if(last[a[i]] != 0){
			for(int j = 0; j <= k; ++j){
				Smt[j].upd(1, 0, n, 0, last[a[i]] - 1, -1);
			}
		}
		for(int j = 0; j <= k; ++j){
			Smt[j].upd(1, 0, n, 0, i - 1, 1);
		}
		last[a[i]] = i;
		for(int j = 1; j <= min(i, k); ++j){
			f[i][j] = Smt[j - 1].ask();
		}
		for(int j = 1; j <= k; ++j){
			Smt[j].upd(1, 0, n, i, i, f[i][j]);
		}
		/*cout << Smt[0].ask() << endl;
		if(i == 2){
			break;
		}*/
	}
	//cout << f[3][1] << endl;
	cout << f[n][k];
	return 0;	
}
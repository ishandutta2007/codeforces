//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define InF (1000000LL * 1000000 * 1000000)
#undef plus
#define plus PlUs

const int maxn = 2e5 + 85 - 69;
LL seg[maxn * 4], plus[maxn * 4];
vector<pll> quer[maxn];
LL a[maxn], dp[maxn];
int n, m;

void add(LL val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg[id] += val;
		plus[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	add(val, st, en, l, mid, id * 2 + 0);
	add(val, st, en, mid, r, id * 2 + 1);
	seg[id] = max(seg[id * 2 + 0], seg[id * 2 + 1]) + plus[id];
	return;
}

LL get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return -InF;
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return max(get(st, en, l, mid, id * 2 + 0),
			get(st, en, mid, r, id * 2 + 1)) + plus[id];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%I64d", a + i);
	for(int i = 0; i < m; i++){
		int fi, se;
		LL val;
		scanf("%d%d%I64d", &fi, &se, &val);
		quer[fi - 1].PB(MP(se - 1, val));
	}
	for(int i = n - 1; i >= 0; i--){
		dp[i] = dp[i + 1];
		add(-a[i], i, n);
		for(auto qu : quer[i])
			add(qu.R, qu.L, n);
		smax(dp[i], get(i, n));
		if(i)
			add(dp[i], i - 1, i);
	}
	printf("%I64d", dp[0]);
	return 0;
}
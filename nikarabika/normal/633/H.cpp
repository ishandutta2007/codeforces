//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 30 * 1000 + 100,
	  maxsq = 200;
int seg_shift[maxn * 4],
	ql[maxn],
	qr[maxn],
	ord[maxn],
	cnt[maxn];
int fibarr[maxn * 10 + 100],
   seg_sum0[maxn * 4],
   seg_sum1[maxn * 4],
   a[maxn],
   ans[maxn],
   n, Mod, q;
int *fib = fibarr + maxn * 5 + 50;
vector<int> all;

bool cmp(int i, int j){
	if(ql[i] / maxsq == ql[j] / maxsq)
		return qr[i] < qr[j];
	return ql[i] < ql[j];
}

int FIBO(int x, int y, int idx){
	return (x * fib[idx] + (y - x) * fib[idx - 1]) % Mod;
}

void pull(int id){
	int x = (seg_sum0[id * 2 + 0] + seg_sum0[id * 2 + 1]) % Mod,
	   y = (seg_sum1[id * 2 + 0] + seg_sum1[id * 2 + 1]) % Mod;
	seg_sum0[id] = FIBO(x, y, seg_shift[id]);
	seg_sum1[id] = FIBO(x, y, seg_shift[id] + 1);
	return;
}

void seg_doshift(int val, int id){
	seg_shift[id] += val;
	int x = seg_sum0[id],
	   y = seg_sum1[id];
	seg_sum0[id] = FIBO(x, y, val);
	seg_sum1[id] = FIBO(x, y, val + 1);
	return;
}

void seg_add(int idx, int l = 0, int r = sz(all), int id = 1){
	if(idx < l or idx >= r){
		if(idx < l)
			seg_doshift(+1, id);
		return;
	}
	if(r - l == 1){
		seg_sum0[id] = (all[idx] * fib[seg_shift[id]]) % Mod;
		seg_sum1[id] = (all[idx] * fib[seg_shift[id] + 1]) % Mod;
		return;
	}
	int mid = (l + r) >> 1;
	seg_add(idx, l, mid, id * 2 + 0);
	seg_add(idx, mid, r, id * 2 + 1);
	pull(id);
	return;
}

void seg_rem(int idx, int l = 0, int r = sz(all), int id = 1){
	if(idx < l or idx >= r){
		if(idx < l)
			seg_doshift(-1, id);
		return;
	}
	if(r - l == 1){
		seg_sum0[id] = seg_sum1[id] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	seg_rem(idx, l, mid, id * 2 + 0);
	seg_rem(idx, mid, r, id * 2 + 1);
	pull(id);
	return;
}

void add(int idx){
	if(!(cnt[idx]++)) seg_add(idx);
	return;
}

void remove(int idx){
	if(!(--cnt[idx])) seg_rem(idx);
	return;
}

int main(){
	scanf("%d%d", &n, &Mod);
	fib[0] = fib[1] = 1;
	for(int i = 2; i <= maxn * 5; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % Mod;
	for(int i = -1; i >= -maxn * 5; i--)
		fib[i] = (fib[i + 2] - fib[i + 1]) % Mod;
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
		all.PB(a[i]);
	}
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
		scanf("%d%d", ql + i, qr + i), ql[i]--, qr[i]--, ord[i] = i;
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < n; i++)
		a[i] = lower_bound(all(all), a[i]) - all.begin();
	for(int i = 0; i < sz(all); i++)
		all[i] %= Mod;
	sort(ord, ord + q, cmp);
	int st = 0, en = -1;
	for(int i = 0; i < q; i++){
		int l = ql[ord[i]], r = qr[ord[i]];
		while(st > l)
			add(a[--st]);
		while(en < r)
			add(a[++en]);
		while(st < l)
			remove(a[st++]);
		while(en > r)
			remove(a[en--]);
		ans[ord[i]] = (seg_sum0[1] + Mod) % Mod;
	}
	for(int i = 0; i < q; i++)
		printf("%d ", ans[i]);
	return 0;
}
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

const int maxn = 2e5 + 85 - 69;
const LL Mod = 1000LL * 1000 * 1000;
LL fibarr[maxn * 2 + 10], sumarr[maxn * 2 + 10], arr[maxn];
LL *fib, *sum;
LL seg0[maxn * 4], seg1[maxn * 4], laz[maxn * 4];
LL f0, f1;
int n, q;

LL Fib(int idx, LL a, LL b){
	return (((fib[idx] * a) % Mod) + ((fib[idx - 1] * ((b - a) % Mod)) % Mod)) % Mod;
}

void push(int, int, int);

void pull(int id){
	seg0[id] = (seg0[id * 2 + 0] + seg0[id * 2 + 1]) % Mod;
	seg1[id] = (seg1[id * 2 + 0] + seg1[id * 2 + 1]) % Mod;
	return;
}

void build(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		seg0[id] = (arr[l] * fib[l - n]) % Mod;
		seg1[id] = (arr[l] * fib[l - n + 1]) % Mod;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	pull(id);
	return;
}

void get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st <= l and r <= en){
		f0 = (f0 + seg0[id]) % Mod;
		f1 = (f1 + seg1[id]) % Mod;
		return;
	}
	if(laz[id])push(l, r, id);
	int mid = (l + r) >> 1;
	if(st < mid)
		get(st, min(mid, en), l, mid, id * 2 + 0);
	if(en > mid)
		get(max(st, mid), en, mid, r, id * 2 + 1);
	return;
}

void modify0(int idx, LL val, int l = 0, int r = n, int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		seg0[id] = (val * fib[l - n]) % Mod;
		seg1[id] = (val * fib[l - n + 1]) % Mod;
		return;
	}
	if(laz[id])push(l, r, id);
	int mid = (l + r) >> 1;
	modify0(idx, val, l, mid, id * 2 + 0);
	modify0(idx, val, mid, r, id * 2 + 1);
	pull(id);
	return;
}

void modify1(LL val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg0[id] += (val * ((sum[r - n] - sum[l - n]) % Mod)) % Mod;
		seg0[id] %= Mod;
		seg1[id] += (val * ((sum[r - n + 1] - sum[l - n + 1]) % Mod)) % Mod;
		seg1[id] %= Mod;
		laz[id] = (laz[id] + val) % Mod;
		return;
	}
	if(laz[id])push(l, r, id);
	int mid = (l + r) >> 1;
	modify1(val, st, en, l, mid, id * 2 + 0);
	modify1(val, st, en, mid, r, id * 2 + 1);
	pull(id);
	return;
}

void push(int l, int r, int id){
	int mid = (l + r) >> 1;
	modify1(laz[id], l, mid, l, mid, id * 2 + 0);
	modify1(laz[id], mid, r, mid, r, id * 2 + 1);
	laz[id] = 0;
	return;
}

int main(){
	fib = fibarr + maxn + 5;
	sum = sumarr + maxn + 5;
	fib[1] = 1;
	for(int i = 2; i < maxn; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % Mod;
	for(int i = 1; i < maxn; i++)
		fib[-i] = (fib[-i + 2] - fib[-i + 1]) % Mod;
	for(int i = -maxn + 1; i + 1 < maxn; i++)
		sum[i + 1] = (sum[i] + fib[i]) % Mod;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++)
		scanf("%I64d", arr + i);
	build();
	while(q--){
		int ty;
		LL fi, se, th;
		scanf("%d%I64d%I64d", &ty, &fi, &se);
		fi--;
		if(ty == 1)
			modify0(fi, se);
		else if(ty == 2){
			f0 = f1 = 0;
			get(fi, se);
			//cout << "Negar " << f0 << ' ' << f1 << endl;
			printf("%I64d\n", (((Fib(n - fi + 2, f0, f1) % Mod) + Mod) % Mod));
			//cout << ((Fib(n - fi + 2, f0, f1) % Mod) + Mod) % Mod << endl;
		}
		else{
			scanf("%I64d", &th);
			modify1(th, fi, se);
		}
	}
	return 0;
}
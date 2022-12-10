#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pii;
typedef pair<pii, LL> piii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())

const int maxn = 2e5 + 85 - 69;
const int maxval = 1e6 + 85 - 69;
const LL Mod = 1e9 + 7;
vector<int> facts[maxval];
bool rev_filled[maxval];
LL rev[maxval];
LL seg1[maxn * 4], seg2[maxn * 7 * 4];
LL a[maxn];
int n, q;
LL ans[maxn], sttime[maxn], fitime[maxn];
LL adss[maxval], last[maxn * 7];
vector<LL> vec;
piii quer[maxn];

void build1(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		seg1[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build1(l, mid, id * 2 + 0);
	build1(mid, r, id * 2 + 1);
	seg1[id] = (seg1[id * 2 + 0] * seg1[id * 2 + 1]) % Mod;
	return;
}

LL get1(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return 1;
	if(st <= l and r <= en)
		return seg1[id];
	int mid = (l + r) >> 1;
	return (get1(st, en, l, mid, id * 2 + 0) * get1(st, en, mid, r, id * 2 + 1)) % Mod;
}

void modify2(int idx, LL val, int l = 0, int r = sz(vec), int id = 1){
	if(idx < l or idx >= r)
		return;
	if(r - l == 1){
		seg2[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	modify2(idx, val, l, mid, id * 2 + 0);
	modify2(idx, val, mid, r, id * 2 + 1);
	seg2[id] = (seg2[id * 2 + 0] * seg2[id * 2 + 1]) % Mod;
	return;
}

LL get2(int st, int en, int l = 0, int r = sz(vec), int id = 1){
	if(st >= r or en <= l)
		return 1;
	if(st <= l and r <= en)
		return seg2[id];
	int mid = (l + r) >> 1;
	return (get2(st, en, l, mid, id * 2 + 0) * get2(st, en, mid, r, id * 2 + 1)) % Mod;
}

bool cmp(piii x, piii y){
	return x.L.R < y.L.R;
}

void find_primes(void){
	for(int i = 2; i < maxval; i++)
		if(facts[i].size() == 0)
			for(int j = i; j < maxval; j += i)
				facts[j].PB(i);
	return;
}

LL Pow(LL x, LL y){
	LL ret = 1, an = x;
	for(int i = 0; y; i++, an = (an * an) % Mod)
		if((y >> i) & 1LL)
			ret = (ret * an) % Mod, y ^= (1LL << i);
	return ret;
}

LL Div(LL x, LL y){
	return (x * Pow(y, Mod - 2)) % Mod;
}

LL Rev(LL x){
	if(rev_filled[x])
		return rev[x];
	rev_filled[x] = true;
	return rev[x] = Div(1, x);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(adss, -1, sizeof adss);
	find_primes();
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sttime[i] = sz(vec);
		for(auto f : facts[a[i]]){
			last[sz(vec)] = adss[f];
			adss[f] = sz(vec);
			vec.PB(f);
		}
		fitime[i] = sz(vec);
	}
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> quer[i].L.L >> quer[i].L.R;
		quer[i].L.L--;
		quer[i].R = i;
	}
	sort(quer, quer + q, cmp);
	build1();
	int p = 0;
	for(int i = 0; i < q; i++){
		while(p < quer[i].L.R){
			for(int j = sttime[p]; j < fitime[p]; j++){
				modify2(last[j], 1);
				modify2(j, ((vec[j] - 1) * Rev(vec[j])) % Mod);
			}
			p++;
		}
		ans[quer[i].R] = (get1(quer[i].L.L, quer[i].L.R) * get2(sttime[quer[i].L.L], fitime[quer[i].L.R - 1])) % Mod;
	}
	for(int i = 0; i < q; i++)
		cout << ans[i] << '\n';
	return 0;
}
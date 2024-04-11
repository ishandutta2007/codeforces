#include <cstdio>
#include <cstring>
#include <algorithm>

#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair < ll, ll > pll;

const int N = 1e5 + 500;
const int OFF = (1 << 17);

struct node{
	node *L, *R;
	ll sm_m, sm_r;
	node(){
		L = NULL, R = NULL;
		sm_m = 0, sm_r = 0;
	}
	node(node* LL, node* RR, ll sm_mm, ll sm_rr){
		L = LL, R = RR, sm_m = sm_mm, sm_r = sm_rr;
	}
};

typedef node* pnode;

inline pnode L(pnode x){
	if(x == NULL) return NULL;
	return x -> L;
}

inline pnode R(pnode x){
	if(x == NULL) return NULL;
	return x -> R;
}

inline ll sm_m(pnode x){
	if(x == NULL) return 0;
	return x -> sm_m;
}

inline ll sm_r(pnode x){
	if(x == NULL) return 0;
	return x -> sm_r;
}

void update(pnode &x, int a, int b, int i, ll dod_m, ll dod_r){
	pnode nw = new node(L(x), R(x), sm_m(x), sm_r(x));
	nw -> sm_m += dod_m; 
	nw -> sm_r += dod_r;
	x = nw;
	if(a == b) return;
	if(i <= (a + b) / 2)
		update(x -> L, a, (a + b) / 2, i, dod_m, dod_r);
	else
		update(x -> R, (a + b) / 2 + 1, b, i, dod_m, dod_r);
}

pll add(pll A, pll B){
	return {A.X + B.X, A.Y + B.Y};
}

pll query(pnode str, pnode nov, int a, int b, int cut){
	if(a > cut)
		return {sm_r(nov) - sm_r(str), 0};
	if(b <= cut)
		return {0, sm_m(nov) - sm_m(str)};
	return add(query(L(str), L(nov), a, (a + b) / 2, cut), query(R(str), R(nov), (a + b) / 2 + 1, b, cut));
}

pnode per[N];
int s[N], m[N], r[N], n;
int uklj[2 * OFF];

ll query2(int i, int a, int b, int lo, int hi, int tme){
	if(lo <= a && b <= hi && uklj[i] != -1){
		pll res = query(per[a - 1], per[b], 0, OFF - 1, tme - uklj[i]);
		ll fin = res.X * (tme - uklj[i]) + res.Y;  uklj[i] = -1;
		return fin;
	}
	if(a > hi || b < lo) return 0;
	if(a == b && uklj[i] == -1)
		return min((ll)m[a], (ll)r[a] * tme + s[a]);
	if(uklj[i] != -1){
		uklj[2 * i] = uklj[i];
		uklj[2 * i + 1] = uklj[i];
		uklj[i] = -1;
	}
	return query2(2 * i, a, (a + b) / 2, lo, hi, tme) + query2(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, tme);
}

void postavi(int i, int a, int b, int lo, int hi, int tme){
	if(lo <= a && b <= hi){
		uklj[i] = tme; return;
	}
	if(a > hi || b < lo) return;
	postavi(2 * i, a, (a + b) / 2, lo, hi, tme);
	postavi(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, tme);
}

int main(){
	memset(uklj, -1, sizeof(uklj));
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d", s + i, m + i, r + i);
		per[i] = per[i - 1];
		if(r[i])
			update(per[i], 0, OFF - 1, (m[i] / r[i]) + 1, m[i], r[i]);
	}
	int q; scanf("%d", &q);
	for(;q--;){
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		printf("%lld\n", query2(1, 0, OFF - 1, l, r, t));
		postavi(1, 0, OFF - 1, l, r, t);
	}
	return 0;
}
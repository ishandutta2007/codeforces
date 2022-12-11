#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(time(0));

bool prim(int x){
	for(int i = 2; i * i <= x; i ++ )
		if(x % i == 0)
			return false;
	return true;
}

int gen_mod(){
	int ret = rnd() % (int)1e8 + 124214121;
	while(!prim(ret))
		-- ret;
	return ret;
}

const int MOD = gen_mod();
const int N = (int)1e5 + 9;
const int P = 10;

int powrp[N];
int hsh[N];
int pref[N];


struct Node{
	int lazy;
	int value;
};

int calc_sum(int l, int r){
	int ret = pref[r];
	if(l > 0)
		ret = (ret - pref[l - 1] + MOD) % MOD;
	return ret;
}

struct Tree{
	int nsize;
	Node T[4000000];

	void build(int node, int cl, int cr){
		T[node].lazy = -1;
		if(cl == cr){
			T[node].value = hsh[cl];
			return;
		}
		int md = (cl + cr)/2;
		build(node * 2, cl, md);
		build(node * 2 + 1, md + 1, cr);
		T[node].value = (T[node * 2].value + T[node * 2 + 1].value) % MOD;
	}
	
	void push(int node, int cl, int cr){
		if(T[node].lazy != -1){
			T[node].value = (1ll * calc_sum(cl, cr) * T[node].lazy) % MOD;
			if(cl != cr){
				T[node * 2].lazy = T[node].lazy;
				T[node * 2 + 1].lazy = T[node].lazy;
			}
			T[node].lazy = -1;
		}
	}
	
	void update(int node, int cl, int cr, int tl, int tr, int vl){
		push(node, cl, cr);
		if(cr < tl)
			return;
		if(cl > tr)
			return;
		if(cl >= tl && cr <= tr){
			T[node].lazy = vl;
			push(node, cl, cr);
			return;
		}
		int md = (cl + cr) / 2;
		update(node * 2, cl, md, tl, tr, vl);
		update(node * 2 + 1, md + 1, cr, tl, tr, vl);
		T[node].value = (T[node * 2].value + T[node * 2 + 1].value ) % MOD;
	}
	
	int ask(int node, int cl, int cr, int tl, int tr){
		push(node, cl, cr);
		if(cr < tl)
			return 0;
		if(cl > tr)
			return 0;
		if(cl >= tl && cr <= tr){
			return T[node].value;
		}
		int md = (cl + cr) / 2;
		return (ask(node * 2, cl, md, tl, tr) + ask(node * 2 + 1, md + 1, cr, tl, tr)) % MOD;
	}
	
	void Init(int n){
		nsize = n;
		build(1, 0, n - 1);
	}
};

Tree hashes;

int inv[N];

int powr(int n, int k){
	if(k == 0)
		return 1;
	int ret = powr(n, k/2);
	ret = (ret * 1ll * ret) % MOD;
	if(k & 1)
		ret = (ret * 1ll * n) % MOD;
	return ret;
}

int calchash(int cl, int cr){
	int sum = hashes.ask(1, 0, hashes.nsize - 1, cl, cr);
	if(cl != 0)
		sum = (sum * 1ll * inv[cl - 1]) % MOD;
	return sum;
}

int main(){
	fastIO;
	int n, m, k ;
	cin >> n >> m >> k;
	int q = m + k;
	powrp[0] = 1ll;
	pref[0] = 1ll;
	for(int i = 1; i <= n; i ++ ){
		powrp[i] = (powrp[i - 1] * 1ll * P) % MOD;
		pref[i] = (pref[i - 1] + powrp[i]) % MOD;
	}
	char dig;
	int vl;
	
	int ip = powr(P, MOD - 2);
	int mult = 1;
	for(int i = 0 ; i < n; i ++ ){
		mult = (mult * 1ll * ip) % MOD;
		inv[i] = mult;
	}
	for(int i = 0; i < n; i ++ ){
		cin >> dig;
		vl = dig - '0';
		hsh[i] = (1ll * vl * powrp[i]) % MOD;
	}
	hashes.Init(n);
	int t, l, r, x;
	for(int i = 0 ; i < q; i ++ ){
		cin >> t >> l >> r >> x;
		-- l, -- r;
		if(t == 1){
			hashes.update(1, 0, n - 1, l, r, x);
		}
		else{
			if(r - l + 1 == x){
				cout << "YES\n";
			}
			else{
				if(calchash(l, r - x) == calchash(l + x, r)){
					cout << "YES\n";
				}
				else{
					cout << "NO\n";
				}
			}
		}
	}
	return 0;
}
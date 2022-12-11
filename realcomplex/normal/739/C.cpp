#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define int ll

struct Node{
	int sz;
	int lazy;
	ll fir;
	ll las;
	int best;
	int maxpref;
	int maxsuff;
	int isuff;
	int dpref;
};

Node merge(Node &a, Node &b){
	Node res;
	res.lazy = 0;
	res.sz = a.sz + b.sz;
	res.fir = a.fir;
	res.las = b.las;
	res.best = max(a.best, b.best);
	res.maxpref = a.maxpref;
	res.maxsuff = b.maxsuff;
	res.isuff = b.isuff;
	res.dpref = a.dpref;
	if(a.las < b.fir){
		if(b.maxsuff == b.sz){
			res.maxsuff = a.isuff + b.sz;
		}
		if(b.isuff == b.sz){
			res.isuff = a.isuff + b.sz;
		}
		if(a.isuff == a.sz){ 
			res.maxpref = a.sz + b.maxpref;
		}
		res.best = max(res.best, a.isuff + b.maxpref);
	}
	else if(a.las > b.fir){
		if(a.dpref == a.sz){
			res.dpref = a.sz + b.dpref;
		}
		if(b.dpref == b.sz){
			res.maxsuff = a.maxsuff + b.dpref;
		}
		if(a.maxpref == a.sz){
			res.maxpref = a.sz + b.dpref;
		}
		res.best = max(res.best, a.maxsuff + b.dpref);
	}
	return res;
}
Node T[2000000];
void push(int node, int cl, int cr){
	T[node].fir += T[node].lazy;
	T[node].las += T[node].lazy;
	if(cl != cr){
		T[node * 2].lazy += T[node].lazy;
		T[node * 2 + 1].lazy += T[node].lazy;
	}
	T[node].lazy = 0;
}

void update(int node, int cl, int cr, int tl, int tr, int ad){
	push(node, cl, cr);
	if(cr < tl)
		return;
	if(cl > tr)
		return;
	if(cl >= tl && cr <= tr){
		T[node].lazy = ad;
		push(node, cl, cr);
		return;
	}
	int mid = (cl + cr) / 2;
	update(node * 2, cl, mid, tl, tr, ad);
	update(node * 2 + 1, mid + 1, cr, tl, tr, ad);
	T[node] = merge(T[node * 2], T[node * 2 + 1]);
}

const int N = (int)3e5 + 9;
ll ff[N];

void build(int node, int cl, int cr){
	if(cl == cr){
		T[node] = {1, 0, ff[cl], ff[cl], 1, 1, 1, 1, 1};  
		return;
	}
	int mid = (cl + cr) / 2;
	build(node * 2, cl, mid);
	build(node * 2 + 1, mid + 1, cr);
	T[node] = merge(T[node * 2], T[node * 2 + 1]);
}

signed main(){
	fastIO;
	int n;
	cin >> n;
	for(int i = 0;i < n; i ++ ){
		cin >> ff[i];
	}
	build(1, 0, n - 1);
	int q;
	cin >> q;
	int li, ri;
	ll xi;
	for(int i = 0 ;i  < q; i ++ ){
		cin >> li >> ri >> xi;
		-- li, -- ri;
		update(1, 0, n-1, li, ri, xi);
		cout << T[1].best << "\n";
	}
	return 0;
}
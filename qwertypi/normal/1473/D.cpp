#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)
using namespace std;

struct Node{
	int s, psg, pss;
	int operator() (){
		return max(0LL, psg - pss + 1);
	}
};

Node merge(Node a, Node b){
	if(a.s == -inf || b.s == -inf) return (a.s == -inf ? b : a);
	Node res;
	res.s = a.s + b.s;
	res.psg = max(0LL, max(a.psg, a.s + b.psg));
	res.pss = min(0LL, min(a.pss, a.s + b.pss));
	return res;
}

int n, m;
Node T[200000 * 4];
string S;

void build(int t = 1, int l = 0, int r = n - 1){
	if(l == r){
		int v = S[l] == '+' ? 1 : -1;
		T[t] = {v, max(0LL, v), min(0LL, v)};
		return;
	}
	int m = (l + r) >> 1;
	build(t << 1, l, m);
	build(t << 1 | 1, m + 1, r);
	T[t] = merge(T[t << 1], T[t << 1 | 1]);
}

Node query(int l, int r, int t = 1, int tl = 0, int tr = n - 1){
	if(l > r) return {-inf};
	if(l <= tl && tr <= r){
		return T[t];
	}
	int tm = (tl + tr) >> 1;
	return merge(query(l, min(r, tm), t << 1, tl, tm), query(max(l, tm + 1), r, t << 1 | 1, tm + 1, tr));
}

void solve(){
	cin >> n >> m;
	cin >> S;
	build();
	for(int i = 0; i < m; i++){
		int l, r; cin >> l >> r; l--; r--;
		Node res = merge(query(0, l - 1), query(r + 1, n - 1));
		cout << res() << endl; // operator overload is fun
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}
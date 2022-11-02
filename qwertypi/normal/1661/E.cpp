#include <bits/stdc++.h>
// Uncertainty principle.
// If you are persistent enough, you can build a segtree.
using namespace std;
// why always ka long long ...
// WTF is TLE????
// lmao Wrong every TC 2... 
// Hi segtree
// Long time no see!
// Woosh
int n;
 
bool c[3][500001];

struct Query{
	int l, r;
	bool operator< (const Query& o) const{
		return l < o.l || l == o.l && r < o.r;
	}
};

// vibe of T192
struct Node{
	int ans = 0;
	bool l[3] = {0}, r[3] = {0}, cl = 0, cr = 0, clr[3][3] = {{0}};
	Node(){};
	Node(int id){
		if(id == -1){
			ans = -1;
			return;
		}
		if(c[0][id] && c[2][id] && !c[1][id]) ans = 2;
		else if(!c[0][id] && !c[1][id] && !c[2][id]) ans = 0;
		else ans = 1;
		for(int i = 0; i < 3; i++){
			l[i] = r[i] = c[i][id];
		}
		cl = cr = false;
		for(int i = 0; i < 3; i++){
			if(c[i][id]) clr[i][i] = true;
		}
		if(c[0][id] && c[1][id]) clr[0][1] = clr[1][0] = true;
		if(c[1][id] && c[2][id]) clr[1][2] = clr[2][1] = true;
		if(c[0][id] && c[1][id] && c[2][id]) cl = cr = true, clr[0][2] = clr[2][0] = true;
	}
	
	friend Node operator+ (const Node& a, const Node& b){
		if(a.ans == -1 || b.ans == -1) return (a.ans == -1 ? b : a);
		Node res;
		res.ans = a.ans + b.ans;
		for(int i = 0; i < 3; i++){
			res.l[i] = a.l[i];
			res.r[i] = b.r[i];
			res.cl |= a.cl;
			res.cr |= b.cr;
		}
		bool eq[3];
		for(int i = 0; i < 3; i++){
			eq[i] = a.r[i] && b.l[i];
		}
		if(eq[0] && eq[2] && !(a.cr && b.cl)) res.ans -= 2;
		else if(eq[0] || eq[1] || eq[2]) res.ans--;
		
		res.cl |= a.clr[0][0] && b.cl && a.clr[2][2];
		res.cr |= b.clr[0][0] && a.cr && b.clr[2][2];
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				for(int k = 0; k < 3; k++){
					res.clr[i][k] |= a.clr[i][j] && a.r[j] && b.l[j] && b.clr[j][k];
				}
			}
		}
		return res;
	}
};

Node T[500001 * 4];
void build(int t = 1, int tl = 0, int tr = n - 1){
	if(tl == tr){
		T[t] = Node(tl);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(t << 1, tl, tm);
	build(t << 1 | 1, tm + 1, tr);
	T[t] = T[t << 1] + T[t << 1 | 1];
}

Node query(int l, int r, int t = 1, int tl = 0, int tr = n - 1){
	if(l > r) return Node(-1);
	if(l <= tl && tr <= r){
		return T[t];
	}
	int tm = (tl + tr) >> 1;
	Node a = query(l, min(r, tm), t << 1, tl, tm);
	Node b = query(max(l, tm + 1), r, t << 1 | 1, tm + 1, tr);
	return a + b;
}

vector<Query> Q;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--){
		Q.clear();
		cin >> n;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < n; j++){
				char v; cin >> v;
				c[i][j] = v == '1';
			}
		}
		build();
		int q; cin >> q;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			l--; r--;
			Q.push_back({l, r});
			cout << query(l, r).ans << endl;
		}
		
	}
}
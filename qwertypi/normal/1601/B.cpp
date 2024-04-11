#include <bits/stdc++.h>

using namespace std;

int n;
struct Node{
	int val, idx;
};

Node merge(Node A, Node B){
	if(A.val == (1 << 30) || B.val == (1 << 30)) return (A.val == (1 << 30) ? B : A);
	return (A.val < B.val ? A : B);
}

struct Segtree{
	Node T[1200001];
	void build(int t = 1, int l = 0, int r = n){
		if(l == r){
			T[t] = {(l == 0 ? 0 : (1 << 30)), (l == 0 ? 0 : -1)};
			return;
		}
		int m = (l + r) >> 1;
		build(t << 1, l, m); build(t << 1 | 1, m + 1, r);
		T[t] = merge(T[t << 1], T[t << 1 | 1]);
	}
	void upd(int idx, int val, int t = 1, int tl = 0, int tr = n){
		// if(t == 1) cout << "U " << idx << ' ' << val << endl;
		if(tl == tr){
			T[t] = {val, idx};
			return;
		}
		int tm = (tl + tr) >> 1;
		if(idx <= tm){
			upd(idx, val, t << 1, tl, tm);
		}else{
			upd(idx, val, t << 1 | 1, tm + 1, tr);
		}
		T[t] = merge(T[t << 1], T[t << 1 | 1]);
	}
	
	Node qry(int l, int r, int t = 1, int tl = 0, int tr = n){
		// if(t == 1) cout << "Q " << l << ' ' << r << endl;
		if(l > r) return {(1 << 30), -1};
		if(l <= tl && tr <= r) return T[t];
		int tm = (tl + tr) >> 1;
		return merge(qry(l, min(tm, r), t << 1, tl, tm), qry(max(tm + 1, l), r, t << 1 | 1, tm + 1, tr));
	}
} segtree;

int A[300001], B[300001], dp[300001], tr[300001];
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> B[i];
	}
	segtree.build();
	for(int i = 1; i <= n; i++){
		int v = i + B[i];
		Node res = segtree.qry(v - A[v], v);
		dp[i] = res.val + 1;
		tr[i] = res.idx;
		segtree.upd(i, dp[i]);
	}
	int p = n;
	if(dp[p] >= (1 << 30)){
		cout << -1 << endl;
	}else{
		vector<int> ans;
		while(p != 0){
			p = tr[p];
			ans.push_back(p);
		}
		cout << ans.size() << endl;
		for(auto i : ans){
			cout << i << ' ';
		}
		cout << endl;
	}
}
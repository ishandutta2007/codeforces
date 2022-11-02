#include <bits/stdc++.h>
#pragma optimize("O2")
#define IOS cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
using namespace std;

int A[100002];
vector<int> t(400000);
map<int, vector<int>> M;

void build(int v, int l, int r){
	if(l == r){
		t[v] = A[l];
		return;
	}
	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m + 1, r);
	t[v] = __gcd(t[v * 2 + 1], t[v * 2 + 2]);
}

int get(int x, int L, int R){
	if(M.find(x) == M.end()){
		return 0;
	}
	return upper_bound(M[x].begin(), M[x].end(), R) - lower_bound(M[x].begin(), M[x].end(), L);
}

int query(int v, int tl, int tr, int l, int r){
	if(l > r){
		return 0;
	}
	if(tl == l && tr == r){
		return t[v];
	}
	int tm = (tl + tr) / 2;
	return __gcd(query(v * 2 + 1, tl, tm, l, min(r, tm)), 
	query(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
	IOS;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		M[A[i]].push_back(i);
	}
	build(0, 0, n - 1);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		int k = v2 - v1 + 1;
		cout << k - get(query(0, 0, n - 1, v1, v2), v1, v2) << endl;
	}
	return 0;
}
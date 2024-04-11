#include <bits/stdc++.h>
 
using namespace std;
#define int long long
int A[300001], B[300001], d[300001];
int n, q;
// majorization
int _max(int a, int b) {
	return (a > b ? a : b);
}
int _min(int a, int b){
	return (a < b ? a : b);
}
struct Node{
	Node(){};
	Node(int _i) : id(_i) {
		if(_i == -1) return;
		sum = d[_i];
		preMin = _min(0LL, d[_i]);
		preMax = _max(0LL, d[_i]);
	};
	int preMin = 0, preMax = 0, sum = 0, id = 0;
};
 
Node operator+ (Node a, Node b){
	if(a.id == -1 || b.id == -1) return (a.id == -1 ? b : a);
	Node res;
	res.sum = a.sum + b.sum;
	res.preMin = min(a.preMin, a.sum + b.preMin);
	res.preMax = max(a.preMax, a.sum + b.preMax);
	return res;
}
 
Node t[400001];
 
void build(int v = 0, int l = 0, int r = n - 1){
	if(l == r){
		t[v] = Node(l);
		return;
	}
	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m + 1, r);
	t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}
 
Node qry(int l, int r, int v = 0, int tl = 0, int tr = n - 1){
	if(l > r) return Node(-1);
	if(l <= tl && tr <= r){
		return t[v];
	}
	int m = (tl + tr) / 2;
	return qry(l, min(m, r), v * 2 + 1, tl, m) + qry(max(m + 1, l), r, v * 2 + 2, m + 1, tr); // lol
}
 
int32_t main(){
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		cin >> B[i];
	}
	for(int i = 0; i < n; i++){
		d[i] = B[i] - A[i];
	}
	build();
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		l--, r--;
		Node res = qry(l, r);
		if(res.preMin < 0 || res.sum != 0){
			cout << -1 << endl;
			continue;
		}
		cout << res.preMax << endl;
	}
	// n take segment tree, n \rightarrow \infty
}
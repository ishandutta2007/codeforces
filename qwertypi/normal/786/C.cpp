#include <bits/stdc++.h>

using namespace std;

int n;
int a[100013];

struct Node{
	int l, r, s;
	int ll = -1, rr = -1;
	Node(){};
	Node(int l, int r, int cont, int ll, int rr) : l(l), r(r), s(cont), ll(ll), rr(rr){};
};

Node t[100013 * 50];
int root[100013];
int tc = 0;

void dbg(Node js){
	cout << "Node (" << js.l << ", " << js.r << "): " << js.s << ' ' << js.ll << ' ' << js.rr << endl;
}

void crawl(int id){
	dbg(t[id]);
	if(t[id].ll != -1) crawl(t[id].ll);
	if(t[id].rr != -1) crawl(t[id].rr);
}

int build(int tl = 0, int tr = n){
	int id = tc++;
	if(tl == tr){
		t[id] = Node(tl, tr, 0, -1, -1);
		return id;
	}
	int tm = (tl + tr) / 2;
	int id_l = build(tl, tm);
	int id_r = build(tm + 1, tr);
	t[id] = Node(tl, tr, t[id_l].s + t[id_r].s, id_l, id_r);
	return id;
}

int upd(int id, int pos, int cont, int tl = 0, int tr = n){
	int nid = tc++;
	if(tl == tr){
		t[nid] = Node(tl, tr, cont, -1, -1);
		return nid;
	}
	int tm = (tl + tr) / 2;
	int id_l = t[id].ll, id_r = t[id].rr;
	if(pos <= tm){
		id_l = upd(t[id].ll, pos, cont, tl, tm);
	}else{
		id_r = upd(t[id].rr, pos, cont, tm + 1, tr);
	}
	t[nid] = Node(t[id].l, t[id].r, t[id_l].s + t[id_r].s, id_l, id_r);
	return nid;
}

int binary_search(int id, int k, int tl = 0, int tr = n){
	if(tl == tr){
		return tl;
	}
	int tm = (tl + tr) / 2;
	if(t[t[id].ll].s >= k + 1){
		return binary_search(t[id].ll, k, tl, tm);
	}else{
		return binary_search(t[id].rr, k - t[t[id].ll].s, tm + 1, tr);
	}
}

int nxt[100013];

vector<int> v[100013];

int ans[100013];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		v[a[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++){
		v[i].push_back(n);
		for(int j = 0; j < (int) v[i].size() - 1; j++){
			nxt[v[i][j]] = v[i][j + 1];
		}
	}
	root[n] = build();
	for(int i = n - 1; i >= 0; i--){
		root[i] = upd(root[i + 1], i, 1);
		if(nxt[i] != n){
			root[i] = upd(root[i], nxt[i], 0);
		}
	}
	for(int i = 1; i <= n; i++){
		int idx = 0, cnt = 0;
		while(idx < n){
			idx = binary_search(root[idx], i);
			cnt++;
		}
		ans[i] = cnt;
	}
	for(int i = 1; i <= n; i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
}
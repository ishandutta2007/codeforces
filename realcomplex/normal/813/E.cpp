#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<ll, ll> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;

struct Node{
	int value;
	int left_node;
	int right_node;
};

Node Tree[N * 40];
int cnt;

int build(int cl, int cr){
	int id = cnt;
	Tree[cnt ++ ] = {0, -1, -1};
	if(cl == cr)
		return id;
	int mid = (cl + cr) / 2;
	int tol = build(cl, mid);
	int tor = build(mid + 1, cr);
	Tree[id].left_node = tol;
	Tree[id].right_node = tor;
	return id;
}

int newnode(int x){
	Tree[cnt ++ ] = Tree[x];
	return cnt - 1;
}

int update(int node, int cl, int cr, int pos, int vl){
	node = newnode(node);
	if(cl == cr){
		Tree[node].value += vl;
		return node;
	}
	int mid = (cl + cr) / 2;
	if(mid >= pos){
		int to = update(Tree[node].left_node, cl, mid, pos, vl);
		Tree[node].left_node = to;
	}
	else{
		int to = update(Tree[node].right_node, mid + 1, cr, pos, vl);
		Tree[node].right_node = to;
	}
	Tree[node].value = Tree[Tree[node].left_node].value + Tree[Tree[node].right_node].value;
	return node;
}

int calc(int node, int cl, int cr, int tl, int tr){
	if(cr < tl || cl > tr)	
		return 0;
	if(cl >= tl && cr <= tr){
		return Tree[node].value;
	}
	int mid = (cl + cr) / 2;
	return calc(Tree[node].left_node, cl, mid, tl, tr) + calc(Tree[node].right_node, mid + 1, cr, tl, tr);
}

int n, k;
int cur_root = 0;
int roots[N];
vector<int> T[N];

int sz;
void do_upd(int pos, int d){
	T[d].push_back(pos);
	if(T[d].size() > k){
		sz = T[d].size();
		sz = sz - k - 1;
		cur_root = update(cur_root, 0, n - 1, T[d][sz], -1);
	}
	cur_root = update(cur_root, 0, n - 1, pos, +1);
}

int main(){
	fastIO;
	cin >> n >> k; 
	cur_root = build(0, n - 1);
	int a;
	for(int i = 0; i < n;i  ++ ){
		cin >> a;
		do_upd(i, a);
		roots[i] = cur_root;
	}
	int queries;
	cin >> queries;
	int xi, yi;
	int li, ri;
	int answ = 0;
	for(int qr = 0; qr < queries; qr ++ ){
		cin >> xi >> yi;
		li = (xi + answ) % n;
		ri = (yi + answ) % n;
		if(li > ri)
			swap(li, ri);
		answ = calc(roots[ri], 0, n - 1, li, ri);
		cout << answ << "\n";
	}
	return 0;
}
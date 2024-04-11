#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<ll, ll> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int inf = (int)2e9 + 9;
const int N = (int)5e5 + 1;

struct Node{
	int number;
	int las_idx;
	int left_node;
	int right_node;
};

// set to {0, inf, -1, -1} if there is no value
Node Tree[N * 40 + 3];
int cnt = 0;

int newnode(int x){
	if(x == -1)
		Tree[cnt ++ ] = {0, inf, -1, -1};
	else
		Tree[cnt ++ ] = Tree[x];
	return cnt - 1;
}

int pos, vl, las_id;

int update(int node, int cl, int cr){
	if(cr < pos)
		return -1;
	if(cl > pos)
		return -1;
	node = newnode(node);
	if(cl == cr){
		Tree[node].number = vl;
		Tree[node].las_idx = las_id;
		return node;
	}
	int nx;
	if(pos <= (cl + cr) / 2){
		nx = update(Tree[node].left_node, cl, (cl + cr) / 2);
		Tree[node].left_node = nx;
	}
	else{
		nx = update(Tree[node].right_node, 1 + (cl + cr) / 2, cr);
		Tree[node].right_node = nx;
	}
	if(Tree[Tree[node].left_node].las_idx <= Tree[Tree[node].right_node].las_idx){
		Tree[node].las_idx = Tree[Tree[node].left_node].las_idx;
		Tree[node].number = Tree[Tree[node].left_node].number;
	}
	else{
		Tree[node].las_idx = Tree[Tree[node].right_node].las_idx;
		Tree[node].number = Tree[Tree[node].right_node].number;
	}
	return node;
}

int tl, tr;

pii Query(int node, int cl, int cr, int tl, int tr){
	if(cr < tl)
		return mp(inf, 0);
	if(cl > tr)
		return mp(inf, 0);
	if(cl >= tl && cr <= tr){
		if(Tree[node].las_idx >= tl)
			return mp(inf, 0);
		return mp(Tree[node].las_idx, Tree[node].number);
	}
	int mid = (cl + cr) / 2;
	return min(Query(Tree[node].left_node, cl, mid, tl, tr), Query(Tree[node].right_node, mid + 1, cr, tl, tr));
}

int n;
int las_pos[N];
int roots[N];

int cur_root = -1;

void do_upd(int x, int ps){
	if(las_pos[x] != -1){
		pos = las_pos[x];
		vl = 0;
		las_id = inf;
		
		cur_root = update(cur_root, 0, n - 1);
	}
	pos = ps;
	vl = x;
	las_id = las_pos[x];
	
	cur_root = update(cur_root, 0, n - 1);
	las_pos[x] = ps;
}

int main(){
	fastIO;
	for(int i = 0 ; i < N; i ++ ){
		las_pos[i] = -1;
	}
	cin >> n;
	int a;
	for(int i = 0 ; i <n; i++ ){
		cin >> a;
		do_upd(a, i);
		roots[i] = cur_root;
	}
	int qr;
	cin >> qr;
	int cl, cr;
	for(int i = 0 ; i < qr; i ++ ){
		cin >> cl >> cr;
		-- cl, -- cr;
		cout << Query(roots[cr], 0, n - 1, cl, cr).se << "\n";
	}
	return 0;
}
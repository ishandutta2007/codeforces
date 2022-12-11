#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAX = (int)1e6 + 9;
const int TREE_SIZE = (int)1e6 * 8;

struct Node{
	int left_node;
	int right_node;
	int value;
};

Node Tree[TREE_SIZE];
int cnt = 1;

vector<int> seg[MAX];

int new_node(int t){
	if(t == -1){
		cnt ++ ;
		return cnt;
	}
	Tree[++ cnt] = Tree[t];
	return cnt;
}


int update(int node, int cl, int cr, int pos){
	int id = new_node(node);
	Tree[id].value ++ ; 
	if(cl == cr){
		return id;
	}
	int mid = (cl + cr)/2;
	if(mid >= pos){
		int nw = update(Tree[id].left_node, cl, mid, pos);
		Tree[id].left_node = nw;
	}
	else{
		int nw = update(Tree[id].right_node, mid + 1, cr, pos);
		Tree[id].right_node = nw;
	}
	return id;
}

int query(int node, int cl, int cr, int tl, int tr){
	if(node == -1)
		return 0;
	if(cr < tl || cl > tr)
		return 0;
	if(cl >= tl && cr <= tr){
		return Tree[node].value;
	}
	int mid = (cl + cr) / 2;
	return query(Tree[node].left_node, cl, mid, tl, tr) + 
	query(Tree[node].right_node, mid + 1, cr, tl, tr);
}

int root[MAX];

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	int li, ri;
	for(int i = 0 ; i < n;i  ++ ){
		cin >> li >> ri;
		seg[li].push_back(ri);
	}
	for(int i = 0 ; i < TREE_SIZE; i ++ )
		Tree[i].left_node = -1, Tree[i].right_node = -1, Tree[i].value = 0;
	root[0] = 1;
	for(int j = 1; j < MAX; j ++ ){
		root[j] = root[j - 1];
		for(auto x : seg[j])
			root[j] = update(root[j], 0, MAX - 1, x);
	}
	int k;
	int a;
	int answ = 0;
	int til, tir;
	for(int i = 0; i  < m ; i ++ ){
		cin >> k;
		vector<int> r;
		for(int j = 0 ; j < k ; j ++ ){
			cin >> a;
			r.push_back(a);
		}
		r.push_back(MAX - 1);
		answ = 0;
		for(int j = 0 ; j < k ; j ++ ){
			til = r[j];
			tir = r[j + 1] - 1;
			answ += query(root[til], 0, MAX - 1, til, tir);
		}
		cout << answ << "\n";
	}
	return 0;
}
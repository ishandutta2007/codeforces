#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<ll,ll> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Node{
	int values;
	int pref1;
	int suf1;
	int max_v;
	int left_node;
	int right_node;
};

const int N = (int)1e5 + 9;
int root[N];

vector<Node> Tree;

Node merge(Node A, Node B){
	Node ret;
	ret.values = A.values + B.values;
	ret.max_v = max({A.max_v, B.max_v, A.suf1 + B.pref1});
	ret.pref1 = A.pref1 + (A.pref1 == A.values) * B.pref1;
	ret.suf1 = B.suf1 + (B.suf1 == B.values) * A.suf1;
	return ret;
}

int build(int tl, int tr){
	int id = Tree.size();
	Tree.push_back({tr - tl + 1, 0, 0, 0, -1, -1});
	if(tl == tr){
		return id;
	}
	int md = (tl + tr) / 2;
	int lnode = build(tl, md);
	int rnode = build(md + 1, tr);
	Tree[id].left_node = lnode;
	Tree[id].right_node = rnode;
	return id;
}

int new_node(int x){
	int id = Tree.size();
	Tree.push_back(Tree[x]);
	return id;
}

int update(int node, int cl, int cr, int target){
	if(cr < target)
		return -1;
	if(cl > target)
		return -1;
	int id = new_node(node);
	if(cl == cr){
		Tree[id] = {1, 1, 1, 1, -1, -1};
		return id;
	}
	int md = (cl + cr) / 2;
	int leftb = update(Tree[id].left_node, cl, md, target);
	int rightb = update(Tree[id].right_node, md + 1, cr, target);
	if(leftb == -1) leftb = Tree[id].left_node;
	if(rightb == -1) rightb = Tree[id].right_node;
	Tree[id] = merge(Tree[leftb], Tree[rightb]);
	Tree[id].left_node = leftb;
	Tree[id].right_node = rightb;
	return id;
}

Node query(int node, int cl, int cr, int tl, int tr){
	if(cr < tl)	
		return {0,0,0,0,0,0};
	if(cl > tr)
		return {0,0,0,0,0,0};
	if(cl >= tl && cr <= tr){
		return Tree[node];
	}
	int md = (cl + cr) / 2;
	Node answ = merge(query(Tree[node].left_node, cl, md, tl, tr),
				query(Tree[node].right_node, md + 1, cr, tl, tr));
	return answ;
}

int main(){
	fastIO;
	int n;
	cin >> n;
	root[n] = build(0, n - 1);
	vector<int> ha, hb;
	vector<int> ff[n];
	int h;
	for(int i = 0 ;i < n; i ++ ){
		cin >> h;
		ha.push_back(h);
		hb.push_back(h);
	}
	sort(ha.begin(), ha.end());
	for(int i = 0 ; i < n; i ++ ){
		hb[i] = lower_bound(ha.begin(), ha.end(), hb[i]) - ha.begin();
		ff[hb[i]].push_back(i);
	}
	for(int i = n - 1; i >= 0 ; i -- ){
		root[i] = root[i + 1];
		for(auto p : ff[i])
			root[i] = update(root[i], 0, n - 1, p);
	}
	int q;
	cin >> q;
	int vl, vr, wd;
	int cl, cr, md;
	for(int i = 0 ; i < q; i ++ ){
		cin >> vl >> vr >> wd;
		-- vl;
		-- vr;
		cl = 0;
		cr = n;
		while(cr - cl > 1){
			md = (cl + cr) / 2;
			if(query(root[md], 0, n - 1, vl, vr).max_v < wd)
				cr = md;
			else
				cl = md;
		}
		cout << ha[cl] << "\n";
		
	}
	return 0;
}
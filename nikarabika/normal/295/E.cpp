//sobskdrbhvk
//man am A _____ & a pair of Izzz wayTn' 230u :)
//segment pointeri mizanam ghorbatan elallah :D
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 1e5 + 85 - 69;
const LL MIN = -1200000000, MAX = +1200000000;
LL pos[maxn];
int n, q;

struct node{
	int l, r;
	LL cnt, left_dist, right_dist, dist;
	node *chL, *chR;
	node(int l = MIN, int r = MAX) :l(l), r(r){
		chL = chR = nullptr;
		cnt = left_dist = right_dist = dist = 0;
		return;
	}
};

struct segment_tree{
	node* root;
	segment_tree(node *ROOT){
		root = ROOT;
		return;
	}
	node merge(node &left, node &right){
		node ret(left.l, right.r);
		ret.chL = &left;
		ret.chR = &right;
		ret.cnt = left.cnt + right.cnt;
		ret.left_dist = left.left_dist + right.left_dist + (left.r - left.l) * right.cnt;
		ret.right_dist = right.right_dist + left.right_dist + (right.r - right.l) * left.cnt;
		ret.dist = left.dist + right.dist + left.right_dist * right.cnt + right.left_dist * left.cnt;
		return ret;
	}
	void add(LL pos, LL val, node &cur){
		if(cur.r - cur.l == 1){
			cur.cnt += val;
			cur.right_dist += val;
			return;
		}

		LL mid = (cur.l + cur.r) / 2;
		
		if(cur.chL == nullptr)
			cur.chL = new node(cur.l, mid);
		if(cur.chR == nullptr)
			cur.chR = new node(mid, cur.r);
		
		if(pos < mid)
			add(pos, val, *cur.chL);
		else
			add(pos, val, *cur.chR);
		cur = merge(*cur.chL, *cur.chR);
		return;
	}
	node get(LL st, LL en, node& cur){
		if(st <= cur.l and cur.r <= en)
			return cur;

		LL mid = (cur.l + cur.r) / 2;
		
		if(st < mid and cur.chL == nullptr)
			cur.chL = new node(cur.l, mid);
		if(en > mid and cur.chR == nullptr)
			cur.chR = new node(mid, cur.r);
		
		if(en <= mid)
			return get(st, en, *cur.chL);
		if(st >= mid)
			return get(st, en, *cur.chR);
		node node1, node2;
		return merge((node1 = get(st, en, *cur.chL)),
				(node2 = get(st, en, *cur.chR)));
	}
} seg(new node());

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> pos[i];
		seg.add(pos[i], +1, *seg.root);
	}
	cin >> q;
	while(q--){
		int ty;
		cin >> ty;
		if(ty == 1){
			int fi, se;
			cin >> fi >> se;
			fi--;
			seg.add(pos[fi], -1, *seg.root);
			pos[fi] += se;
			seg.add(pos[fi], +1, *seg.root);
		}
		else{
			LL fi, se;
			cin >> fi >> se;
			cout << seg.get(fi, se + 1, *seg.root).dist << '\n';
		}
	}
	return 0;
}
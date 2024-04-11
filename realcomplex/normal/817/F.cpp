#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

const int N = (int)1e6 + 912;

vector<ll> p;
vector<pii>segm;
struct Node{
	ll value;
	int lazy;
};

Node Tree[N * 4];

void build(int node, int tl, int  tr){
	Tree[node].value = segm[tr].se - segm[tl].fi + 1;
	Tree[node].lazy = -1;
	if(tl == tr)
		return;
	int md = (tl + tr)/2;
	build(node * 2, tl, md);
	build(node * 2 + 1, md + 1, tr);
}

void uplazy(int node, int lz){
	if(Tree[node].lazy == -1){
		Tree[node].lazy = lz;
		return;
	}
	if(lz == 2){
		if(Tree[node].lazy == 0)
			Tree[node].lazy = 1;
		else if(Tree[node].lazy == 1)
			Tree[node].lazy = 0;
		else 
			Tree[node].lazy = -1;
	}
	else{
		Tree[node].lazy = lz;
	}
	
}

void clc(int node, int tl, int tr){
	if(Tree[node].lazy == -1)
		return;
	if(Tree[node].lazy == 0){
		Tree[node].value = segm[tr].se - segm[tl].fi + 1;
	}
	if(Tree[node].lazy == 1){
		Tree[node].value = 0;
	}
	if(Tree[node].lazy == 2){
		Tree[node].value = (segm[tr].se - segm[tl].fi  + 1) - Tree[node].value;
	}
}

void push(int node, int cl, int cr){
	if(Tree[node].lazy == -1)
		return;
	clc(node, cl, cr);
	if(cl != cr){
		uplazy(node * 2, Tree[node].lazy);
		uplazy(node * 2 + 1, Tree[node].lazy);
	}
	Tree[node].lazy = -1;
	
}

void update(int node, int cl, int cr, int tl, int tr, int tt){
	push(node, cl, cr);
	if(cr < tl)	
		return;
	if(cl > tr)
		return;
	if(cl >= tl and cr <= tr){
		Tree[node].lazy = tt;
		push(node, cl, cr);
		return;
	}
	int md  = (cl + cr)/2;
	update(node * 2, cl, md, tl, tr, tt);
	update(node * 2 + 1, md + 1, cr, tl, tr, tt);
	Tree[node].value = Tree[node * 2].value + Tree[node * 2 + 1].value;
}

ll ask(int node, int cl, int cr, int tl, int tr){
	push(node, cl, cr);
	if(cr < tl)	
		return 0ll;
	if(cl > tr)
		return 0ll;
	if(cl  >= tl and cr <= tr){
		return Tree[node].value;
	}
	int md = (cl + cr)/2;
	return ask(node * 2, cl,  md, tl, tr) + ask(node * 2 + 1, md + 1, cr, tl, tr);
}

int main(){
	fastIO;
	int q;
	cin >> q;
	int t[q];
	ll lf[q];
	ll rf[q];
	for(int i = 0 ;i < q; i ++ ){
		cin >> t[i] >> lf[i] >> rf[i];
		p.push_back(lf[i]);
		p.push_back(rf[i]);
	}
	p.push_back(1);
	sort(p.begin(), p.end());
	p.resize(unique(p.begin(), p.end()) - p.begin());
	for(int i = 0 ; i < p.size(); i ++ ){
		segm.push_back(mp(p[i], p[i]));
		if(i + 1 < p.size()){
			if(p[i] + 1 <= p[i + 1] - 1){
				segm.push_back(mp(p[i] + 1, p[i + 1] - 1));
			}
		}
	}
	int sz = segm.size();
	build(1, 0, sz - 1);
	int cl, cr;
	for(int ti = 0; ti < q; ti  ++ ){
		if(t[ti] == 2)
			t[ti] = 0;
		else if(t[ti] == 1)
			t[ti] = 1;
		else
			t[ti] = 2;
		lf[ti] = lower_bound(segm.begin(), segm.end(), mp(lf[ti], -1ll)) - segm.begin();
		rf[ti] = lower_bound(segm.begin(), segm.end(), mp(rf[ti], -1ll)) - segm.begin();
		update(1, 0, sz - 1, lf[ti], rf[ti], t[ti]);
		if(ask(1, 0, sz - 1, 0, 0) > 0){
			cout << 1 << "\n";
		}
		else{
			cl = 0;
			for(int lg = 20; lg >= 0 ; lg -- ){
				if(cl + (1 << lg) < sz){
					if(ask(1, 0, sz - 1, 0, cl + (1 << lg)) == 0)
						cl += (1 << lg);
				}
			}
			cout << segm[cl].se + 1 << "\n";
		}
	}
	return 0;
}
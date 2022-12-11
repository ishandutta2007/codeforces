#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

const int N = (int)1e5 + 9;
const int M = (int)5e5 + 9;
const int LG = 18;

struct Node{
	int value;
	int lazy;
};

Node Tree[M * 4];
int dr[M];
int nn;

void build(int node, int cl, int cr){
	Tree[node].lazy = -1;
	if(cl == cr){
		Tree[node].value = dr[cl];
		return;
	}
	int md = (cl + cr)/2;
	build(node * 2, cl, md);
	build(node * 2 + 1, md + 1, cr);
	Tree[node].value = min(Tree[node * 2].value, Tree[node * 2 + 1].value);
}

void push(int node, int cl, int cr){
	if(Tree[node].lazy == -1)
		return;
	Tree[node].value = Tree[node].lazy;
	if(cl != cr){
		Tree[node * 2].lazy = Tree[node].lazy;
		Tree[node * 2 + 1].lazy = Tree[node].lazy;
	}
	Tree[node].lazy = -1;
}

void update(int node, int cl, int cr, int tl, int tr, int st){
	push(node, cl, cr);
	if(cr < tl)
		return;
	if(cl > tr)	
		return;
	if(cl >= tl and cr <= tr){
		Tree[node].lazy = st;
		push(node, cl, cr);
		return;
	}
	int md = (cl + cr)/2;
	update(node * 2, cl, md, tl, tr, st);
	update(node * 2 + 1, md + 1, cr, tl, tr, st);
	Tree[node].value = min(Tree[node * 2].value, Tree[node * 2 + 1].value);
}

int ask(int node, int cl, int cr, int tl, int tr){
	push(node, cl, cr);
	if(cr < tl)
		return (int)1e9 + 9;
	if(cl > tr)
		return (int)1e9 + 9;
	if(cl >= tl and cr <= tr){
		return Tree[node].value;
	}
	int md = (cl + cr)/2;
	return min(ask(node * 2, cl, md, tl, tr), ask(node * 2 + 1, md + 1, cr, tl, tr));
}

int tb[N][LG];
int lg[N];

int sz;
int bt; 
int qry(int l, int r){
	sz = r - l + 1;
	bt = lg[sz];
	return min(tb[l][bt], tb[r - (1 << bt) + 1][bt]);
}

int main(){
	fastIO;
	int n, k;
	cin >> n >> k;
	int z = (int)1e9 + 9;
	for(int i = 0 ; i < n; i ++ ){
		cin >> tb[i][0];
		z = min(z, tb[i][0]);
	}
	for(int j = 1; j < LG; j ++ ){
		for(int x = 0; x <= n - (1 << j); x ++ ){
			tb[x][j] = min(tb[x][j - 1], tb[(x + (1 << (j - 1)))][j - 1]);
		}
	}
	int p = 0;
	for(int i = 1 ; i <= n; i ++ ){
		while((1 << (p + 1)) <= i){
			p ++ ;
		} 
		lg[i] = p;
	}
	int q;
	cin >> q;
	vector<int> ip;
	int ty[q];
	int li[q];
	int ri[q];
	int ad[q];
	for(int i = 0 ; i < q; i ++ ){
		cin >> ty[i] >> li[i] >> ri[i];
		-- li[i];
		-- ri[i];
		if(ty[i] == 1)
			cin >> ad[i];
		ip.push_back(li[i]);
		ip.push_back(ri[i]);
	}
	sort(ip.begin(), ip.end());
	ip.resize(unique(ip.begin(), ip.end()) - ip.begin());
	vector<pii> segm;
	for(int i = 0 ; i < ip.size(); i ++ ){
		segm.push_back(mp(ip[i], ip[i]));
		if(i + 1 < ip.size()){
			if(ip[i] + 1 <= ip[i + 1] - 1){
				segm.push_back(mp(ip[i] + 1, ip[i + 1] - 1));
			}
		}
	}
	int c = 0;
	int dx, dy;
	for(auto it : segm){
		dx = it.fi / n;
		dy = it.se / n;
		if(dx == dy){
			dr[c] = qry(it.fi % n, it.se % n);
		}
		else if(dy == dx + 1){
			dr[c] = min(qry(it.fi % n, n - 1), qry(0, it.se % n));
		}
		else{
			dr[c] = z;
		}
		++ c;
	}
	nn = segm.size();
	build(1, 0, nn - 1);
	for(int i = 0 ; i < q; i ++ ){
		dx = li[i];
		dy = ri[i];
		dx = lower_bound(segm.begin(), segm.end(), mp(dx, -1)) - segm.begin();
		dy = lower_bound(segm.begin(), segm.end(), mp(dy, -1)) - segm.begin();
		if(ty[i] == 1)
			update(1, 0, nn - 1, dx, dy, ad[i]);
		else
			cout << ask(1, 0, nn - 1, dx, dy) << "\n";
	}
	return 0;
}
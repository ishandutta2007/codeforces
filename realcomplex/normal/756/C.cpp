#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)1e5 + 9;

struct Node{
	int val;
	int lazy;
};

Node Tree[N * 4];

void push(int node, int cl, int cr){
	Tree[node].val += Tree[node].lazy;
	if(cl != cr){
		Tree[node * 2].lazy += Tree[node].lazy;
		Tree[node * 2 + 1].lazy += Tree[node].lazy;
	}
	Tree[node].lazy = 0;
}

void update(int node, int cl, int cr, int tl, int tr, int vl){
	
	push(node, cl, cr);
	if(cr < tl){
		return;
	}
	if(cl > tr){
		return;
	}
	if(cl >= tl and cr <= tr){
		Tree[node].lazy = vl;
		push(node, cl, cr);
		return;
	}
	int md = (cl + cr)/2;
	update(node * 2, cl, md, tl, tr, vl);
	update(node * 2 + 1, md + 1, cr, tl, tr, vl);
	Tree[node].val = max(Tree[node * 2].val, Tree[node * 2 + 1].val);
}

int ask(int node ,int cl, int cr, int tl, int tr){
	push(node, cl, cr);
	if(cr < tl)
		return -(int)1e9;
	if(cl > tr)
		return -(int)1e9;
	if(cl >= tl and cr <= tr){
		return Tree[node].val;
	}
	int md = (cl + cr)/2;
	return max(ask(node * 2, cl, md, tl, tr), ask(node * 2 + 1, md + 1, cr, tl, tr));
}

int opr[N];
int q;


int main(){
	fastIO;
	for(int i = 0 ; i < N * 4; i ++ )
		Tree[i].val = 0, Tree[i].lazy = 0;
	cin >> q;
	int p;
	int t;
	int z;
	for(int i= 0 ; i < q ; i ++ ){
		cin >> p >> t;
		-- p;
		if(t == 1){
			cin >> z;
			opr[p] = z;
			update(1, 0, q - 1, 0, p, 1);
		}	
		else{
			update(1, 0, q - 1, 0, p, -1);
		}
		int d = q;
		for(int bit = 20; bit >= 0 ; bit -- ){
			if(d - (1 << bit) >= 0){
				if(ask(1, 0, q - 1, d - (1 << bit), q - 1) <= 0){
					d -= (1 << bit);
				}
			}
		}
		d --;
		if(d < 0)
			cout << -1 << "\n";
		else
			cout << opr[d] << "\n"; 
	
	}
	return 0;
	
}
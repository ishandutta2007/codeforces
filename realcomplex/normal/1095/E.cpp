#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 9;

struct Node{
	int val;
	int lazy;
};

int value[N];

struct Tree{
	Node T[N * 4];
	int nsz;
	void build(int node, int cl, int cr){
		T[node].lazy = 0;
		if(cl == cr){
			T[node].val = value[cl];
			return;
		}
		int md = (cl + cr) / 2;
		build(node * 2, cl, md);
		build(node * 2 + 1, md + 1, cr);
		T[node].val = min(T[node * 2].val, T[node * 2 + 1].val);
	}
	void push(int node, int cl, int cr){
		T[node].val += T[node].lazy;
		if(cl != cr){
			T[node * 2].lazy += T[node].lazy;
			T[node * 2 + 1].lazy += T[node].lazy;
		}
		T[node].lazy = 0;
	}
	
	void update(int node, int cl, int cr, int tl, int tr, int x){
		push(node, cl, cr);
		if(cr < tl)	
			return;
		if(cl > tr)
			return;
		if(cl >= tl && cr <= tr){
			T[node].lazy = x;
			push(node, cl, cr);
			return;
		}
		int md = (cl + cr) / 2;
		update(node * 2, cl , md, tl , tr, x);
		update(node * 2 + 1, md + 1, cr, tl, tr, x);
		T[node].val = min(T[node * 2].val, T[node * 2 + 1].val);
	}
	
	int ask(int node, int cl, int cr, int tl, int tr){
		push(node, cl, cr);
		if(cr < tl)
			return (int)1e9 + 9;
		if(cl > tr)
			return (int)1e9 + 9;
		if(cl >= tl && cr <= tr){
			return T[node].val;
		}
		int md = (cl + cr) / 2;
		return min(ask(node * 2, cl, md, tl, tr), ask(node * 2 + 1, md + 1, cr, tl, tr));
	}
	
	void Init(int nn){
		nsz = nn;
		build(1, 0, nn - 1);
	}
	void call_update(int tl, int tr, int x){
		update(1, 0, nsz - 1, tl, tr, x);
	}
};

Tree balance;

int main(){
	fastIO;
	int n;
	cin >> n;
	string t;
	cin >> t;
	int bal = 0;
	int p;
	for(int i = 0 ; i < n; i ++ ){
		if(t[i] == '(')
			bal ++ ;
		else
			bal -- ;
		value[i] = bal;
	}
	balance.Init(n);
	int cur, rev;
	int answ = 0;
	for(int i = 0 ; i < n; i ++ ){
		if(t[i] == '(')
			cur = 1;
		else
			cur = -1;
		rev = -cur;
		balance.call_update(i, n - 1, 2 * rev);
		if(balance.ask(1, 0, n - 1, 0, n - 1) == 0 && balance.ask(1, 0, n - 1, n - 1, n - 1) == 0){
			answ ++ ;
		}
		balance.call_update(i, n - 1, 2 * cur);
	}
	cout << answ;

	return 0;
}
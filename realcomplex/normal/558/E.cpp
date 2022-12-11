#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int AL = 26;

struct Node{
	int cnt[AL];
	int lazy; // -1 if no operation; 1 if non-decreasing; 0 if non-increasing
};

struct Tree{
	Node T[N * 4 + 512];
	int nn;
	vector<int> st;
	
	void build(int node, int cl, int cr){
		T[node].lazy = -1;
		if(cl == cr){
			for(int j = 0 ; j < AL; j ++ )
				T[node].cnt[j] = 0;
			T[node].cnt[st[cl]] ++ ;
			return;
		}
		int mid = (cl + cr) / 2;
		build(node * 2, cl, mid);
		build(node * 2 + 1, mid + 1, cr);
		for(int j = 0 ; j < AL; j ++ ){
			T[node].cnt[j] = T[node * 2].cnt[j] + T[node * 2 + 1].cnt[j];
		}
	}
	
	void push(int node, int cl, int cr){
		if(cl != cr && T[node].lazy != -1){
			if(T[node].lazy == 1){
				int mid = (cl + cr) / 2;
				int sz = mid - cl + 1;
				int mz;
				for(int j = 0 ;j < AL; j ++ ){
					mz = min(sz, T[node].cnt[j]);
					sz -= mz;
					T[node * 2].cnt[j] = mz;
				}
				mid ++ ;
				sz = cr - mid + 1;
				for(int j = AL - 1; j >= 0 ; j -- ){
					mz = min(sz, T[node].cnt[j]);
					sz -= mz;
					T[node * 2 + 1].cnt[j] = mz;
				}
			}
			else{
				int mid = (cl + cr) / 2;
				int sz = mid - cl + 1;
				int mz;
				for(int j = AL - 1 ; j >= 0; j -- ){
					mz = min(sz, T[node].cnt[j]);
					sz -= mz;
					T[node * 2].cnt[j] = mz;
				}
				mid ++ ;
				sz = cr - mid + 1;
				for(int j = 0 ; j < AL; j ++ ){
					mz = min(sz, T[node].cnt[j]);
					sz -= mz;
					T[node * 2 + 1].cnt[j] = mz;
				}
			}
		
			T[node * 2].lazy = T[node].lazy;
			T[node * 2 + 1].lazy = T[node].lazy;
		}
		
		T[node].lazy = -1;
	}
	
	int iseg[AL];
	
	
	void calc(int node, int cl, int cr, int tl, int tr){
		push(node, cl, cr);
		if(cr < tl)
			return;
		if(cl > tr)
			return;
		if(cl >= tl && cr <= tr){
			for(int t = 0; t < AL; t ++  ){
				iseg[t] += T[node].cnt[t];
			}
			return;
		}
		int mid = (cl + cr) / 2;
		calc(node * 2, cl, mid, tl, tr);
		calc(node * 2 + 1, mid + 1, cr, tl, tr);
	}
	
	void sort_upd(int node, int cl, int cr, int tl, int tr, int ty){
		push(node, cl, cr);
		if(cr < tl)
			return;
		if(cl > tr)
			return;
		if(cl >= tl && cr <= tr){
			int sz = cr - cl +  1;
			int mz;
			for(int t = 0;  t < AL; t ++ )
				T[node].cnt[t] = 0;
			if(ty == 1){
				for(int t = 0;t < AL; t ++ ){
					mz = min(sz, iseg[t]);
					iseg[t] -= mz;
					sz -= mz;
					T[node].cnt[t] = mz;
				}
			}
			else{
				for(int t = AL - 1; t >= 0; t -- ){
					mz = min(sz, iseg[t]);
					iseg[t] -= mz;
					sz -= mz;
					T[node].cnt[t] = mz;
				}
			}
			T[node].lazy = ty;
			push(node, cl, cr);	
			return;
		}
		int mid = (cl + cr) / 2;
		sort_upd(node * 2, cl, mid, tl, tr, ty);
		sort_upd(node * 2 + 1, mid + 1, cr, tl, tr, ty);
		for(int t = 0 ;t < AL; t ++ ){
			T[node].cnt[t] = T[node * 2].cnt[t] + T[node * 2 + 1].cnt[t];
		}
	}
	
	int query(int node, int cl, int cr, int pos){
		push(node, cl, cr);
		if(cl == cr){
			for(int y = 0; y < AL; y ++ )
				if(T[node].cnt[y] > 0)
					return y;
		}
		int mid = (cl + cr) / 2;
		if(mid >= pos)
			return query(node * 2, cl, mid, pos);
		else
			return query(node * 2 + 1, mid + 1, cr, pos);
	}
	
	void do_sort(int l, int r, int op){
		for(int i = 0 ; i < AL; i ++ )
			iseg[i] = 0;
		calc(1, 0, nn - 1, l, r);
		sort_upd(1, 0,  nn - 1, l, r, op);
	}
	
	void Init(int n, vector<int> cl){
		st = cl;
		nn = n;
		build(1, 0,n - 1);
	}
};

Tree data;

int main(){
	fastIO;
	int n, q;
	cin >> n >> q;
	vector<int> pi;
	char c;
	for(int i = 0 ; i < n; i ++ ){
		cin >> c;
		pi.push_back(c - 'a');
	}
	data.Init(n, pi);
	int tl, tr, ki;
	for(int qr = 0; qr < q; qr ++ ){
		cin >> tl >>  tr >> ki;
		-- tl, -- tr;
		data.do_sort(tl, tr, ki);
	}
	string answ;
	for(int i = 0 ; i < n;i  ++ ){
		answ.push_back(char(data.query(1, 0, n - 1, i) + 'a'));
	}
	cout << answ << "\n";
	return 0;
}
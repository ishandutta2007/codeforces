#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Node{
	int val;
	int lzy;
};

struct Data{
	int n;
	Node T[4000000];
	
	vector<pii> segs;
	void Init(vector<pii> d){
		segs = d;
		n = segs.size();
		for(int i = 0 ; i <= n; i ++ )
			T[i].val = 0, T[i].lzy = 0;
	}
	
	void push(int node, int tl, int tr){
		T[node].val = max(T[node].val, T[node].lzy);
		if(tl != tr){
			T[node * 2].lzy = max(T[node * 2].lzy, T[node].lzy);
			T[node * 2 + 1].lzy = max(T[node * 2 + 1].lzy, T[node].lzy);
		}
		T[node].lzy = 0;
	}
	
	void update(int node, int cl, int cr, int tl, int tr, int vl){
		push(node, cl, cr);
		if(cr < tl)	
			return;
		if(cl > tr)
			return;
		if(cl >= tl && cr <= tr){
			T[node].lzy = vl;
			push(node, cl,  cr);
			return;
		}
		int md = (cl + cr)/2;
		update(node * 2, cl, md, tl, tr, vl);
		update(node * 2 + 1, md + 1, cr, tl, tr, vl);
		T[node].val = max(T[node * 2].val, T[node * 2 + 1].val);
	}
	
	int qry(int node, int cl, int cr, int tl, int tr){
		push(node, cl, cr);
		if(cr < tl)
			return 0;
		if(cl > tr)
			return 0;
		if(cl >= tl && cr <= tr){
			return T[node].val;
		}
		int md = (cl + cr)/2;
		return max(qry(node * 2, cl, md, tl, tr),
		qry(node * 2 + 1, md + 1, cr, tl, tr));
	}
	
	int ask(int l, int r){
		l = lower_bound(segs.begin(), segs.end(), mp(l, -1)) - segs.begin();
		r = lower_bound(segs.begin(), segs.end(), mp(r, -1)) - segs.begin();
		return qry(1, 0, n - 1, l, r);
	}
	
	void upd(int l, int r, int d){
		l = lower_bound(segs.begin(), segs.end(), mp(l, -1)) - segs.begin();
		r = lower_bound(segs.begin(), segs.end(), mp(r, -1)) - segs.begin();
		update(1, 0, n - 1, l, r, d);
	}
};

Data rows, cols;

int main(){
	fastIO;
	int nn, q;
	cin >> nn >> q;
	int x[q], y[q];
	char d[q];
	
	vector<int> xp, yp;
	vector<pii> xseg, yseg;
	
	xp.push_back(1);
	yp.push_back(1);
	
	for(int i = 0 ; i < q; i ++ ){
		cin >> x[i] >> y[i] >> d[i];
		xp.push_back(x[i]);
		yp.push_back(y[i]);
		if(x[i] + 1 <= nn)
			xp.push_back(x[i] + 1);
		if(y[i] + 1 <= nn)
			yp.push_back(y[i] + 1);
	}
	
	sort(xp.begin(), xp.end());
	sort(yp.begin(), yp.end());
	
	xp.resize(unique(xp.begin(), xp.end()) - xp.begin());
	yp.resize(unique(yp.begin(), yp.end()) - yp.begin());
	
	for(int i = 0 ; i < xp.size(); i ++ ){
		xseg.push_back(mp(xp[i], xp[i]));
		if(i + 1 < xp.size()){
			if(xp[i] + 1 < xp[i + 1] - 1){
				xseg.push_back(mp(xp[i] + 1, xp[i + 1] - 1));
			}
		}
	}
	
	for(int i = 0 ; i  < yp.size(); i ++ ){
		yseg.push_back(mp(yp[i], yp[i]));
		if(i + 1 < yp.size()){
			if(yp[i] + 1 < yp[i + 1] - 1){
				yseg.push_back(mp(yp[i] + 1, yp[i + 1] - 1));
			}
		}
	}
	
	rows.Init(yseg);
	cols.Init(xseg);
	set<pii> asked;
	int mx;
	for(int i = 0 ;i < q; i ++ ){
		if(asked.count(mp(x[i], y[i]))){
			cout << 0 << "\n";
			continue;
		}
		asked.insert(mp(x[i], y[i]));
		if(d[i] == 'U'){
			mx = cols.ask(x[i], x[i]);
			cout << y[i] - mx << "\n";
			mx ++ ;
			rows.upd(mx, y[i], x[i]);
		}
		else{
			mx = rows.ask(y[i], y[i]);
			cout << x[i] - mx << "\n";
			mx ++ ;
			cols.upd(mx, x[i], y[i]);
		}
	}
	return 0;
}
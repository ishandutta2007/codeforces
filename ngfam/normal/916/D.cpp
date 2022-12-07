#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int maxn = 1e9;


int cnt;

int n;
map < string, int > app;

int get(string x){
	if(app.count(x)) return app[x];
	return app[x] = ++cnt;
}

struct query{
	int t;
	int a;
	int b;

	void read(){
		string r, name;
		cin >> r;
		if(r[0] =='s'){
			t = 0;
			cin >> name >> b;
			a = get(name);
		}
		if(r[0] == 'r'){
			t = 1;
			cin >> name;
			a = get(name);
		}
		if(r[0] == 'q'){
			t = 2;
			cin >> name;
			a = get(name);
		}
		if(r[0] == 'u'){
			t = 3;
			cin >> a;
		}
	}
}a[N];

struct dynamicPSMT{
	struct Node{
		Node *L;
		Node *R;
		long long val;

		Node(Node *u = 0, Node *v = 0, long long value = 0) : L(u), R(v), val(value) {}
	};


	#define mid ((l + r) >> 1)


	Node *upd(Node *p, int l, int r, int pos, int val){
		if(!p) p = new Node();
		if(l > pos || r < pos) return p;

		Node *ret = new Node(p -> L, p -> R, p -> val);


		if(l == r) ret -> val += val;
		else{
			ret -> L = upd(ret -> L, l, mid, pos, val);
			ret -> R = upd(ret -> R, mid + 1, r, pos, val);
			ret -> val = ret -> L -> val + ret -> R -> val;
		}
		return ret;
	}

	Node *modify(Node *p, int l, int r, int pos, long long val){
		if(!p) p = new Node();
		if(l > pos || r < pos) return p;

		Node *ret = new Node(p -> L, p -> R, p -> val);

		if(l == r) ret -> val = val;
		else{
			ret -> L = modify(ret -> L, l, mid, pos, val);
			ret -> R = modify(ret -> R, mid + 1, r, pos, val);
			ret -> val = ret -> L -> val + ret -> R -> val;
		}


		return ret;
	}

	long long query(Node *p, int l, int r, int x, int y){
		if(!p) return 0;
		if(x > y || x > r || y < l) return 0;
		if(l >= x && r <= y) return p -> val;
		return query(p -> L, l, mid, x, y) + query(p -> R, mid + 1, r, x, y);
	}

	Node *at[N];
}f, g;


int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);


	cin >> n;


	for(int i = 1; i <= n; ++i){
		a[i].read();
		if(a[i].t == 0){
			int x;
			if(x = f.query(f.at[i - 1], 1, maxn, a[i].a, a[i].a)){
				g.at[i] = g.upd(g.at[i - 1], 1, maxn, x, -1);
				f.at[i] = f.modify(f.at[i - 1], 1, maxn, a[i].a, a[i].b);
				g.at[i] = g.upd(g.at[i], 1, maxn, a[i].b, 1);
			}
			else{
				g.at[i] = g.upd(g.at[i - 1], 1, maxn, a[i].b, 1);
				f.at[i] = f.modify(f.at[i - 1], 1, maxn, a[i].a, a[i].b);
			}
		}
		if(a[i].t == 1){
			int x;
			if(x = f.query(f.at[i - 1], 1, maxn, a[i].a, a[i].a)){
				g.at[i] = g.upd(g.at[i - 1], 1, maxn, x, -1);
				f.at[i] = f.modify(f.at[i - 1], 1, maxn, a[i].a, 0);
			}
		}
		if(a[i].t == 2){
			int x;
			if(x = f.query(f.at[i - 1], 1, maxn, a[i].a, a[i].a)){
				cout << g.query(g.at[i - 1], 1, maxn, 1, x - 1) << '\n';
			}
			else cout << "-1\n";
			cout << flush;
		}
		if(a[i].t == 3){
			g.at[i] = g.at[i - a[i].a - 1];
			f.at[i] = f.at[i - a[i].a - 1];
			continue;
		}

		if(!g.at[i]) g.at[i] = g.at[i - 1];
		if(!f.at[i]) f.at[i] = f.at[i - 1];
	}



	return 0;
}
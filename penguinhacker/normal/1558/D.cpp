#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	int id=-1, sz=1, pri=rng();
	Node* lc=nullptr;
	Node* rc=nullptr;
	int lz=0;
	Node(int x) { id=x; }
};
 
int sz(Node* u) {
	return u?u->sz:0;
}
 
Node* cmb(Node* u) {
	u->sz=1+sz(u->lc)+sz(u->rc);
	return u;
}
 
void prop(Node* u) {
	if (u&&u->lz) {
		u->id+=u->lz;
		if (u->lc)
			u->lc->lz+=u->lz;
		if (u->rc)
			u->rc->lz+=u->lz;
		u->lz=0;
	}
}
 
ar<Node*, 2> split(Node* u, int k) { // all values <=k on one side
	if (!u)
		return {nullptr, nullptr};
	prop(u);
	//prop(u->lc);
	//prop(u->rc);
	if (u->id>k) {
		ar<Node*, 2> cur=split(u->lc, k);
		u->lc=cur[1];
		return {cur[0], cmb(u)};
	} else {
		ar<Node*, 2> cur=split(u->rc, k);
		u->rc=cur[0];
		return {cmb(u), cur[1]};
	}
}
 
Node* mrg(Node* l, Node* r) {
	prop(l), prop(r);
	if (!l||!r)
		return l?l:r;
	if (l->pri>r->pri) {
		l->rc=mrg(l->rc, r);
		return cmb(l);
	} else {
		r->lc=mrg(l, r->lc);
		return cmb(r);
	}
}

void app(Node* u) {
	if (u) {
		++u->lz;
		prop(u);
	}
}

void dbg(Node* u) {
	if (!u)
		return;
	prop(u);
	dbg(u->lc);
	cout << u->id << " ";
	dbg(u->rc);
}

const int mxN=2e5, M=998244353;
int n, m, x[mxN], y[mxN];
ll f[2*mxN], iv[2*mxN], iF[2*mxN];

ll C(int a, int b) {
	assert(0<=b&&b<=a&&a<2*mxN);
	return f[a]*iF[b]%M*iF[a-b]%M;
}

void solve() {
	cin >> n >> m;
	int cnt=0;
	Node* rt=nullptr;
	auto Pr=[&]() {
		cout << "DEBUGGING : ";
		dbg(rt);
		cout << "\n";
	};
	for (int i=0; i<m; ++i) {
		cin >> x[i] >> y[i];
		//Pr();
		if (y[i]==1) {
			++cnt;
			app(rt);
			rt=mrg(new Node(1), rt);
			//dbg(rt);
			//cout << "LEFT SIDE" << endl;
		} else {
			//--y[i];
			ar<Node*, 2> a=split(rt, y[i]-1);
			ar<Node*, 2> b=split(a[0], y[i]-2);
			Node *lhs=b[0], *mid=b[1], *rhs=a[1];
			if (mid) {
				rhs=mrg(mid, rhs);
				app(rhs);
				rt=mrg(lhs, rhs);
			} else {
				app(rhs);
				mid=new Node(y[i]);
				++cnt;
				rt=mrg(lhs, mrg(mid, rhs));
			}
		}
		//Pr();
	}
	//Pr();
	cout << C(2*n-1-cnt, n-1-cnt) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[0]=f[1]=iF[0]=iF[1]=iv[1]=1;
	for (int i=2; i<2*mxN; ++i) {
		f[i]=f[i-1]*i%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iF[i-1]*iv[i]%M;
	}
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
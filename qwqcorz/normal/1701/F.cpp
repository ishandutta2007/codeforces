#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

int Q,d;
struct segment_tree {
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	struct node {
		ll s0,s1,s2,tag;
		node(ll x=-1) {
			if (~x) {
				s0=1,s1=x,s2=x*x;
			} else {
				s0=s1=s2=0;
			}
			tag=0;
		}
		friend node operator +(node a,node b) {
			node ret;
			ret.s0=a.s0+b.s0;
			ret.s1=a.s1+b.s1;
			ret.s2=a.s2+b.s2;
			return ret;
		}
		void add(ll x) {
			s2+=2*x*s1+x*x*s0;
			s1+=x*s0;
			tag+=x;
		}
	}t[N*4];
	void push_down(int w) {
		if (!t[w].tag) {
			return;
		}
		t[ls].add(t[w].tag);
		t[rs].add(t[w].tag);
		t[w].tag=0;
	}
	void change(int w,int l,int r,int x,ll y) {
		if (l==r) {
			t[w]=node(y);
			return;
		}
		push_down(w);
		if (x<=mid) {
			change(ls,l,mid,x,y);
		} else {
			change(rs,mid+1,r,x,y);
		}
		t[w]=t[ls]+t[rs];
	}
	ll query(int w,int l,int r,int ql,int qr) {
		if (ql<=l&&r<=qr) {
			return t[w].s0;
		}
		push_down(w);
		if (qr<=mid) {
			return query(ls,l,mid,ql,qr);
		}
		if (ql>mid) {
			return query(rs,mid+1,r,ql,qr);
		}
		return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
	}
	void add(int w,int l,int r,int ql,int qr,ll x) {
		if (ql<=l&&r<=qr) {
			t[w].add(x);
			return;
		}
		push_down(w);
		if (ql<=mid) {
			add(ls,l,mid,ql,qr,x);
		}
		if (qr>mid) {
			add(rs,mid+1,r,ql,qr,x);
		}
		t[w]=t[ls]+t[rs];
	}
	#undef mid
	#undef rs
	#undef ls
}t;
bool vis[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n=2e5+1;
	cin>>Q>>d;
	while (Q--) {
		int x;
		cin>>x;
		if (!vis[x]) {
			vis[x]=1;
			t.change(1,0,n,x,t.query(1,0,n,x-d,x-1));
			t.add(1,0,n,x+1,x+d,1);
		} else {
			vis[x]=0;
			t.change(1,0,n,x,-1);
			t.add(1,0,n,x+1,x+d,-1);
		}
		ll ans=(t.t[1].s2-t.t[1].s1)/2;
		cout<<ans<<"\n";
	}
	
	return 0;
}
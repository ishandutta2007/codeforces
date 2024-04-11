#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

template<typename T>
void ckmx(T &x,T y) {
	if (x<y) {
		x=y;
	}
}
int n,Q,X,Y;
double A,B;
struct segment_tree {
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	struct node {
		double v[3][3];
		node(int x=0) {
			for (int i=0;i<3;i++) {
				for (int j=0;j<3;j++) {
					v[i][j]=0;
				}
			}
			v[1][1]=B*x;
			v[2][2]=A*x;
		}
		friend node operator +(node a,node b) {
			node ret;
			for (int i=0;i<3;i++) {
				for (int j=0;j<3;j++) {
					for (int x=0;x<3;x++) {
						for (int y=0;x+y<3;y++) {
							ckmx(ret.v[i][j],a.v[i][x]+b.v[y][j]);
						}
					}
				}
			}
			return ret;
		}
	}t[N*4];
	void change(int w,int l,int r,int x,int y) {
		if (l==r) {
			t[w]=node(y);
			return;
		}
		if (x<=mid) {
			change(ls,l,mid,x,y);
		} else {
			change(rs,mid+1,r,x,y);
		}
		t[w]=t[ls]+t[rs];
	}
	node query(int w,int l,int r,int ql,int qr) {
		if (ql<=l&&r<=qr) {
			return t[w];
		}
		if (qr<=mid) {
			return query(ls,l,mid,ql,qr);
		}
		if (ql>mid) {
			return query(rs,mid+1,r,ql,qr);
		}
		return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
	}
	#undef mid
	#undef rs
	#undef ls
}t;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(15);
	
	cin>>n>>Q>>X>>Y;
	if (X>Y) {
		swap(X,Y);
	}
	A=1./Y,B=1./(X+Y);
	for (int i=1;i<=n;i++) {
		int x;
		cin>>x;
		t.change(1,1,n,i,x);
	}
	while (Q--) {
		int opt,x,y;
		cin>>opt>>x>>y;
		if (opt==1) {
			t.change(1,1,n,x,y);
		} else {
			auto res=t.query(1,1,n,x,y);
			double ans=0;
			for (int i=0;i<3;i++) {
				for (int j=0;j<3;j++) {
					ckmx(ans,res.v[i][j]);
				}
			}
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}
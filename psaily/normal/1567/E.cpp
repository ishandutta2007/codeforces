#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f
 
typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<long long,int> pli;
typedef double db;
// head
 
const int mod=998244353;
const int N=2e5+5;

int q,n;
int arr[N];

namespace segment_tree {
	#define lp p<<1
	#define rp p<<1|1
	
	struct node {
		int l,r;
		ll tmp;
		int ls,rs;
	}tr[N<<2];
	node operator +(const node &a,const node &b) {
		node res;
		int L=a.l,R=b.r,mid=a.r;
		res.l=L,res.r=R;
		if (arr[mid]>arr[mid+1]) {	
			res.ls=a.ls,res.rs=b.rs;
			res.tmp=a.tmp+b.tmp;
		}else {
			if (a.ls==mid-L+1) res.ls=a.ls+b.ls;
			else res.ls=a.ls;
			if (b.rs==R-mid) res.rs=b.rs+a.rs;
			else res.rs=b.rs;
			
			res.tmp=a.tmp+b.tmp+1ll*a.rs*b.ls;
		}
		return res;
	}
	void build(int p,int l,int r) {
		if (l==r) {
			tr[p].tmp=1;
			tr[p].l=tr[p].r=l;
			tr[p].ls=tr[p].rs=1;
			return;
		}
		int mid=(l+r)>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		tr[p]=tr[lp]+tr[rp];	
	}
	void update(int p,int l,int r,int x) {
		if (l==r) return;
		int mid=(l+r)>>1;
		if (x<=mid) update(p<<1,l,mid,x);
		else update(p<<1|1,mid+1,r,x);
		tr[p]=tr[lp]+tr[rp];
	}
	node query(int p,int l,int r,int ql,int qr) {
		if (l==ql&&r==qr) return tr[p];
		int mid=(l+r)>>1;
		if (qr<=mid) return query(p<<1,l,mid,ql,qr);
		else if (ql>mid) return query(p<<1|1,mid+1,r,ql,qr);
		else return query(p<<1,l,mid,ql,mid)+query(p<<1|1,mid+1,r,mid+1,qr);
	}
}
using namespace segment_tree;

int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) scanf("%d",&arr[i]);
	build(1,1,n);
	while (q--) {
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if (op==1) {
			arr[x]=y;
			update(1,1,n,x);
		}else {
			node ans=query(1,1,n,x,y);
			printf("%lld\n",ans.tmp);
		}
	}
	return 0;	
}
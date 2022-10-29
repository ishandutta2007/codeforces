#include <bits/stdc++.h>
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

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double db;
// head 

const int N=2e5+5;
int n,k;
int a[N];
int fir[N],lst[N];
int dp[N];

namespace segT {
	#define lp p<<1
	#define rp p<<1|1
	
	struct node {
		int l,r;
		int mn;
	}tr[N<<2];
	
	void up(int p) {
		tr[p].mn=min(tr[lp].mn,tr[rp].mn);
	}
	
	void build(int p,int l,int r) {
		tr[p].l=l,tr[p].r=r;
		if (l==r) {
			tr[p].mn=l; return;
		}
		int mid=(l+r)>>1;
		build(lp,l,mid);
		build(rp,mid+1,r);
		up(p);
	}
	#define L tr[p].l
	#define R tr[p].r
	int query(int p,int l,int r) {
		if (L==l&&R==r) {return tr[p].mn;}
		int mid=(L+R)>>1;
		if (r<=mid) return query(lp,l,r);
		else if (l>mid) return query(rp,l,r);
		else return min(query(lp,l,mid),query(rp,mid+1,r));
	}
	void update(int p,int pos,int x) {//one node clear
		if (L==R) {tr[p].mn=x; return;}
		int mid=(L+R)>>1;
		if (pos<=mid) update(lp,pos,x);
		else update(rp,pos,x);
		up(p);
	}
}
using namespace segT;

int vc[N];

int main() {
	cin>>n;
	rep(i,1,n+1) {
		scanf("%d",&a[i]);
		if (!fir[a[i]]) fir[a[i]]=i;
		lst[a[i]]=i;
	}
	rep(i,1,n+1) if (lst[a[i]]==i) vc[i]=fir[a[i]];
	
	build(1,1,n);
	rep(i,1,n+1) {
		dp[i]=dp[i-1]+1;
		
		if (vc[i]) {
			int l=vc[i];
			dp[i]=min(dp[i],dp[l-1]+2);
			if (l+1<=i-1) {//[l+1,i-1]
				// bug(l+1),debug(i-1);
				int opt=query(1,l+1,i-1);
				dp[i]=min(dp[i],opt+1);
				// debug(opt);
			}
		}
		update(1,i,dp[i]);
		// printf("dp[%d]=%d\n",i,dp[i]);
		// debug(vc[i]);
		// puts("------");
	}
	printf("%d\n",n-dp[n]);
	return 0;	
}
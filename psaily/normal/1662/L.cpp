#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl 
mt19937 mrand(time(0)); 

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7,inf=1<<30;
// head
const int N=4e5+5;
int n,V,x[N],t[N],dp[N];

struct node {
	ll l,r;
	int id;	
}a[N];
bool cmpid(node a,node b) {return a.id<b.id;}
bool cmpl(node a,node b) {
	if (a.l!=b.l) return a.l<b.l;
	return a.id<b.id;
}
/*
bool cmpr(node a,node b) {
	if (a.r!=b.r) return a.r<b.r;
	return a.id<b.id;
}
*/

struct bit {
	int mx[N<<1],m;
	int lowbit(int x) {return x&(-x);}
	void init() { rep(i,0,N<<1) mx[i]=-inf; }
	void update(int x,int a) { 
		for (;x<=m;x+=lowbit(x)) mx[x]=max(mx[x],a);
	}
	int query(int x) {
		int res=-inf;
		for (;x;x-=lowbit(x)) res=max(res,mx[x]);
		return res;
	}
	void clear(int x) {
		for (;x<=m;x+=lowbit(x)) mx[x]=-inf;
	}
}bit;

void cdq(int l,int r) {
	if (l==r) return;
	int mid=(l+r)>>1;
	cdq(l,mid);
	// bug(l),bug(mid),debug(r);
	// [l,mid] [mid+1,r]
	sort(a+mid+1,a+r+1,cmpl);
	int lcur=l;
	rep(i,mid+1,r+1) {
		while (lcur<=mid&&a[lcur].l<=a[i].l) {
			bit.update(a[lcur].r,dp[a[lcur].id]);
			lcur++;	
		}
		int mx=bit.query(a[i].r);
		dp[a[i].id]=max(dp[a[i].id],mx+1);	
	}
	rep(i,l,lcur) {
		bit.clear(a[i].r);	
	}
	cdq(mid+1,r);
	inplace_merge(a+l,a+mid+1,a+r+1,cmpl);
}
int main() {
	bit.init();
	scanf("%d%d",&n,&V);
	rep(i,1,n+1) scanf("%d",t+i);
	rep(i,1,n+1) scanf("%d",x+i);
	
	vector<ll> vs;
	rep(i,1,n+1) dp[i]=-inf;
	rep(i,0,n+1) {
		a[i].l=-x[i]+(ll)t[i]*V;
		a[i].r=+x[i]+(ll)t[i]*V;
		a[i].id=i;
		vs.pb(a[i].l); vs.pb(a[i].r);
	}
	make_unique(vs);
	bit.m=SZ(vs)+5;
	rep(i,0,n+1) {
		a[i].l=lower_bound(all(vs),a[i].l)-vs.begin()+1;
		a[i].r=lower_bound(all(vs),a[i].r)-vs.begin()+1;
		// bug(i),bug(a[i].l),debug(a[i].r);
	}
	// puts("!!!");
	cdq(0,n);
	printf("%d\n",*max_element(dp,dp+n+1));
	return 0;
}
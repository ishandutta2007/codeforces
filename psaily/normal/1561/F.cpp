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
const int M=2*N;

int T,n,m;
int p[N],q[N];

ll powmod(ll x,ll k) {
	ll res=1;
	for (;k;k>>=1,x=x*x%mod) if (k&1) res=res*x%mod;
	return res;
}

ll fac[M],inv[M];
void init() {
	fac[0]=inv[0]=1;
	rep(i,1,M) fac[i]=fac[i-1]*i%mod;
	rep(i,1,M) inv[i]=powmod(fac[i],mod-2);
}
ll comb(int a,int b) {
	return fac[a]*inv[a-b]%mod*inv[b]%mod;
}

int siz[N<<2];
void up(int p) {siz[p]=siz[p<<1]+siz[p<<1|1];}
void build(int p,int l,int r) {
	if (l==r) {
		siz[p]=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	up(p);
}
void update(int p,int l,int r,int x,int op) {
	if (l==r) {
		siz[p]+=op;
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) update(p<<1,l,mid,x,op);
	else update(p<<1|1,mid+1,r,x,op);
	up(p);
}
int find(int p,int l,int r,int k) {
	if (l==r) return l;
	int mid=(l+r)>>1;
	if (siz[p<<1]>=k) return find(p<<1,l,mid,k);
	else return find(p<<1|1,mid+1,r,k-siz[p<<1]);
}

set<int> ans;
int stk[N],top;

int main() {
	init();
	
	build(1,1,N-1);
	scanf("%d",&T);
	while (T--) {
		ans.clear();
		scanf("%d%d",&n,&m);
		
		rep(i,1,m+1) scanf("%d%d",&p[i],&q[i]);
		per(i,m+1,1) {
			int a=find(1,1,N-1,q[i]),b=find(1,1,N-1,q[i]+1);
			ans.insert(b);
			stk[++top]=a,update(1,1,N-1,a,-1);
		}
		
		int op=n-1-ans.size();
		printf("%lld\n",comb(n+op,n));
		// 14-426-2
		while (top) update(1,1,N-1,stk[top--],+1);
	}
	
	return 0;	
}
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
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
// head

const int mod=1e9+7;
const int N=2005*60;

int n,k;
ll a[N];
map<ll,int> id;
ll g[N];

int top,cnt;
ll stk[N];
vi e[N];

int col[N];
ll dp[N][7];

ll powmod(ll x,ll k) {
	ll res=1;
	for (;k;k>>=1,x=x*x%mod) if (k&1) res=res*x%mod;
	return res;
}
void add(ll &a,ll b) {
	(a+=b)%=mod;	
}

int gao(char *s) {
	if (s[0]=='w') return 1;
	else if (s[0]=='y') return 2;
	else if (s[0]=='g') return 3;
	else if (s[0]=='b') return 4;
	else if (s[0]=='r') return 5;
	else return 6;
}
int fan(int x) {
	if (x==1||x==2) return 3-x;
	if (x==3||x==4) return 7-x;		
	if (x==5||x==6) return 11-x;
	return 0;
}

void dfs(int u) {
	// debug(u);
	
	if (col[u]) dp[u][col[u]]=1;
	else rep(i,1,7) dp[u][i]=1;
	
	rep(i,0,SZ(e[u])) {
		int v=e[u][i];
		dfs(v);
		
		rep(j,1,7) if (dp[u][j]) {
			ll ans=0;
			rep(k,1,7) {
				if (k==j||k==fan(j)) continue;
				// if (u==1) {
				// 	bug(u),debug(v); bug(j),debug(k);
				// 	puts("");
				// }
				add(ans,dp[v][k]%mod);
			}
			dp[u][j]=ans*dp[u][j]%mod;
		}
	}
}

int main() {
	scanf("%d%d",&k,&n);
	
	rep(i,1,n+1) {
		char s[10];
		scanf("%lld%s",&a[i],s);
		
		if (!id[a[i]]) id[a[i]]=++cnt,g[cnt]=a[i];
		col[id[a[i]]]=gao(s);
		
		top=0;
		while (a[i]) {
			if (!id[a[i]]) id[a[i]]=++cnt,g[cnt]=a[i];
			stk[++top]=id[a[i]];
			a[i]/=2;
		}
		
		per(i,top+1,2) e[stk[i]].pb(stk[i-1]);
	}
	
	rep(i,1,cnt+1) {
		sort(all(e[i]));
		e[i].erase(unique(all(e[i])),e[i].end());
	}
	
	// rep(i,1,cnt+1) {
	// 	debug(i);
	// 	rep(j,0,SZ(e[i])) printf("%d ",e[i][j]);
	// 	puts("");
	// }
	
	ll tot=1;
	rep(i,1,k+1) tot*=2; tot--;
	int root=id[1];
	
	dfs(root);
	
	ll ans=0;
	rep(i,1,7) add(ans,dp[root][i]);
	// bug(tot),debug(ans);
	
	// rep(i,1,cnt+1) bug(g[i]);
	// rep(i,1,cnt+1) rep(j,1,7) printf("dp[%lld][%d]=%lld\n",g[i],j,dp[i][j]);
	
	// debug(ans);
	ans=ans*powmod(4,tot-cnt)%mod;
	
	// if (ans%10==6) ans/=2;
	printf("%lld\n",ans);
	return 0;	
}
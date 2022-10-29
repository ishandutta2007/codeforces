#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
// head

const int N=1e6+5;
const int P=1e4;

int T,n;
ll ans;
int a[N],val[N];
bool in[N],mark[N];
int stk[N],top;

void dfs(int u) {
	if (mark[u]) {
		rep(i,1,top+1) mark[stk[i]]=1;
		return;
	}
	if (in[u]) {
		int mi=inf;
		rep(i,1,top+1) mark[stk[i]]=1;
		// rep(i,1,top+1) printf("%d ",stk[i]); puts("");
		for (;;) {
			int v=stk[top--];
			mi=min(mi,val[v]);
			// debug(v);
			if (v==u) break;
		}
		ans+=mi; 
		return;
	}
	stk[++top]=u,in[u]=1;
	dfs(a[u]);	
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&val[i]); 
	rep(i,1,n+1) scanf("%d",&a[i]);
	rep(i,1,n+1) {
		top=0,dfs(i);
	}
	printf("%lld\n",ans);
	return 0;
}
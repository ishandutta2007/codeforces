#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x.begin(),x.end())
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
const int mod=998244353;
typedef long long ll;
// head

const int N=1050;
int n,m,w[N];
ll dp[2][N];
void add(ll &a,ll b) {(a+=b)%=mod;}
int lowbit(int x) {return x&(-x);}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,m+1) {
		int u,v;
		scanf("%d%d",&u,&v);
		w[u]|=(1<<v);
		w[v]|=(1<<u);
	}
	// a d1 d2 d3 d4.. b
	int cur=0;
	dp[cur][0]=1;
	rep(i,0,n) {
		rep(sta,0,1<<10) dp[1-cur][sta]=0;
		rep(sta,0,1<<10) if (dp[cur][sta]) {
			// mask represent the element to the left
			rep(h,0,10) {
				int s=w[h]&sta;
				if (s&&lowbit(s)<(1<<h)) continue;
				add(dp[1-cur][(1<<h)|s],dp[cur][sta]);
			}
		}
		cur=1-cur;
	}
	ll ans=0;
	rep(sta,0,1<<10) add(ans,dp[cur][sta]);
	printf("%lld\n",ans);
	return 0;
}
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
typedef double db;
// head

const int N=3e5+5;
int n,k;
int a[N];
pii b[N];
int dp[N],g[N];

struct Trie {
	static const int M=6e6+5;
	int ch[M][2],tot;
	pii v[M];
	
	int newnode() {
		++tot;
		ch[tot][0]=ch[tot][1]=0;
		v[tot]=mp(0,0);
		return tot;
	}
	void insert(int x,pii val) {
		int cur=0;
		per(i,30,0) {
			int d=(x>>i)&1;
			if (!ch[cur][d]) ch[cur][d]=newnode();
			cur=ch[cur][d];
			v[cur]=max(v[cur],val);
		}
	}
	pii query(int x) {
		int cur=0;
		pii ans=mp(0,0);
		per(i,30,0) {
			int d=(x>>i)&1;
			int c=(k>>i)&1;
			
			if (c==1) {
				cur=ch[cur][1-d];
			}else {
				if (ch[cur][1-d]) ans=max(ans,v[ch[cur][1-d]]);
				cur=ch[cur][d];
			}
			
			if (!cur) break;
			if (i==0&&cur) ans=max(ans,v[cur]);
		}
		return ans;
	}
}T;

int main() {
	cin>>n>>k;
	rep(i,1,n+1) scanf("%d",&b[i].fi),b[i].se=i;
	sort(b+1,b+1+n);
	rep(i,1,n+1) a[i]=b[i].fi;
	
	rep(i,1,n+1) {
		dp[i]=1;
		
		pii res=T.query(a[i]);
		// bug(res.fi),debug(res.se);
		dp[i]=res.fi+1,g[i]=res.se;
		
		T.insert(a[i],mp(dp[i],i));		
	}
	
	int mx=0;
	rep(i,1,n+1) if (dp[i]>dp[mx]) mx=i;
	
	// rep(i,1,n+1) printf("dp[%d]=%d\n",i,dp[i]);
	
	if (dp[mx]==1) puts("-1");
	else {
		printf("%d\n",dp[mx]);
		while (mx) {
			printf("%d ",b[mx].se);
			mx=g[mx];
		}
		puts("");
	}
	return 0;	
}
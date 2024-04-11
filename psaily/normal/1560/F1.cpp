#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
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
const int N=5e5+5;

int T,n,k;
ll ans;
ll pw[20];
int dig[20];
bool mark[10];

void dfs(int p,int sum,bool limit,int us) {
	if (!p) {
		ans=min(ans,(ll)sum);
		return;
	}
	// bug(p),bug(sum),bug(limit),debug(us);
	
	if (!limit) {
		if (mark[0]||us<k) {
			ans=min(ans,(ll)sum);	
		}else {
			int c=0;
			rep(i,1,10) if (mark[i]) {c=i; break;}
			per(i,p+1,1) sum+=c*pw[i];
			ans=min(ans,(ll)sum);
		}
		return ;	
	}else {
		int c;
		
		c=dig[p];
		// debug(c);
		if (mark[c]) dfs(p-1,sum+pw[p]*c,1,us);
		else if (us<k) {
			mark[c]=1;
			dfs(p-1,sum+pw[p]*c,1,us+1);
			mark[c]=0;	
		}
		
		
		if (dig[p]!=9) {
			c=dig[p]+1;
			// debug(c);
			if (mark[c]) dfs(p-1,sum+pw[p]*c,0,us);
			else if (us<k) {
				mark[c]=1;
				dfs(p-1,sum+pw[p]*c,0,us+1);
				mark[c]=0;	
			}
		}
			
		c=-1;
		rep(i,0,10) if (mark[i]&&i>dig[p]) {c=i; break;}
		// debug(c);
		if (~c) dfs(p-1,sum+pw[p]*c,0,us);
	}
}

int main() {
	pw[1]=1;
	rep(i,2,18) pw[i]=pw[i-1]*10;
	
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&k);
		dig[0]=0;
		for (int x=n;x;x/=10) dig[++dig[0]]=x%10;
			
		ans=0;
		if (k>=2) ans=pw[dig[0]+1];
		else {
			rep(i,1,dig[0]+1+1) ans+=pw[i];
		}
		
		// debug(ans);
		// per(i,dig[0]+1,1) printf("%d",dig[i]); puts("");
		
		rep(i,0,10) mark[i]=0;
		dfs(dig[0],0,1,0);
		
		printf("%lld\n",ans);
	}
	return 0;	
}
/*
1
20 1

*/
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

typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<long long,int> pli;
typedef double db;
// head

const int mod=998244353;
const int N=1e5+5;
int n,m;
int f[51][N];
ll sum[N];
int l[N],r[N];
ll g[N];// gcd=g

void add(ll &a,ll b) {a+=b; if (a>=mod) a-=mod;}

int main() {
	cin>>n>>m;
	rep(i,1,n+1) scanf("%d%d",&l[i],&r[i]);
	rep(gc,1,m+1) {
		int tot=m/gc;
		// debug(tot);
		
		rep(i,1,tot+1) f[1][i]=0,sum[i]=0;
		rep(i,(l[1]+gc-1)/gc,r[1]/gc+1) f[1][i]=1;
		rep(i,1,tot+1) sum[i]=(sum[i-1]+f[1][i])%mod;
		
		// rep(i,1,tot+1) printf("f[1][%d]=%d\n",i,f[1][i]);
		
		rep(i,2,n+1) {
			int mi=(l[i]+gc-1)/gc,mx=r[i]/gc;
			// bug(mi),debug(mx);
			if (mi>mx) {sum[tot]=0; break;}
			rep(j,mi,tot+1) {
				// f[i][j]=f[i-1][j-mi]+...f[i-1][j-mx]
				if (j<=mx) f[i][j]=sum[j-mi];
				else f[i][j]=(sum[j-mi]-sum[j-mx-1]+mod)%mod;
			}
			// rep(i,1,tot+1) printf("f[2][%d]=%d\n",i,f[2][i]);
			sum[0]=0;
			rep(j,1,tot+1) sum[j]=(sum[j-1]+f[i][j])%mod;
		}
		
		g[gc]=sum[tot];	
		// bug(gc),debug(g[gc]);
	}
	
	per(i,m+1,1) {
		for (int j=i+i;j<=m;j+=i) g[i]=(g[i]-g[j]+mod)%mod;
	}
	printf("%lld\n",g[1]);
	return 0;	
}
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

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7,inf=1<<30;
// head

const int N=2e5+5;
int n,ans[N],deg[N],pos[N];
int g[N][32],a[N];
int belong[N],mpos[N];

int main() {
	memset(mpos,127,sizeof(mpos));
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&g[i][0]),deg[g[i][0]]++;
	rep(i,1,n+1) {
		scanf("%d",&a[i]);
	}
	int cor=0;
	int mxnum=*max_element(a+1,a+1+n);
	rep(i,1,n+1) if (!deg[i]) cor++;
	// debug(cor);
	int rd=(mxnum-n)/cor;
	// debug(rd);
	rep(j,1,32) rep(i,1,n+1) g[i][j]=g[g[i][j-1]][j-1];
	rep(i,1,n+1) {
		int p=i;
		rep(j,0,32) if (rd>>j&1) p=g[p][j];
		belong[i]=p;
		mpos[p]=min(mpos[p],i);
	}
	// a[i] is minimal
	set<int> cand;
	rep(i,1,n+1) cand.insert(i);
	rep(i,1,n+1) if (mpos[i]<inf) ans[mpos[i]]=a[i],cand.erase(a[i]);
	rep(i,1,n+1) if (!ans[i]) {
		int tar=belong[i];// initial seat i (rd) -> belong[i]
		// id>=a[i]
		ans[i]=*cand.lower_bound(a[tar]);
		cand.erase(ans[i]);
	}
	rep(i,1,n+1) printf("%d%c",ans[i]," \n"[i==n]);
	
	return 0;
}
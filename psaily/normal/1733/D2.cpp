#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int mod=998244353;
const ll inf=1ll<<60;
// head
const double eps=1e-12;
const int N=5005; 
int n,x,y;
char s1[N],s2[N];
ll dp[N][N];
int cur=0;

void solve() {
	cur++;
	scanf("%d%d%d",&n,&x,&y);
	scanf("%s%s",s1+1,s2+1);

	if (cur==-1) {
		printf("%d %d %d\n",n,x,y);
		cout << s1+1 << endl;
		cout << s2+1 << endl;
		return;
	}

	rep(i,0,n+1) rep(j,0,n+1) dp[i][j]=(ll)1e18; 

	VI p;
	rep(i,1,n+1) if (s1[i]!=s2[i]) p.pb(i);
	int m=SZ(p);

	if (m&1) { puts("-1"); return; }
	if (!m) { puts("0"); return; }

	if (x>=y) {
		if (m==2&&p[0]+1==p[1]) printf("%lld\n",min((ll)x,2ll*y));
		else {
			printf("%lld\n",(ll)m/2*y);
		}
		return;
	}


	auto Min=[&](ll &a,ll b) { a=min(a,b); };

	dp[0][0]=0;
	rep(i,1,m+1) rep(j,0,m) {
		Min(dp[i][j],dp[i-1][j]);
		if (j>=1&&i>=2) Min(dp[i][j],dp[i-2][j-1]+(ll)(p[i-1]-p[i-2])*x);
	}
	

	// debug(dp[m][0]);
	// debug(m);

	ll ans=1e18;
	rep(j,0,m) {
		//debug((ll)(m-j*2)/2*y);
		Min(ans,dp[m][j]+(ll)(m-j*2)/2*y);
	}
	printf("%lld\n",ans);
}


int main() {
    int _;
    scanf("%d",&_);
    while (_--) {
    	solve();
    }
   	
	return 0;
}
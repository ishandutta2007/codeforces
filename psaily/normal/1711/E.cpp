#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
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
const int mod=998244353,inf=1<<30;
// head
const int N=2e5+5;
char str[N];
int n;
int dp[N][3][3][3][2][2][2];

void add(int &a,int b) {
	a+=b;
	if (a>mod) a-=mod;
}

int cg(int a,int aa) {
	if (a==2) return 2;
	else if (a==0) {
		if (aa==1) return 2;
		if (aa==0) return 0;
	} else if (a==1) {
		if (aa==0) return 2;
		if (aa==1) return 1;
	}
	return 0;
}

int dfs(int p,int i,int j,int k,int la,int lb,int lc) {
	int &res=dp[p][i][j][k][la][lb][lc];
	if (~res) return res;
	if (p==n+1) {
		if (!i||!j||!k) return 0;
		if (i==1||j==1||k==1) return 0;
		return 1;
	}
	res=0;
	int dig=str[p]-'0';
	int upa=la?dig:1;
	int upb=lb?dig:1;
	int upc=lc?dig:1;

	rep(aa,0,upa+1) rep(bb,0,upb+1) rep(cc,0,upc+1) {
		int ii=aa^bb,jj=aa^cc,kk=bb^cc;
		if (ii+jj+kk==0) {
			add(res,dfs(p+1,i,j,k,la&&(aa==upa),lb&&(bb==upb),lc&&(cc==upc)));
		} else if (ii+jj+kk==2) {
			int ci=cg(i,ii),cj=cg(j,jj),ck=cg(k,kk);
			if (i==0&&j==0&&k==0) {
				ci=ii,cj=jj,ck=kk;
			}
			add(res,dfs(p+1,ci,cj,ck,la&&(aa==upa),lb&&(bb==upb),lc&&(cc==upc)));
		}
	}

	//printf("dp[%d][%d][%d][%d][%d][%d][%d]=%d\n",p,i,j,k,la,lb,lc,res);

	return res;
}

void solve() {
	memset(dp,-1,sizeof(dp));
	scanf("%s",str+1);
	n=strlen(str+1);

	int ans=0;
	rep(a,0,2) rep(b,0,2) rep(c,0,2) {
		int i=a^b,j=a^c,k=b^c;
		add(ans,dfs(2,i,j,k,a,b,c));
		//debug(ans);
	}
	printf("%d\n",(ans%mod+mod)%mod);
}

int main() {
	solve();
	return 0;
}
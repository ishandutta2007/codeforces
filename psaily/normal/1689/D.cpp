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
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int mod=998244353,inf=1<<30;
// head

const int N=3e5+5;
int n,m;
char s[1005][1005];
int val[5];

void solve() {
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%s",s[i]+1);
	rep(i,1,5) val[i]=-inf;
	rep(i,1,n+1) rep(j,1,m+1) if (s[i][j]=='B') {
		val[1]=max(val[1],-i-j);
		val[2]=max(val[2],i-j);
		val[3]=max(val[3],-i+j);
		val[4]=max(val[4],i+j);
	}
	int ans=inf;
	PII pos;
	rep(i,1,n+1) rep(j,1,m+1) {
		int v=max({val[1]+i+j,val[2]-i+j,val[3]+i-j,val[4]-i-j});
		if (v<ans) ans=v,pos={i,j};
	}
	printf("%d %d\n",pos.fi,pos.se);
}
int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}	
	return 0;
}
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
typedef pair<ll,int> pli;
typedef vector<int> vi;

const int N=2e5+5;
int n,T,k;
int a[N];
pii p[N];

int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		if (n==1) {puts("1"); continue;}
		else if (n==2) {puts("2"); puts("2 1"); continue;}
		int t=0;
		p[++t]=mp(n,n-2);
		p[++t]=mp(n-1,n-1);
		rep(i,1,n-2) p[++t]=mp(n-i,n-i-2);
		printf("%d\n",(p[t].fi+p[t].se)/2);
		rep(i,1,t+1) printf("%d %d\n",p[i].fi,p[i].se);
	}
	return 0;
}
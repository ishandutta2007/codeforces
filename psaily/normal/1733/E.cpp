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

ll t;
int x,y;
ll a[130][130],b[130][130];

void solve() {
	scanf("%lld%d%d",&t,&x,&y);

	int k=x+y;
	if (t<k) { puts("NO"); return; }

	a[0][0]=t-k,b[0][0]=t-k+1;

	rep(i,0,min(120,k)+1) for (int j=0;j<120&&j+i<=k;j++) {
		if (i||j) {
			a[i][j]=0;
			b[i][j]=0;
		}

		if (i) a[i][j]+=a[i-1][j]/2;
		if (j) a[i][j]+=(a[i][j-1]+1)/2;

		if (i) b[i][j]+=b[i-1][j]/2;
		if (j) b[i][j]+=(b[i][j-1]+1)/2;		
	}

	// puts("!!!");

	if (b[x][k-x]-a[x][k-x]) puts("YES");
	else puts("NO");
}


int main() {
	int q;
    scanf("%d",&q);
    while (q--) {
    	solve();
    }

	return 0;
}
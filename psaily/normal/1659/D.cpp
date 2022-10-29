#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl 
mt19937 mrand(time(0)); 

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=998244353,inf=1<<30;
// head
const db eps=1e-7;
const int N=2e5+5;
int n,m,q;
int a[N],b[N],mark[N],rk[N];

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]),mark[i]=rk[i]=b[i]=0;
	if (!a[1]) b[1]=0,mark[1]=1; else b[1]=1;
	rep(i,1,n+1) {
		// a[i] = (i-1)b[i] + i_pos - i
		// rk[i] 
		if (rk[i-1]<i) {
			b[i]=a[i]>0?1:0;
		}else if (mark[i]==1) b[i]=0;
		else b[i]=1;
		int p=a[i]-(i-1)*b[i]+i;
		// bug(i),bug(a[i]),debug(p);
		rk[i]=p;
		mark[p]=1;
	}
	rep(i,1,n+1) printf("%d ",b[i]);
	puts("");
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();	
	}
	return 0;	
}
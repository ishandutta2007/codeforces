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
const int mod=1e9+7;
const ll inf=1ll<<60;
// head
typedef pair<ll,int> PLI;
const int N=1505;
int n,a[N][N];
struct node {
	int x,y,v;	
};
vector<node> ps;
int r[N][N],c[N][N],row[N],col[N];

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) rep(j,1,n+1) scanf("%d",&a[i][j]),ps.pb({i,j,a[i][j]});	
	sort(all(ps),[&](node a,node b) {return a.v<b.v;});
	for (auto tmp:ps) {
		int x=tmp.x,y=tmp.y;
		r[x][y]=row[x];
		c[x][y]=col[y];
		row[x]++,col[y]++;
	}	
	ll ans=0;
	rep(i,1,n+1) rep(j,1,n+1) {
		int x=i,y=j;
		ans+=(ll)r[x][y]*(n-1-c[x][y])+(ll)c[x][y]*(n-1-r[x][y]);	
	}
	ans/=2;
	printf("%lld\n",ans);
	return 0;
}
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
const int mod=998244353;
const ll inf=1ll<<60;
// head
const double eps=1e-12;
const int N=2e5+5; 
int n,k,a[N],b[N];

void solve() {
	scanf("%d%d",&n,&k);

	rep(i,0,k) b[i]=0;
	rep(i,1,n+1) scanf("%d",&a[i]),b[i%k]=max(b[i%k],a[i]); 

	ll ans=0;
	rep(i,0,k) ans+=b[i];

	printf("%lld\n",ans);
}



int main() {
    int tt;
    cin>>tt;
    while (tt--) {
    	solve();
    }
   	
	return 0;
}
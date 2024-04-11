#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
typedef vector<int> vi;

const int N=1e5+5;
const int mod=998244353;

ll n,k,m,l;

int main() {
	cin>>n>>m>>k>>l;
	if (m>n||k+l>n) puts("-1");
	else {
		l=(l+k+m-1)/m;
		ll all=m*l;
		if (all>n) puts("-1");
		else printf("%lld\n",l);
	}
	return 0;	
}
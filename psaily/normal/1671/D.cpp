#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define SZ(x) ((int)x.size())
#define pb push_back
#define all(x) x.begin(),x.end()
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef vector<int> VI;
const int inf=1<<30;

const int N=2e5+5;
int n,x,a[N];
ll ans;

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&x);
		ans=0;
		rep(i,1,n+1) {
			scanf("%d",&a[i]);
			if (i>1) ans+=abs(a[i]-a[i-1]);
		}
		int mn=*min_element(a+1,a+1+n);
		int mx=*max_element(a+1,a+1+n);
		// bug(mi),bug(mx),debug(ans);
		if (mx<x) ans+=min((x-mx)*2,x-max(a[n],a[1]));
		if (mn>1) ans+=min((mn-1)*2,min(a[n],a[1])-1);
		printf("%lld\n",ans);
	}
	return 0;	
}
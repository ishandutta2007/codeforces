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

int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&k);
		rep(i,1,n+1) scanf("%d",&a[i]);
		if (n==1) {printf("%d\n",a[1]); continue;}
		sort(a+1,a+1+n);
		ll mx=a[n]+a[n-1];
		int p=n-2;
		k--;
		while (k--&&p) mx+=a[p--];
		printf("%lld\n",mx);
	}
	return 0;
}
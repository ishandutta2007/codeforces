#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

const int N=1e5+5;
int a[N],b[N];
int T,n,m,x;

int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&x);
		rep(i,1,n+1) scanf("%d",&a[i]);
		rep(i,1,n+1) scanf("%d",&b[i]);
		bool flag=1;
		rep(i,1,n+1) {
			if (a[i]+b[n-i+1]>x) {flag=0; break;}	
			
		}
		if (flag) puts("Yes");
		else puts("No");
	}
	return 0;	
}
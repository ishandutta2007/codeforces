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
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		printf("%d\n",max(a+b,c+d));
	}
	return 0;	
}
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define SZ(x) ((int)x.size())
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define pb push_back
typedef long long ll;
typedef double db;
typedef vector<int> VI;

// head
const int N=2e5+5;
int n,m,a[N],b[N],c[N];
char str[N];

void solve() {
	scanf("%d",&n);
	scanf("%s",str+1);
	rep(i,1,n+1) a[i]=str[i]-'0';
	if (a[1]!=9) {
		b[(n+1)/2]=0;
		for (int i=1,j=n;i<j;i++,j--) {
			b[i]=9-a[i],b[j]=9-a[j];
		}
	} else {
		rep(i,0,n+1) c[i]=2;
		c[n]=1;
		per(i,n+1,1) {
			b[i]=c[i]-a[i];
			if (b[i]<0) b[i]+=10,c[i-1]--;
		}
	}
	rep(i,1,n+1) printf("%d",b[i]);
	puts("");
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();	
	}
	return 0;	
}
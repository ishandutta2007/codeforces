#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define SZ(x) ((int)x.size())
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long double db;
typedef unsigned long long ull;
// head

int n;
ll a[30];
void prep() {
	a[n=1]=1;
	while (a[n]*3<=1e9) {
		a[n+1]=a[n]*3;
		++n;
	}
}
int main() {
	prep();
	
	int _;
	for (scanf("%d",&_);_;_--) {
		int x;
		scanf("%d",&x);
		if (x>n) puts("NO");
		else {
			puts("YES");
			rep(i,1,x+1) printf("%lld%c",a[i]," \n"[i==x]);
			
				
		}
		
		
	
	}
		
	return 0;	
}